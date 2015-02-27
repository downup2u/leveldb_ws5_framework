#ifndef _LEVELDB_DISPATCHER_INCLUDE_H
#define _LEVELDB_DISPATCHER_INCLUDE_H

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/smart_ptr.hpp>
#include "dispatcher.hpp"

#include "leveldb/db.h"

#include "model_db.pb.h"
#include "model_comm.pb.h"
#include "packmsg.pb.h"

class leveldbdispatcher{
public:
	leveldbdispatcher(boost::shared_ptr<leveldb::DB> pDB);
public:
	void registerCallback(boost::shared_ptr<ProtobufDispatcher> msgdispatcher);
private:
	boost::shared_ptr<leveldb::DB> pDB_;
public:
	void onmessage_t1(boost::shared_ptr<comminternal::PkgMsg> pMsgReq, boost::shared_ptr<sample_projectname::PkgOptTable1Req> pReq, boost::shared_ptr<comminternal::PkgSessionUser> pSessionUsr, const SessionCallBack callback);

};

#endif