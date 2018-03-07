#include "LinkedList.h"

int main(void)
{
	LinkedList<int> linked;
	if (linked.IsEmpty())
	{
		printf("리스트가 비어있음\n");
	}
	linked.insert(5);
	linked.insert(3);
	linked.insert(2);
	linked.insert(11);
	linked.Print();

	printf("remove: %d\n", linked.remove(2));
	linked.Print();

	linked.insert(25, 2);
	linked.Print();

	return 0;
}