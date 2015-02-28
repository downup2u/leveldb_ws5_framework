#include "wssrvmain.h"
#include <gflags/gflags.h>
wssrvmain::wssrvmain(){
	
}

DEFINE_int32(srvport, 9002, "server listen port");

void wssrvmain::start() {
	wssrv_ = boost::make_shared<wssrv>(io_);
	workPtr_ = boost::make_shared<boost::asio::io_service::work>(io_);
	wssrv_->run(FLAGS_srvport);
	t_ = boost::make_shared<boost::thread>(boost::bind(&boost::asio::io_service::run, &io_));

}

void wssrvmain::stop(){
	if (wssrv_){
		wssrv_->stop();
		io_.stop();
		t_->join();
	}
}