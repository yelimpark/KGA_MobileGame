#pragma once

template <typename T>
class SmartPtr
{
private:
	T* posptr;
public:
	SmartPtr(T* ptr) : posptr(ptr)
	{  }

	T& operator*() const
	{
		return *posptr;
	}
	T* operator->() const
	{
		return posptr;
	}
	~SmartPtr()
	{
		delete posptr;
	}
};