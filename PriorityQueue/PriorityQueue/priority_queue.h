#pragma once
#include <stdio.h>
#include <stdlib.h>
#define BOOL int
#define TRUE 1
#define FALSE 0

void createQueue(const int _size);
BOOL isEmpty();
BOOL isFull();
void maxHeapify(const int _idx, const int _length);
void printQueue();
void buildMaxHeap(const int _length);
void heapSort();
void insertData(const int _data);
int removeData();
void clear();