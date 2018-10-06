#ifndef _GLOG_SAMPLE_H_
#define _GLOG_SAMPLE_H_

#include <glog/logging.h>
#include <fstream>

typedef void (*pfnSigHandle)(const char *pData, int iSize);

class CGLOG {
	public:
	CGLOG(const char *arg) {
		PCHECK(arg != NULL);

		FLAGS_log_dir = "./";
		init(arg);
		google::InstallFailureWriter(CGLOG::SignalHandle);
	}

	CGLOG(const char *arg, const char *log_dir) {
		PCHECK(arg != NULL && log_dir != NULL);

		FLAGS_log_dir = log_dir;
		init(arg);
		google::InstallFailureWriter(CGLOG::SignalHandle);
	}

	CGLOG(const char *arg, pfnSigHandle pfn) {
		PCHECK(arg != NULL && pfn != NULL);

		FLAGS_log_dir = "./";
		init(arg);
		google::InstallFailureWriter(pfn);
	}

	CGLOG(const char *arg, const char *log_dir, pfnSigHandle pfn) {
		PCHECK(arg != NULL && log_dir != NULL && pfn != NULL);

		FLAGS_log_dir = log_dir;
		init(arg);
		google::InstallFailureWriter(pfn);
	}

	virtual ~CGLOG() {
		google::ShutdownGoogleLogging();
	}

	private:
	void init(const char *arg) {
		google::InitGoogleLogging(arg);

		//FLAGS_logtostderr = 1;
		FLAGS_alsologtostderr = 1;
		FLAGS_colorlogtostderr = 1;
		google::InstallFailureSignalHandler();
	}

	static void SignalHandle(const char* data, int size)
	{
	    std::ofstream fs("glog_dump.log",std::ios::app);
	    std::string str = std::string(data,size);
	    fs<<str;
	    fs.close();
	    LOG(ERROR)<<str;
	}
};

#endif
