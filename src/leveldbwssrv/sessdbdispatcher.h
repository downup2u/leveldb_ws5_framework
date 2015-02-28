#ifndef _SESSION_DB_DISPATCHER_INCLUDE_H
#define _SESSION_DB_DISPATCHER_INCLUDE_H

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/smart_ptr.hpp>
#include "packmsg.pb.h"
#include "dispatcher.hpp"
#include "model_db.pb.h"
#include "model_comm.pb.h"
#include "leveldb/db.h"


class sessdbdispatcher {
public:
	sessdbdispatcher(boost::shared_ptr<leveldb::DB> pDB);
	~sessdbdispatcher();
public:
	void registerCallback(boost::shared_ptr<ProtobufDispatcher> msgdispatcher);
public:
	void onmessage_t1(boost::shared_ptr<comminternal::PkgMsg> pMsgReq, boost::shared_ptr<sample_projectname::PkgOptTable1Req> pReq, boost::shared_ptr<comminternal::PkgSessionUser> pSessionUsr, const SessionCallBack callback);
	void onmessage_t2(boost::shared_ptr<comminternal::PkgMsg> pMsgReq, boost::shared_ptr<sample_projectname::PkgOptTable2Req> pReq, boost::shared_ptr<comminternal::PkgSessionUser> pSessionUsr, const SessionCallBack callback);
};
#endif