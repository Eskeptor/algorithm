#include <stdio.h>

int search(int _data[], int _begin, int _end, int _value)
{
	if (_begin > _end)
		return -1;
	else if (_data[_begin] == _value)
		return _begin;
	else
		return search(_data, _begin + 1, _end, _value);
}

int main(void)
{
	int arr[] = { 1, 7, 99, 12, 6, 54, 12, 31 ,20, 41, 2 };
	const int VALUE = 31;
	printf("%dÀÇ À§Ä¡: %d\n", VALUE, search(arr, 0, sizeof(arr) / sizeof(int), VALUE));
	return 0;
}