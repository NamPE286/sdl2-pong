#include "LogUtils.hpp"
#include <iostream>

static void logStatus(Status* stat) {
	auto delayStartTime = std::chrono::high_resolution_clock::now();

	while (stat->running) {
		auto curTime = std::chrono::high_resolution_clock::now();
		int delta = std::chrono::duration<float, std::chrono::milliseconds::period>(curTime - delayStartTime).count();

		if (delta < 1000) {
			continue;
		}

		delayStartTime = curTime;

		std::cout << "Frame time: " << stat->deltaTime << " FPS: ";

		if ((int)stat->deltaTime == 0) {
			std::cout << "inf";
		}
		else {
			std::cout << 1000 / (int)stat->deltaTime;
		}

		std::cout << '\n';
	}
}

std::thread LogUtils::statusThread(Status* stat) {
	return std::thread(logStatus, stat);
}