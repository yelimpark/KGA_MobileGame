#pragma once
#include "HighCreditAccount.h"
#include <cassert>

template <typename T>
class BoundCheckArray
{
private:
	T* arr;
	int arrlen;

	BoundCheckArray(const BoundCheckArray& arr) { }
	BoundCheckArray& operator=(const BoundCheckArray& arr) { }

public:
	BoundCheckArray(int len)
		:arrlen(len)
	{
		arr = new T[len];
	}
	
	T& operator[] (int idx)
	{
		assert(idx >= 0 && idx < arrlen);

		return arr[idx];
	}
	
	T operator[] (int idx) const
	{
		assert(idx >= 0 && idx < arrlen);

		return arr[idx];
	}

	int GetArrLen() const
	{
		return arrlen;
	}

	void RemoveBCA(int idx, int max)
	{
		for (int i = idx; i < max-1; i++) {
			arr[i] = arr[i + 1];
		}
		arr[max - 1] = NULL;
	}

	~BoundCheckArray()
	{
		delete[]arr;
	}
};