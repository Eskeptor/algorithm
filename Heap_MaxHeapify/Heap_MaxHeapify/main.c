#include "max_heapify.h"

int main(void)
{
	// �迭�� 0��°�� �ʿ�����Ƿ� -1�� �ʱ�ȭ
	int arr[] = { -1,16,4,10,14,7,9,3,2,8,1 };
	//int arr[] = { -1, 4, 16, 15, 8, 7, 13, 14, 2, 5 };
	int idx = 2;

	printArr(arr, sizeof(arr) / sizeof(int));
	maxHeapify(arr, idx, sizeof(arr) / sizeof(int));
	printArr(arr, sizeof(arr) / sizeof(int));

	return 0;
}