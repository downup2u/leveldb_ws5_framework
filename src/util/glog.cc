#include "glog.h"
#include <gflags/gflags.h>
namespace GlobalLog
{
	DEFINE_string(logname, "Iteasysoft", "log name");

	void initLogPathWithName(const std::string &sLogPath, const std::string &sLogName, int nLevel){
		std::string sInfoDir = sLogPath + "/" + sLogName + "_INFO_";
		google::SetLogDestination(google::GLOG_INFO, sInfoDir.c_str());
		std::string sWarningDir = sLogPath + "/" + sLogName + "_WARN_";
		//google::SetLogDestination(google::WARNING, sWarningDir.c_str());   //设置 google::WARNING 级别的日志存储路径和文件名前缀
		std::string sErrDir = sLogPath + "/" + sLogName + "_ERR_";
		google::SetLogDestination(google::ERROR, sErrDir.c_str());
		std::string sFatalDir = sLogPath + "/" + sLogName + "_FATAL_";
		//google::SetLogDestination(google::FATAL, sFatalDir.c_str());
		google::InitGoogleLogging(sLogName.c_str());  //参数为自己的可执行文件名  
	}

	void initLogPath(){
		initLogPathWithName(FLAGS_log_dir, FLAGS_logname, FLAGS_minloglevel);
	}
	void initLogPath(const std::string &sPath, int nLevel){
		size_t n = sPath.rfind('/');
		if (n == std::string::npos){
			n = sPath.rfind('\\');
		}
		std::string sLogPath;
		std::string sLogName = "task";
		if (n != std::string::npos){
			sLogName = sPath.substr(n+1, std::string::npos);
			sLogPath = sPath.substr(0, n);
		}
		else{
			sLogPath = sPath;
		}
		FLAGS_log_dir = sLogPath;
		FLAGS_minloglevel = nLevel;
		initLogPathWithName(FLAGS_log_dir, "task", FLAGS_minloglevel);
	}
};
