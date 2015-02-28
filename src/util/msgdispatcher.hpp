#ifndef _MSGDISPATCHER_WRAP_INCLUDE_H
#define _MSGDISPATCHER_WRAP_INCLUDE_H

#include <google/protobuf/message.h>

#include "packmsg.pb.h"

#include <boost/asio.hpp>
#include <boost/serialization/singleton.hpp> 

#include "dispatcher.hpp"
#include "codec.h"
#include <boost/make_shared.hpp>

template <typename TSessionDispatcher> 
class msgdispatcher{
public:
	msgdispatcher(){};
	template <typename DB> void startSrv(boost::shared_ptr<DB> pdb){
		msgdispatcher_ = boost::make_shared<ProtobufDispatcher>();
		pPkgSessionUser_ = boost::make_shared<comminternal::PkgSessionUser>();
		psessdbdispatcher_ = boost::make_shared<TSessionDispatcher>(pdb);
		psessdbdispatcher_->registerCallback(msgdispatcher_);
	}
public:
	void onMessage(boost::shared_ptr<comminternal::PkgMsg> pMsgReq, SessionCallBack callback){
		if (pMsgReq){
			boost::shared_ptr<google::protobuf::Message> pMsg = codecutil::getMsgFromHex(pMsgReq->reqmsgtype(), pMsgReq->reqmsgdata());
			msgdispatcher_->onMessage(pMsgReq, pMsg, pPkgSessionUser_, callback);
		}
	}
public:
	boost::shared_ptr<comminternal::PkgSessionUser> pPkgSessionUser_;
	boost::shared_ptr<TSessionDispatcher> psessdbdispatcher_;
	boost::shared_ptr<ProtobufDispatcher> msgdispatcher_;
};

#endif