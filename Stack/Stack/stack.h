#pragma once
#include <iostream>

using namespace std;

template<typename T>
class Stack
{
private:
	int size;
	int cur;
	T* arr;
public:
	Stack(const int _size) : size(_size), cur(-1)
	{
		arr = new T[size];
	}
	~Stack();
	bool Push(const T _data);
	T Pop();
	T Top() const;
	bool IsEmpty() const;
	void Reset();
	void Print() const;
};