#include "merge.h"

void mergeSort(int _arr[], const int _begin, const int _end)
{
	int mid = 0;
	if (_begin < _end)
	{
		mid = (_begin + _end) / 2;
		mergeSort(_arr, _begin, mid);
		mergeSort(_arr, mid + 1, _end);
		merge(_arr, _begin, _end);
	}
}

void merge(int arr[], const int _begin, const int _end)
{
	int length = _end - _begin + 1;
	int* tmpArr = (int*)malloc(sizeof(int) * length);
	int leftCounter = _begin;
	int mid = (_begin + _end) / 2;
	int rightCounter = mid + 1;
	
	for (int i = 0; i < length; i++)
	{
		if (arr[leftCounter] < arr[rightCounter])
		{
			if (leftCounter <= mid)
				tmpArr[i] = arr[leftCounter++];
			else
			{
				tmpArr[i] = arr[leftCounter];
				for (int j = i; j < length; j++)
				{
					tmpArr[j] = arr[rightCounter++];
				}
				break;
			}
		}
		else
		{
			if (rightCounter <= _end)
				tmpArr[i] = arr[rightCounter++];
			else
			{
				tmpArr[i] = arr[rightCounter];
				for (int j = i; j < length; j++)
				{
					tmpArr[j] = arr[leftCounter++];
				}
				break;
			}
		}
	}

	for (int i = _begin; i <= _end; i++)
	{
		arr[i] = tmpArr[i - _begin];
	}
	
	free(tmpArr);
}

void printArr(int arr[], const int _length)
{
	printf("arr: ");
	for (int i = 0; i < _length; i++)
	{
		printf("%d", arr[i]);
		if (i == _length - 1)
			printf("\n");
		else
			printf(", ");
	}
}
