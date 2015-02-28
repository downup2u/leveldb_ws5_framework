#include "wssrvmain.h"
#include <gflags/gflags.h>
#include "glog.h"
//std::string scmdline = "log_dir=f:/iteasysoft/logs minloglevel=0 wssrv --srvport=9003 --dbpath=f:/iteasysoft/dbdata --logname=wssrv";
//DEFINE_int32(minloglevel, 0, "Messages logged at a lower level than this don't "
//	"actually get logged anywhere");

DECLARE_int32(minloglevel);
DECLARE_int32(srvport);
DECLARE_string(log_dir);

int main(int argc, char *argv[]) {
	google::ParseCommandLineFlags(&argc, &argv, true);

	//std::cout << "minloglevel:" << FLAGS_minloglevel << ",log_dir:" << FLAGS_log_dir << ",srvport:" << FLAGS_srvport;
 	initLogPath();
	LOG(INFO) << "server start...";

	wssrvmain::get_mutable_instance().start();
	char ch = getchar();
	while (ch != 'q'){
		ch = getchar();
	}
	wssrvmain::get_mutable_instance().stop();
}
