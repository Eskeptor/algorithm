#include "max_heapify.h"

int main(void)
{
	// 배열의 0번째는 필요없으므로 -1로 초기화
	//int arr[] = { -1,16,4,10,14,7,9,3,2,8,1 };
	int arr[] = { -1,16,14,10,22,8,9,3,2,4,1 };
	int idx = 4;

	printArr(arr, sizeof(arr) / sizeof(int));
	maxHeapify(arr, idx, sizeof(arr) / sizeof(int));
	printArr(arr, sizeof(arr) / sizeof(int));

	return 0;
}