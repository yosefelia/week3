#include <iostream>
#include "Vector.h"
using namespace std;

Vector::Vector(int n)
{
	if (n < 2)
	{
		n = 2;
	}
	_size = 0;
	_capacity = n;
	_resizeFactor = n;
	_elements = new int[_capacity];
}

Vector::~Vector()
{
	delete[] _elements;
}

int Vector::size() const
{
	return _size;
}

int Vector::capacity() const
{
	return _capacity;
}

int Vector::resizeFactor() const
{
	return _resizeFactor;
}
bool Vector::empty() const
{
	return _size == 0;
}

void Vector::push_back(const int& val)
{
	if (_size == _capacity)
	{
		reserve(_capacity + _resizeFactor);
	}
	_elements[_size++] = val;
}

int Vector::pop_back()
{
	if (_size == 0)
	{
		std::cerr << "Error from pop_back: vector ia empty\n";
		return -9999;
	}
	int lastElement = _elements[_size - 1];
	_size--;

	return lastElement;
}

void Vector::reserve(const int n)
{
	int newCapacity = _capacity;
	int i = 0;
	int* newElements = nullptr;
	if (n <= _capacity)
	{
		return;
	}

	while (newCapacity < n)
	{
		newCapacity += _resizeFactor;
	}
	newElements = new int[newCapacity];
	for (i = 0; i < _size; i++)
	{
		newElements[i] = _elements[i];
	}

	delete[] _elements;
	_elements = newElements;
	_capacity = newCapacity;
}

void Vector::resize(const int n)
{
	if (n <= _capacity)
	{
		_size = n;
	}
	else
	{
		reserve(n);
		_size = n;
	}
}

void Vector::resize(const int n, const int& val)
{
	int i = 0;
	if (n > _capacity)
	{
		reserve(n);
	}

	for (i = _size; i < n; i++)
	{
		_elements[i] = val;
	}
	_size = n;
}

void Vector::assign(const int val)
{
	int i = 0;
	for (i = 0; i < _size; i++)
	{
		_elements[i] = val;
	}
}

Vector::Vector(const Vector& other)
{
	int i = 0;
	_capacity = other._capacity;
	_size = other._size;
	_resizeFactor = other._resizeFactor;

	_elements = new int[_capacity];
	for (i = 0; i < _size; i++)
	{
		_elements[i] = other._elements[i];
	}
}

Vector& Vector::operator=(const Vector& other)
{
	if (this != &other)
	{
		Vector temp(other);
		temp.swap(*this);
	}
	return *this;
}

void Vector::swap(Vector& other) noexcept
{
	std::swap(_elements, other._elements);
	std::swap(_capacity, other._capacity);
	std::swap(_size, other._size);
	std::swap(_resizeFactor, other._resizeFactor);
}

int& Vector::operator[](int n) const
{
	if (n < 0 || n >= _size)
	{
		std::cerr << "Error: Index " << n << " is out of range (size: " << _size << ")." << std::endl;
		exit(-1);
	}
	return _elements[n];
}