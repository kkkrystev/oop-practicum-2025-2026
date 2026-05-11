#pragma once

class Matrix
{
	int** matrix;
	unsigned rows, colls;
	mutable bool isNull;
	mutable bool isChecked;

	void free();
	void copyFrom(const Matrix& other);

public:
	Matrix();
	Matrix(int rows, int colls);
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	~Matrix();

	Matrix& operator+=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);

	bool operator==(const Matrix& other);
	bool operator!=(const Matrix& other);
	operator bool() const;

	int* operator[](int idx);
	const int* operator[](int idx) const;
};

Matrix operator+(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& lhs, const Matrix& rhs);