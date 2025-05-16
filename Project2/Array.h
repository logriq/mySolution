#pragma once

class Array
{
private:
	int* arr;
	size_t size;
public:
	Array(size_t size);
	Array(const Array& other);
	~Array();

	Array operator=(const Array& other);
	int& operator[](size_t index);
	const int& operator[](size_t index) const;

	size_t Size() const { return size; }
};
