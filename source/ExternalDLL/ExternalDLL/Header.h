#pragma once
#include <chrono>
typedef std::chrono::time_point<std::chrono::steady_clock> timepoint;
class Clock {
public:
	static timepoint now() {
		return std::chrono::high_resolution_clock::now();
	}
	static double getMicroSecondsFrom(timepoint& p) {
		return double(std::chrono::duration_cast<std::chrono::microseconds>(now() - p).count());
	}
	static double getMilliSecondsFrom(timepoint& p) {
		return double(std::chrono::duration_cast<std::chrono::milliseconds>(now() - p).count());
	}
	static double getNanoSecondsFrom(timepoint& p) {
		return double(std::chrono::duration_cast<std::chrono::nanoseconds>(now() - p).count());
	}
};
