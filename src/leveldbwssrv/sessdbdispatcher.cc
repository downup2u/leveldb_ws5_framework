#include "sessdbdispatcher.h"
#include "codec.h"
#include <jansson.h>

sessdbdispatcher::sessdbdispatcher(boost::shared_ptr<leveldb::DB> pDB){
}

sessdbdispatcher::~sessdbdispatcher()
{

}

void sessdbdispatcher::registerCallback(boost::shared_ptr<ProtobufDispatcher> msgdispatcher){

	msgdispatcher->registerMessageCallback<sample_projectname::PkgOptTable1Req>(boost::bind(&sessdbdispatcher::onmessage_t1, this, _1, _2, _3, _4));
	msgdispatcher->registerMessageCallback<sample_projectname::PkgOptTable2Req>(boost::bind(&sessdbdispatcher::onmessage_t2, this, _1, _2, _3, _4));
}

void sessdbdispatcher::onmessage_t1(boost::shared_ptr<comminternal::PkgMsg> pMsgReq, boost::shared_ptr<sample_projectname::PkgOptTable1Req> pReq, boost::shared_ptr<comminternal::PkgSessionUser> pSessionUsr, const SessionCallBack callback){
	std::cout << "get messgage1" << std::endl;
	boost::shared_ptr<comminternal::PkgMsg> pMsgReply = boost::make_shared<comminternal::PkgMsg>(*pMsgReq);
	callback(pMsgReply);
}

void sessdbdispatcher::onmessage_t2(boost::shared_ptr<comminternal::PkgMsg> pMsgReq, boost::shared_ptr<sample_projectname::PkgOptTable2Req> pReq, boost::shared_ptr<comminternal::PkgSessionUser> pSessionUsr, const SessionCallBack callback){
	std::cout << "get messgage2" << std::endl;
	boost::shared_ptr<comminternal::PkgMsg> pMsgReply = boost::make_shared<comminternal::PkgMsg>(*pMsgReq);
	callback(pMsgReply);

}
