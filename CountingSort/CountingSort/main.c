#include "count.h"

int main(void)
{
	int arr[] = { 2,5,3,0,2,3,0,3 };
	int arr2[] = { 5,5,3,4,5,1,0,4,1,3,0,2,4,2,3,0 };
	createArray(arr2, sizeof(arr2) / sizeof(int), 5);
	//createArray(arr, sizeof(arr) / sizeof(int), 5);
	count1();
	count2();
	sort();
	printArr();
	clear();
	return 0;
}