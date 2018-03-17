#include "quick.h"

int main(void)
{
	int arr[] = { 5, 9, 65, 1, 3, 45, 81, 99, 12, 33 };
	int length = sizeof(arr) / sizeof(int);
	printArr(arr, length);
	quickSort(arr, 0, length - 1);
	printArr(arr, length);

	return 0;
}