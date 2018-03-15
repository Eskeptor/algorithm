#include "bubble.h"

int main(void)
{
	int arr[] = { 5, 9, 65, 1, 3, 45, 81, 99, 12, 33 };
	printArr(arr, sizeof(arr) / sizeof(int));
	bubbleSort(arr, sizeof(arr) / sizeof(int));
	printArr(arr, sizeof(arr) / sizeof(int));

	return 0;
}