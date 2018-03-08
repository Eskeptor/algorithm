#include <stdio.h>

void binaryPrint(int _num)
{
	if (_num <= 1)
		printf("%d", _num);
	else
	{
		binaryPrint(_num / 2);
		printf("%d", _num % 2);
	}
}

int main(void) {
	int num = 12254;
	printf("%d = ", num);
	binaryPrint(num);
	printf("(2)\n");
	return 0;
}