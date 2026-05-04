#include "Vector.h"


void Vector::copyFrom(const Vector& other)
{
	if (!other._data)
	{
		_dim = 1;
		_data = new int[1];
		_data[0] = 0;
		return;
	}

	_dim = other._dim;
	_data = new int[_dim];
	for (int i = 0; i < _dim; ++i)
		_data[i] = other._data[i];
}

void Vector::moveFrom(Vector&& other)
{
	_dim = other._dim;
	_data = other._data;

	other._dim = 0;
	other._data = nullptr;
}

void Vector::free()
{
	delete[] _data;
	_data = nullptr;
	_dim = 0;
}

Vector::Vector(size_t dimention)
{
	_dim = dimention;
	_data = new int[_dim] {0};
}


Vector::Vector(const int* data, size_t dimention)
{
	if (!data)
	{
		_dim = 1;
		_data = new int[1];
		_data[0] = 0;
		return;
	}

	_dim = dimention;
	_data = new int[_dim];
	for (int i = 0; i < _dim; ++i)
		_data[i] = data[i];
}

Vector::Vector(const Vector& other)
{
	copyFrom(other);
}

Vector& Vector::operator=(const Vector& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Vector::Vector(Vector&& other) noexcept
{
	moveFrom(std::move(other));
}

Vector& Vector::operator=(Vector&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}


int Vector::operator[](size_t ind)
{
	if (ind >= _dim)
		return 0;

	return _data[ind];
}
const int Vector::operator[](size_t ind) const
{
	if (ind >= _dim)
		return 0;

	return _data[ind];
}

Vector& Vector::operator+=(const Vector& other)
{
	if (_dim != other._dim)
	{
		std::cout << "Not same dimention!\n";
		return *this;
	}

	for (int i = 0; i < _dim; ++i)
		_data[i] += other._data[i];

	return *this;
}

Vector operator+(const Vector& lhs, const Vector& rhs)
{
	if (lhs._dim != rhs._dim)
	{
		std::cout << "Not same dimention!\n";
		return lhs;
	}

	Vector v(lhs._dim);
	v += lhs;
	v += rhs;
	return v;
}



std::ostream& operator<<(std::ostream& os, const Vector& v)
{
	os << "<";
	for (int i = 0; i < v._dim - 1; ++i)
	{
		os << v._data[i] << ", ";
	}
	os << v._data[v._dim - 1] << ">\n";
	return os;
}



std::istream& operator>>(std::istream& is, Vector& v)
{
	for (int i = 0; i < v._dim; ++i)
	{
		is >> v._data[i];
	}
	return is;
}

Vector::~Vector()
{
	free();
}

bool operator==(const Vector& lhs, const Vector& rhs)
{
	if (lhs._dim != rhs._dim)
		return 0;

	for (int i = 0; i < lhs._dim; ++i)
		if (lhs._data[i] != rhs._data[i])
			return 0;

	return 1;
}


bool operator!=(const Vector& lhs, const Vector& rhs)
{
	return !(lhs == rhs);
}
