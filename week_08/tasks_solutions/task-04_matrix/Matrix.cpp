#include "Matrix.h"

void Matrix::free()
{
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = nullptr;

	rows = 0;
	colls = 0;

	bool isNull = false;
	bool isChecked = false;
}
void Matrix::copyFrom(const Matrix& other)
{
	rows = other.rows;
	colls = other.colls;
	matrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[colls];
		for (int j = 0; j < colls; i++) {
			matrix[i][j] = other.matrix[i][j];
		}
	}

	isChecked = other.isChecked;
	isNull = other.isNull;
}

Matrix::Matrix() : rows(2), colls(2), isNull(true), isChecked(false)
{
	matrix = new int* [this->rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[this->colls] {};
	}
}
Matrix::Matrix(int rows, int colls)
{
	if (rows < 1 || colls < 1) return;

	this->rows = rows;
	this->colls = colls;

	matrix = new int* [this->rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[this->colls] {};
	}

	isNull = true;
	isChecked = false;
}
Matrix::Matrix(const Matrix& other)
{
	copyFrom(other);
}
Matrix& Matrix::operator=(const Matrix& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Matrix::~Matrix()
{
	free();
}

Matrix& Matrix::operator+=(const Matrix& other)
{
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < colls; ++j) {
			matrix[i][j] += other.matrix[i][j];
		}
	}

	isChecked = false;
	return *this;
}
Matrix& Matrix::operator*=(const Matrix& other)
{
	Matrix result(rows, other.colls);

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < other.colls; ++j) {
			for (int k = 0; k < colls; ++k) {
				result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
			}
		}
	}

	free();
	copyFrom(result);

	return *this;
}

bool Matrix::operator==(const Matrix& other)
{
	if (rows != other.rows || colls != other.colls) return false;

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < colls; ++j) {
			if (matrix[i][j] != other.matrix[i][j]) return false;
		}
	}
	return true;
}
bool Matrix::operator!=(const Matrix& other)
{
	return !(*this == other);
}
Matrix::operator bool() const
{
	if (!isChecked) {
		isNull = true;
		for (int i = 0; i < rows && isNull; i++) {
			for (int j = 0; i < colls; i++) {
				if (matrix[i][j] != 0) {
					isNull = false;
					break;
				}
			}
		}
		isChecked = true;
	}
	return !isNull;
}

int* Matrix::operator[](int idx)
{
	return matrix[idx];
}
const int* Matrix::operator[](int idx) const
{
	return matrix[idx];
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
	Matrix result(lhs);
	result += lhs;
	return result;
}
Matrix operator*(const Matrix& lhs, const Matrix& rhs)
{
	Matrix result(lhs);
	result *= rhs;
	return result;
}
