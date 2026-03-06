#include <iostream>

class Time {
public:
	Time() : hour(0), minute(0), second(0) {}
	Time(unsigned int h, unsigned int m, unsigned int s)
		: hour(h), minute(m), second(s) {
		normalise();
	}

	unsigned int getHour() const {
		return hour;
	}
	unsigned int getMinute() const {
		return minute;
	}
	unsigned int getSecond() const {
		return second;
	}

	void setHour(unsigned int h) {
		hour = h % 24;
	}
	void setMinute(unsigned int m) {
		minute = m;
		normalise();
	}
	void setSecond(unsigned int s) {
		second = s;
		normalise();
	}

	void tick() {
		addSeconds(1);
	}

	void addSeconds(unsigned int s) {
		second += s;
		normalise();
	}

	unsigned int secondsFromStart() const {
		return hour * 3600 + minute * 60 + second;
	}

	unsigned int secondsToMidnight() const {
		return 24 * 3600 - secondsFromStart();
	}

	bool isDinnerTime() const {
		unsigned int current = secondsFromStart();
		unsigned int start = Time(20, 30, 0).secondsFromStart();
		unsigned int end = Time(22, 0, 0).secondsFromStart();
		return current >= start && current <= end;
	}

	bool isEarlierThan(const Time& other) const {
		return this->secondsFromStart() < other.secondsFromStart();
	}

	void print() const {
		if (hour < 10)
			std::cout << "0";
		std::cout << hour << ":";

		if (minute < 10)
			std::cout << "0";
		std::cout << minute << ":";

		if (second < 10)
			std::cout << "0";
		std::cout << second;
	}

private:
	unsigned int hour, minute, second;

	void normalise() {
		minute += second / 60;
		second %= 60;

		hour += minute / 60;
		minute %= 60;

		hour %= 24;
	}
};