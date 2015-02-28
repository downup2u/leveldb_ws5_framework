#ifndef _SESSION_DB_DISPATCHER_INCLUDE_H
#define _SESSION_DB_DISPATCHER_INCLUDE_H

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/smart_ptr.hpp>
#include "packmsg.pb.h"
#include "dispatcher.hpp"
#include "model_db.pb.h"
#include "leveldb/db.h"

typedef boost::function<void(boost::shared_ptr<comminternal::PkgMsg> pPkgMsg)> msgSrvCallback;
class sessdbdispatcher {
public:
	sessdbdispatcher(boost::shared_ptr<leveldb::DB> pDB);
	~sessdbdispatcher();
public:
	void registerCallback(boost::shared_ptr<ProtobufDispatcher> msgdispatcher);

public:
	//void onmessage_login(boost::shared_ptr<comminternal::PkgMsg> pMsgReq, boost::shared_ptr<xkcrm::PkgUserLoginReq> pReq, boost::shared_ptr<comminternal::PkgSessionUser> pSessionUsr, const SessionCallBack callback);
private:
	msgSrvCallback callback_;

	//void initData();
	//void queryData();
	

};
#endif