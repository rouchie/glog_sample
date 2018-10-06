#include "glog.h"

using namespace std;

int main(int argc, char **argv)
{

	CGLOG::INIT_GLOG(argv[0], "./");

	DLOG(INFO) << "begin.";

	LOG(INFO) << __TIME__;
	LOG(INFO) << "what the fuck.";
	LOG(WARNING) << "what the fuck.";
	LOG(ERROR) << "what the fuck.";
	LOG(FATAL) << "what the fuck.";

	LOG(INFO) << "something out more.";

	return 0;
}
