#include "stack.h"

template<typename T>
Stack<T>::~Stack()
{
	if (arr != NULL)
	{
		delete[] arr;
	}
}

template<typename T>
bool Stack<T>::Push(const T _data)
{
	if (cur <= size - 1)
	{
		arr[++cur] = _data;
		return true;
	}
	return false;
}

template<typename T>
T Stack<T>::Pop()
{
	if (cur != -1)
	{
		return arr[cur--];
	}
	return NULL;
}

template<typename T>
T Stack<T>::Top() const
{
	if (!IsEmpty())
	{
		return arr[cur];
	}
	return NULL;
}

template<typename T>
bool Stack<T>::IsEmpty() const
{
	return cur == -1;
}

template<typename T>
void Stack<T>::Reset()
{
	if (arr != NULL)
	{
		delete[] arr;
	}
	arr = new T[size];
	cur = -1;
}

template<typename T>
void Stack<T>::Print() const
{
	printf("arr: ");
	for (int i = 0; i <= cur; i++)
	{
		cout << arr[i] << " ";
	}
	printf("\n");
}