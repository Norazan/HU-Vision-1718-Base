#pragma once
#include <chrono>
using namespace std::chrono;
typedef high_resolution_clock::time_point timepoint;

class Clock {
public:
	static timepoint now() {
		return high_resolution_clock::now();
	}
	static double getMicroSecondsFrom(timepoint& p) {
		return double(duration_cast<microseconds>(now() - p).count());
	}
	static double getMilliSecondsFrom(timepoint& p) {
		return double(duration_cast<milliseconds>(now() - p).count());
	}
	static double getNanoSecondsFrom(timepoint& p) {
		return double(duration_cast<nanoseconds>(now() - p).count());
	}
};