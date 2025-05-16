#pragma once
#include <iostream>

template <class T>
class BasicString
{
public:
	BasicString() : data(new T[1]), len(0), cap(1)
	{
		data[0] = '\0';
	}

	BasicString(const T* str) : len(std::strlen(str))
	{
		cap = len + 1;
		data = new T[cap];
		std::memcpy(data, str, len + 1);
	}

	BasicString(const BasicString& other)
	{
		len = other.len;
		cap = other.cap;
		data = new T[cap];
		std::memcpy(data, other.data, len + 1);
	}

	BasicString(BasicString&& other) noexcept : data(other.data), len(other.len), cap(other.cap)
	{
		other.data = nullptr;
		other.len = 0;
		other.cap = 0;
	}

	~BasicString()
	{
		delete[] data;
	}

	BasicString& operator=(const BasicString& other)
	{
		if (this != &other)
		{
			delete[] data;
			len = other.len;
			cap = other.cap;
			data = new T[cap];
			std::memcpy(data, other.data, len + 1);
		}
		return *this;
	}

	BasicString& operator=(BasicString&& other) noexcept
	{
		if (this != &other)
		{
			delete[] data;
			data = other.data;
			len = other.len;
			cap = other.cap;
			other.data = nullptr;
			other.len = 0;
			other.cap = 0;
		}
		return *this;
	}

	T& operator [](size_t index)
	{
		return data[index];
	}

	const T& operator [](size_t index) const
	{
		return data[index];
	}

	bool empty() const
	{
		return len == 0;
	}

	size_t size() const
	{
		return len;
	}

	size_t capacity() const
	{
		return cap;
	}

	void append(const T* str)
	{
		if (!str) return;
		size_t addLen = std::strlen(str);
		if (len + addLen + 1 > cap)
		{
			size_t newCap = std::max(cap * 2, len + addLen + 1);
			resize(newCap);
		}
		std::memcpy(data + len, str, addLen);
		len += addLen;
		data[len] = '\0';
	}

	int find(const T* str)
	{
		if (!str || !data) return -1;
		size_t searchLen = std::strlen(str);
		if (searchLen == 0 || searchLen > len) return -1;

		for (size_t i = 0; i <= len - searchLen; ++i)
		{
			bool found = true;
			for (size_t j = 0; j < searchLen; ++j)
			{
				if (data[i + j] != str[j])
				{
					found = false;
					break;
				}
			}
			if (found) return static_cast<int>(i);
		}
		return -1;
	}

private:
	T* data;
	size_t len;
	size_t cap;

	void resize(size_t newCapacity)
	{
		if (newCapacity > cap)
		{
			T* newData = new T[newCapacity];
			std::memcpy(newData, data, (len + 1) * sizeof(T));
			delete[] data;
			data = newData;
			cap = newCapacity;
		}
	}
};