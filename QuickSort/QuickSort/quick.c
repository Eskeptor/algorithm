#include "quick.h"

int partition(int _arr[], const int _begin, const int _end, const int _pivot)
{
	int length = _end - _begin;
	int* rightArr = (int*)malloc(sizeof(int) * length + 1);		// 아무리 길어도 _arr의 배열길이가 n이라면 _pivot이 빠진 n-1을 넘지 않음
	int* leftArr = (int*)malloc(sizeof(int) * length + 1);
	int rightCounter = 0;
	int leftCounter = 0;

	for (int i = _begin; i <= _end; i++)
	{
		if (_arr[i] > _arr[_pivot])
			rightArr[rightCounter++] = _arr[i];
		else if (_arr[i] < _arr[_pivot])
			leftArr[leftCounter++] = _arr[i];
	}

	int tmp = _arr[_pivot];
	for (int i = 0; i < leftCounter; i++)
		_arr[i + _begin] = leftArr[i];
	_arr[leftCounter + _begin] = tmp;
	for (int i = 0; i < rightCounter; i++)
		_arr[i + leftCounter + _begin + 1] = rightArr[i];

	free(rightArr);
	free(leftArr);

	return leftCounter + _begin;
}

void quickSort(int _arr[], const int _begin, const int _end)
{
	if (_begin >= _end)
		return;

	int pivot = (_begin + _end) / 2;
	int point = partition(_arr, _begin, _end, pivot);
	quickSort(_arr, _begin, point - 1);
	quickSort(_arr, point + 1, _end);
}

void printArr(const int _arr[], const int _length)
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