#pragma once
#include <iostream>

class Vector
{
	int* _data;
	size_t _dim;

	void copyFrom(const Vector& other);
	void moveFrom(Vector&& other);
	void free();

public:

	Vector() = delete;
	Vector(size_t dimention);
	Vector(const int* data, size_t dimention);

	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	Vector(Vector&& other) noexcept;
	Vector& operator=(Vector&& other) noexcept;

	int operator[](size_t ind);
	const int operator[](size_t ind) const;

	Vector& operator+=(const Vector& other);
	
	friend Vector operator+(const Vector& lhs, const Vector& rhs);
	friend std::istream& operator>>(std::istream& is, Vector& v);
	friend std::ostream& operator<<(std::ostream& os, const Vector& v);

	friend bool operator==(const Vector& lhs, const Vector& rhs);

	~Vector();
};

bool operator!=(const Vector& lhs, const Vector& rhs);



