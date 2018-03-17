#include "heap.h"

int main(void)
{
	int arr[] = { -1, 4,1,3,2,16,9,10,14,8,7 };
	int arrLength = sizeof(arr) / sizeof(int);
	printArr(arr, arrLength);
	heapSort(arr, arrLength);
	printArr(arr, arrLength);
	return 0;
}