#include "bubble.h"

void bubbleSort(int arr[], int _length)
{
	int temp;
	for (int i = 0; i < _length; i++)
	{
		for (int j = 0; j < _length - i; j++)
		{
			if (j + 1 < _length && arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void printArr(int arr[], int _length)
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