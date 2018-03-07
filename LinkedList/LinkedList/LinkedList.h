#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
	Node<T>* next;
	T data;
	Node(const T _data) : data(_data) {}
};

template <typename T>
class LinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	int length;
public:
	LinkedList() : length(0) 
	{
		tail = new Node<T>(NULL);
		tail->next = head;
		head = tail;
	}
	~LinkedList()
	{
		if (!IsEmpty())
		{
			Node<T>* tmp_target = tail;
			Node<T>* next;
			for (int i = 0; i < length; i++)
			{
				next = tmp_target->next;
				delete tmp_target;
				tmp_target = next;
			}
			delete next;
		}
	}
	void insert(const T _data)
	{
		Node<T>* node = new Node<T>(_data);
		head->next = node;
		head = node;
		length++;
	}
	void insert(const T _data, const int _index)
	{
		if (_index <= length)
		{
			Node<T>* node = new Node<T>(_data);
			Node<T>* tmp_prev;
			Node<T>* tmp_target = tail;
			
			for (int i = 0; i < _index; i++)
			{
				tmp_prev = tmp_target;
				tmp_target = tmp_target->next;
			}
			node->next = tmp_target;
			tmp_prev->next = node;
			length++;
		}
		else
		{
			printf("Error: %d에 넣지 못함\n", _index);
		}
	}
	T remove(const int _index)
	{
		if (_index <= length)
		{
			T returnData;
			Node<T>* tmp_prev;
			Node<T>* tmp_target = tail;
			Node<T>* tmp_next;

			for (int i = 0; i < _index; i++)
			{
				tmp_prev = tmp_target;
				tmp_target = tmp_target->next;
				tmp_next = tmp_target->next;
			}
			returnData = tmp_target->data;
			tmp_prev->next = tmp_next;
			delete tmp_target;
			length--;
			return returnData;
		}
		else
		{
			printf("Error: %d위치의 값을 지우지 못함\n", _index);
			return NULL;
		}
	}
	T Top() const
	{
		if (!IsEmpty())
		{
			return head->data;
		}
		else
		{
			return NULL;
		}
	}
	void Print() const
	{
		if (!IsEmpty())
		{
			printf("리스트: ");
			Node<T>* cur = tail->next;
			for (int i = 0; i < length; i++)
			{
				cout << cur->data;
				cur = cur->next;
				if (i != length - 1)
				{
					printf(", ");
				}
				else
				{
					printf("\n");
				}
			}
		}
		else
		{
			printf("리스트가 비어있습니다.\n");
		}
	}
	bool IsEmpty() const
	{
		return length == 0;
	}
};