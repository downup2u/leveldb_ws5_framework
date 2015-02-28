#include "leveldbdispatcher.h"


leveldbdispatcher::leveldbdispatcher(boost::shared_ptr<leveldb::DB> pDB){
	pDB_ = pDB;
}


void leveldbdispatcher::registerCallback(boost::shared_ptr<ProtobufDispatcher> msgdispatcher){

	msgdispatcher->registerMessageCallback<sample_projectname::PkgOptTable1Req>(boost::bind(&leveldbdispatcher::onmessage_t1, this, _1, _2, _3, _4));
	msgdispatcher->registerMessageCallback<sample_projectname::PkgOptTable2Req>(boost::bind(&leveldbdispatcher::onmessage_t2, this, _1, _2, _3, _4));
}

void leveldbdispatcher::onmessage_t1(boost::shared_ptr<comminternal::PkgMsg> pMsgReq, boost::shared_ptr<sample_projectname::PkgOptTable1Req> pReq, boost::shared_ptr<comminternal::PkgSessionUser> pSessionUsr, const SessionCallBack callback){

}

void leveldbdispatcher::onmessage_t2(boost::shared_ptr<comminternal::PkgMsg> pMsgReq, boost::shared_ptr<sample_projectname::PkgOptTable2Req> pReq, boost::shared_ptr<comminternal::PkgSessionUser> pSessionUsr, const SessionCallBack callback){

}
