#include "binary.h"

int main(void)
{
	int arr[] = { 5,3,7,2,4,8 };
	createTree();
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		insert(arr[i]);
	}
	printTree();
	remove(3);
	printTree();
	clear();

	return 0;
}