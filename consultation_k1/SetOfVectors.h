#pragma once
#include "Vector.h"
#include <iostream>
#include <vector>

class SetOfVectors
{
	size_t _id;
	std::vector<Vector> _vectors;

public:

	SetOfVectors();

	size_t getSize() const;
	void add(const Vector& v);
	void remove(size_t index);
	void print() const;

	friend SetOfVectors operator|(const SetOfVectors& lhs, const SetOfVectors& rhs);
	friend SetOfVectors operator&(const SetOfVectors& lhs, const SetOfVectors& rhs);

};

