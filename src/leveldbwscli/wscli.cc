#include "wscli.h"
#include "codecinmsg.h"
#include <gflags/gflags.h>

#ifdef _WIN32
DEFINE_string(dbpath, "f:/iteasysoft/dbdata", "database path");
#else
DEFINE_string(dbpath, "/var/iteasysoft/dbdata", "database path");
#endif

wscli::wscli(boost::asio::io_service&io) :callback_(NULL){
	client_.clear_access_channels(websocketpp::log::alevel::all);
	client_.clear_error_channels(websocketpp::log::elevel::all);

	client_.init_asio(&io);

	client_.set_message_handler(bind(&wscli::on_message, this, ::_1, ::_2));
	client_.set_open_handler(bind(&wscli::on_open, this, ::_1));
	client_.set_close_handler(bind(&wscli::on_close, this, ::_1));
}

void wscli::start(const std::string& uri, SessionCallBack callback){
	// Done boilerplate initialization, now our connection code:
	callback_ = callback;
	websocketpp::lib::error_code ec;
	client::connection_ptr con = client_.get_connection(uri.c_str(), ec);
	if (ec)
	{
		boost::shared_ptr<comminternal::PkgMsg> pPkgMsgReply = codecutil::getClientMsg_InitStatus(comminternal::PkgMsg_EnMsgStatusCode_MSG_CONNECTED);
		pPkgMsgReply->set_issuc(false);
		pPkgMsgReply->set_errdevdesc(ec.message());
		callback(pPkgMsgReply);
		return;
	}
	client_.connect(con);

	leveldb::DB* db;
	leveldb::Options options;
	options.create_if_missing = true;
	leveldb::Status status = leveldb::DB::Open(options, FLAGS_dbpath, &db);
	boost::shared_ptr<leveldb::DB> pDB(db);
	msgdispatcher_.startSrv<leveldb::DB>(pDB);
}

void wscli::on_open(websocketpp::connection_hdl hdl){
	hdl_ = hdl;
	boost::shared_ptr<comminternal::PkgMsg> pPkgMsgReply = codecutil::getClientMsg_InitStatus(comminternal::PkgMsg_EnMsgStatusCode_MSG_CONNECTED);
	pPkgMsgReply->set_issuc(true);
	callback_(pPkgMsgReply);

	LOG(INFO) << "client on_open...";

}

void wscli::on_close(websocketpp::connection_hdl hdl){
	hdl_.reset();
	boost::shared_ptr<comminternal::PkgMsg> pPkgMsgReply = codecutil::getClientMsg_InitStatus(comminternal::PkgMsg_EnMsgStatusCode_MSG_CLOSED);
	pPkgMsgReply->set_issuc(false);
	callback_(pPkgMsgReply);

	LOG(INFO) << "client on_close...";
}

void wscli::on_message(websocketpp::connection_hdl hdl, message_ptr msg){
	std::cout << "Received Echo: " << msg->get_payload() << std::endl;

	websocketpp::lib::error_code ec;
	boost::shared_ptr<comminternal::PkgMsg> pPkgMsgReply = codecutil::getInMsgFromHex(msg->get_payload());
	if (!pPkgMsgReply){
		LOG(INFO) << "(on_message)unknow server:" << msg->get_payload();
		client_.close(hdl, websocketpp::close::status::going_away, "unknow server", ec);
		return;
	}
	callback_(pPkgMsgReply);

	if (!pPkgMsgReply->issuc()){
		client_.close(hdl, websocketpp::close::status::going_away, pPkgMsgReply->errdevdesc(), ec);
	}

}

void wscli::send_messsage(boost::shared_ptr<comminternal::PkgMsg> pMsgReq){
	if (hdl_.use_count() > 0){
		LOG(INFO) << "(send_messsage)" << codecutil::getHexFromMsg(pMsgReq);

		client_.send(hdl_, codecutil::getHexFromMsg(pMsgReq), websocketpp::frame::opcode::text);
	}
	else{
		boost::shared_ptr<comminternal::PkgMsg> pPkgMsgReply = codecutil::getClientMsg_InitStatus(comminternal::PkgMsg_EnMsgStatusCode_MSG_CONNECTED);
		pPkgMsgReply->set_issuc(false);
		pPkgMsgReply->set_errdevdesc("not connected");
		callback_(pPkgMsgReply);
	}
}

void wscli::stop(){
}
