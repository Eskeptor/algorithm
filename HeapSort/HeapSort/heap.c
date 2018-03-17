#include "heap.h"


// n의 자식은
// 왼: 2n
// 오: 2n + 1
void maxHeapify(int _arr[], const int _idx, const int _length)
{
	int curIdx = _idx;
	while (1)
	{
		int childIdx = curIdx;
		if (curIdx * 2 + 1 < _length)
		{
			if (_arr[curIdx * 2] > _arr[curIdx * 2 + 1])
				childIdx = curIdx * 2;
			else
				childIdx = curIdx * 2 + 1;
		}
		else
		{
			childIdx *= 2;
		}

		if (childIdx >= _length)
			break;

		if (_arr[curIdx] < _arr[childIdx])
		{
			int tmp = _arr[childIdx];
			_arr[childIdx] = _arr[curIdx];
			_arr[curIdx] = tmp;
			curIdx = childIdx;
		}
		else
			break;
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

void heapSort(int _arr[], const int _length)
{
	for (int i = _length - 1; i > 0; i--)
	{
		if (i * 2 <= _length - 1)
			maxHeapify(_arr, i, _length);
	}
}