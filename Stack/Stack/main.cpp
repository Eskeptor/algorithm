#include "stack.h"
#include "stack.cpp"

int main(void)
{
	Stack<int> stack(5);

	if (stack.IsEmpty())
	{
		printf("Stack is empty.\n");
	}
	stack.Push(4);
	stack.Push(2);
	stack.Push(125);
	stack.Print();
	printf("Top: %d\n", stack.Top());
	printf("Pop: %d\n", stack.Pop());
	stack.Print();

	return 0;
}