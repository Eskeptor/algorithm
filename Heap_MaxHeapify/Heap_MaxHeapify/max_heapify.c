#include "max_heapify.h"


// n의 자식은
// 왼: 2n
// 오: 2n + 1
void maxHeapify(int _arr[], const int _idx, const int _length)
{
	int idx = _idx;
	while (idx > 1 && idx < _length)
	{
		if (_arr[idx] > _arr[idx / 2])
		{
			int tmp = _arr[idx];
			_arr[idx] = _arr[idx / 2];
			_arr[idx / 2] = tmp;
			idx /= 2;
		}
		else
		{
			if (idx * 2 <= _length) 
			{
				if (_arr[idx] < _arr[idx * 2])
				{
					int tmp = _arr[idx];
					_arr[idx] = _arr[idx * 2];
					_arr[idx * 2] = tmp;
					idx *= 2;
				}
				else if (_arr[idx] < _arr[idx * 2 + 1])
				{
					int tmp = _arr[idx];
					_arr[idx] = _arr[idx * 2 + 1];
					_arr[idx * 2 + 1] = tmp;
					idx = idx * 2 + 1;
				}
			}
			else
				break;
		}
	}
}

void printArr(const int _arr[], const int _length)
{
	printf("arr: ");
	for (int i = 1; i < _length; i++)
	{
		printf("%d", _arr[i]);
		if (i == _length - 1)
			printf("\n");
		else
			printf(", ");
	}
}