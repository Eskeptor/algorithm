#include "priority_queue.h"

int main(void)
{
	int arr[] = { 20,10,15,8,7,13,14,2,5,6 };
	int arrSize = sizeof(arr) / sizeof(int);

	createQueue(20);
	for (int i = 0; i < arrSize; i++)
		insertData(arr[i]);
	heapSort();
	printQueue();
	insertData(15);
	printQueue();
	heapSort();
	printQueue();

	clear();
	return 0;
}
