#ifndef ARRAY_HPP
#define ARRAY_HPP


template <typename T>
class Array
{
	private:
		unsigned int _size;
		T* _data;
	public:
		Array();
		Array(unsigned int size);
		Array(const Array &other);
		~Array();
		Array &operator=(const Array &other);
		T &operator[](unsigned int index) const;
		unsigned int size() const;
};


#endif // ARRAY_HPP