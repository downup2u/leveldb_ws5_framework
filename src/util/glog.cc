#include "glog.h"

namespace GlobalLog
{
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
		FLAGS_logbufsecs = 0;  //��־ʵʱ���
		FLAGS_max_log_size = 1024; // max log size is 1024M
		
		std::string sInfoDir = sLogPath + "/" + sLogName +"_INFO_";
		google::SetLogDestination(google::GLOG_INFO, sInfoDir.c_str());
		std::string sWarningDir = sLogPath + "/" + sLogName + "_WARN_";
		//google::SetLogDestination(google::WARNING, sWarningDir.c_str());   //���� google::WARNING �������־�洢·�����ļ���ǰ׺
		std::string sErrDir = sLogPath + "/" + sLogName + "_ERR_";
		google::SetLogDestination(google::ERROR, sErrDir.c_str());
		std::string sFatalDir = sLogPath + "/" + sLogName + "_FATAL_";
		//google::SetLogDestination(google::FATAL, sFatalDir.c_str());
		google::InitGoogleLogging(sLogName.c_str());  //����Ϊ�Լ��Ŀ�ִ���ļ���  
	}
};
