#include "insertion.h"

void insertionSort(int _arr[], int _length)
{
	int cur, tmp;

	for (int i = 1; i < _length; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (_arr[i] < _arr[j])
			{
				cur = _arr[i];
				for (int k = i; k >= j; k--)
				{
					_arr[k] = _arr[k - 1];
				}
				_arr[j] = cur;
				break;
			}
		}
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