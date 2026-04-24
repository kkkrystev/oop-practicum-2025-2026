#include "SetOfVectors.h"

static size_t id = 1;

SetOfVectors::SetOfVectors()
{
	_id = id++;
}

void SetOfVectors::add(const Vector& v) 
{
	for (int i = 0; i < _vectors.size(); ++i)
		if (_vectors[i] == v)
			return;
		
	_vectors.push_back(v);
}

void SetOfVectors::remove(size_t index)
{
	if (index >= _vectors.size())
	{
		std::cout << "Out of range!\n";
		return;
	}

	std::swap(_vectors[index], _vectors[_vectors.size() - 1]);
	_vectors.pop_back();
}

void SetOfVectors::print() const
{
	std::cout << "ID: " << _id << '\n';
	for (int i = 0; i < _vectors.size(); ++i)
	{
		std::cout << _vectors[i];
	}
	std::cout << '\n';
}

size_t SetOfVectors::getSize() const
{
	return _vectors.size();
}

SetOfVectors operator|(const SetOfVectors& lhs, const SetOfVectors& rhs)
{
	SetOfVectors s;

	for (int i = 0; i < lhs.getSize(); ++i)
		s.add(lhs._vectors[i]);

	for (int i = 0; i < rhs.getSize(); ++i)
		s.add(rhs._vectors[i]);

	return s;
}

SetOfVectors operator&(const SetOfVectors& lhs, const SetOfVectors& rhs)
{
	SetOfVectors s;

	for (int i = 0; i < lhs.getSize(); ++i)
		for (int j = 0; j < rhs.getSize(); ++j)
			if (lhs._vectors[i] == rhs._vectors[j])
				s.add(lhs._vectors[i]);

	return s;
}

