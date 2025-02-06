#ifndef LOGUTILS_HEADER
#define LOGUTILS_HEADER

#include <thread>

struct Status {
	bool running = true;
	float deltaTime = 0.0f;
};

namespace LogUtils {
	std::thread statusThread(Status* stat);
}

#endif