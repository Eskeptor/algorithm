#include "insertion.h"

int main(void)
{
	int arr[] = { 5, 9, 65, 1, 3, 45, 81, 99, 12, 33 };
	int length = sizeof(arr) / sizeof(int);
	printArr(arr, length);
	insertionSort(arr, length);
	printArr(arr, length);

	return 0;
}