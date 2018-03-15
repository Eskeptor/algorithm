#include "selection.h"

void selectionSort(int _arr[], int _length)
{
	int max, idx = 0, tmp;
	for (int i = _length - 1; i >= 0; i--)
	{
		max = _arr[0];
		idx = 0;
		for (int j = 0; j <= i; j++)
		{
			if (max < _arr[j])
			{
				max = _arr[j];
				idx = j;
			}
		}
		tmp = _arr[idx];
		_arr[idx] = _arr[i];
		_arr[i] = tmp;
	}
}

void printArr(int _arr[], int _length)
{
	printf("arr: ");
	for (int i = 0; i < _length; i++)
	{
		printf("%d", _arr[i]);
		if (i == _length - 1)
			printf("\n");
		else
			printf(", ");
	}
}