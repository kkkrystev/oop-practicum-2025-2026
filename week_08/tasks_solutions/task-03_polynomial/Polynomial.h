#pragma once
#include <iostream>

class Polynomial
{
	int* coeffs;
	unsigned degree;

	void free();
	void copyFrom(const Polynomial& other);
	void moveFrom(Polynomial&& other);

public:
	Polynomial();
	Polynomial(unsigned degree, int* coeffs);

	Polynomial(const Polynomial& other);
	Polynomial& operator=(const Polynomial& other);

	Polynomial(Polynomial&& other);
	Polynomial& operator=(Polynomial&& other);

	~Polynomial();

	Polynomial& operator+=(const Polynomial& other);
	Polynomial& operator-=(const Polynomial& other);
	Polynomial& operator*=(const Polynomial& other);
	Polynomial operator~() const;
	int operator()(double x) const; 

	friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly);
	friend std::istream& operator>>(std::istream& is, Polynomial& poly);
};

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs);
Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs);

