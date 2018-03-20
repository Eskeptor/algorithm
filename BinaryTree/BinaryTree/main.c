#include "binary.h"

int main(void)
{
	int arr[] = { 10,6,15,5,9,14,25,3,19 };
	createTree();
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		insertNode(arr[i]);
	print(PREORDER);
	print(INORDER);
	print(POSTORDER);
	return 0;
}