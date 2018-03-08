#include <stdio.h>
#define NOT -1

int search(int _arr[], int _begin, int _end, int _value)
{
	if (_begin > _end)
		return NOT;

	int middle = (_begin + _end) / 2;
	if (_arr[middle] == _value)
		return middle;
	else if (_arr[middle] > _value)
		return search(_arr, _begin, middle - 1, _value);
	else
		return search(_arr, middle + 1, _end, _value);
}

int main(void)
{
	int arr[] = { 1, 5, 6, 8, 12, 16, 22, 30, 35 };
	const int VALUE = 12;
	printf("%dÀÇ À§Ä¡: %d\n", VALUE, search(arr, 0, sizeof(arr) / sizeof(int), VALUE));
	return 0;
}