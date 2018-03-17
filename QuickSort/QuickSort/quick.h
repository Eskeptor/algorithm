#pragma once
#include <stdio.h>
#include <stdlib.h>

int partition(int _arr[], const int _begin, const int _end, const int _pivot);
void quickSort(int _arr[], const int _begin, const int _end);
void printArr(const int _arr[], const int _length);