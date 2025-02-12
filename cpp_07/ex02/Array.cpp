#include "Array.hpp"

template <typename T>
Array<T>::Array(): _size(0), _data(NULL) {}

template <typename T>
Array<T>::Array(unsigned int size): _size(size), _data(new T[_size]) {}

template <typename T>
Array<T>::Array(const Array &other): _size(other._size), _data(new T[_size])
{
	for(unsigned int i = 0; i < _size; i++)
		_data[i] = other._data[i];
}

template <typename T>
Array<T>::~Array() {delete [] _data;}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		if(_data != NULL)
			delete []_data;
		_size = other._size;
		_data = new T[other._size];
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("index out of the range");
	return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const {return _size;}