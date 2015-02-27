#include <string>
#include <boost/make_shared.hpp>
#include "wsclimain.h"
#include "model_comm.pb.h"
#include <gflags/gflags.h>
#include "str2argv.h"

void onclient_msg(boost::shared_ptr<comminternal::PkgMsg> pMsgReply){
	if (pMsgReply){

	}
}

DEFINE_string(srvuri, "ws://localhost:9002", "server's uri");
DEFINE_int32(var3, 0, "value3 desc");
DEFINE_bool(mybool1, false, "mybool1 desc");

int main(int argc, char* argv[]) {
	{
		std::string scmdline = "wsclient --srvuri=ws://127.0.0.1:9002 --dbpath=f:/var/iteasysoft --mybool1=true";
		const char *errmsg;
		char **margv;
		int    margc;
		if (str2argv(scmdline.c_str(), &margc, &margv, &errmsg) == 0) {
			google::ParseCommandLineFlags(&margc, &margv, false);
			std::cout << "var1:" << FLAGS_srvuri << std::endl;
			std::cout << "var3:" << FLAGS_var3 << std::endl;
			std::cout << "mybool1:" << FLAGS_mybool1 << std::endl;

			argv_free(&margc, &margv);		
		}
		else {
			printf("parse error: %s\n", errmsg);
		}
	}
	wsclimain::get_mutable_instance().start(FLAGS_srvuri, boost::bind(onclient_msg, _1));
 
	char ch = getchar();
	while (ch != 'q'){
		if (ch == 'l'){			
			//boost::shared_ptr<xkcrm::PkgUserLoginReq> pReq = boost::make_shared<xkcrm::PkgUserLoginReq>();
			//pReq->set_phonenumber("18118003691");
			//pReq->set_password("123456");
			//pReq->set_gettype(xkcrm::EnGetType::GT_PHONE);
			//boost::shared_ptr<comminternal::PkgMsg> pPkgMsg = codecutil::getClientMsg_InitWithMsg(pReq);
			//wsclimain::get_mutable_instance().send_messsage(pPkgMsg);
		}
		
		ch = getchar();

	}

	wsclimain::get_mutable_instance().stop();
   
}