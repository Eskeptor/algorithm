#include "queue.h"

int main(void)
{
	int arr[] = { 20,10,15,8,7,13,14,2,5,6,15 };
	int arrSize = sizeof(arr) / sizeof(int);

	createQueue();
	for (int i = 0; i < arrSize; i++)
		enqueue(arr[i]);

	printQueue();
	clear();

	return 0;
}