#pragma once
class ArithmeticProgression
{
	int firstMember;
	int diff;

public:
	ArithmeticProgression();
	ArithmeticProgression(int firstMember, int diff);

	void setFirstMember(int firstMember);

	ArithmeticProgression& operator+=(const ArithmeticProgression& other);
	ArithmeticProgression& operator-=(const ArithmeticProgression& other);

	int operator[](int idx) const;
	int operator()(int n) const;

	friend ArithmeticProgression operator+(const ArithmeticProgression& ap, unsigned toSkip);
};

ArithmeticProgression operator+(const ArithmeticProgression& lhs, const ArithmeticProgression& rhs);
ArithmeticProgression operator-(const ArithmeticProgression& lhs, const ArithmeticProgression& rhs);

