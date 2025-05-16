#include "Array.h"

Array::Array(size_t size)
	: size(0), arr(nullptr)
{
	if (size > 0)
	{
		this->size = size;
		arr = new int[size] {};
	}
}