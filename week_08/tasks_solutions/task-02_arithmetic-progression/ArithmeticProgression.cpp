#include "ArithmeticProgression.h"

ArithmeticProgression::ArithmeticProgression() : firstMember(1), diff(1)
{
}
ArithmeticProgression::ArithmeticProgression(int firstMember, int diff) : firstMember(firstMember), diff(diff)
{
}

void ArithmeticProgression::setFirstMember(int firstMember)
{
	this->firstMember = firstMember;
}

ArithmeticProgression& ArithmeticProgression::operator+=(const ArithmeticProgression& other)
{
	firstMember += other.firstMember;
	diff += other.diff;
	return *this;
}
ArithmeticProgression& ArithmeticProgression::operator-=(const ArithmeticProgression& other)
{
	firstMember -= other.firstMember;
	diff -= other.diff;
	return *this;
}

int ArithmeticProgression::operator[](int idx) const
{
	return firstMember + idx * diff;
}
int ArithmeticProgression::operator()(int n) const
{
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (*this)[i];
	}
	return sum;
}

ArithmeticProgression operator+(const ArithmeticProgression& ap, unsigned toSkip)
{
	int newFirstMember = ap.firstMember + (toSkip - 1) * ap.diff;
	return ArithmeticProgression(newFirstMember, ap.diff);
}

ArithmeticProgression operator+(const ArithmeticProgression& lhs, const ArithmeticProgression& rhs)
{
	ArithmeticProgression result(lhs);
	result += rhs;
	return result;
}
ArithmeticProgression operator-(const ArithmeticProgression& lhs, const ArithmeticProgression& rhs)
{
	ArithmeticProgression result(lhs);
	result -= rhs;
	return result;
}


