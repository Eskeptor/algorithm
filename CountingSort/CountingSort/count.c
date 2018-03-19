#include "count.h"

typedef struct _ARRAY
{
	int* originalDatas;
	int* countDatas;
	int* sortedDatas;
	int size;
	int max;
}Array;

Array* arr;

void createArray(int* _arr, const int _length, const int _max)
{
	arr = (Array*)malloc(sizeof(Array));
	arr->originalDatas = (int*)malloc(sizeof(int) * _length);
	for (int i = 0; i < _length; i++)
		arr->originalDatas[i] = _arr[i];
	arr->countDatas = (int*)calloc((_max + 1), sizeof(int));
	arr->sortedDatas = (int*)calloc(_length, sizeof(int));
	arr->size = _length;
	arr->max = _max;
}

void count1()
{
	for (int i = 0; i < arr->size; i++)
	{
		arr->countDatas[arr->originalDatas[i]]++;
	}
}

void count2()
{
	for (int i = 1; i <= arr->max; i++)
	{
		arr->countDatas[i] += arr->countDatas[i - 1];
	}
}

void sort()
{
	int cur;
	int prev = arr->countDatas[0];
	int counter = 0;

	for (int i = 0; i < prev; i++)
		arr->sortedDatas[counter++] = 0;

	for (int i = 1; i < arr->max + 1; i++)
	{
		prev = arr->countDatas[i - 1];
		cur = arr->countDatas[i];
		if (cur - prev > 0)
		{
			for (int j = 0; j < cur - prev; j++)
			{
				arr->sortedDatas[counter++] = i;
			}
		}
	}
}

void printArr()
{
	printf("arr: ");
	for (int i = 0; i < arr->size; i++)
	{
		printf("%d", arr->sortedDatas[i]);
		if (i == arr->size - 1)
			printf("\n");
		else
			printf(", ");
	}
}

void clear()
{
	free(arr->countDatas);
	free(arr->originalDatas);
	free(arr->sortedDatas);
	free(arr);
}