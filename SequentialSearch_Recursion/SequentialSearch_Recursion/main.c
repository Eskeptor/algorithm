#include <stdio.h>
#define NOT -1

int search1(int _data[], int _begin, int _end, int _value)
{
	if (_begin > _end)
		return NOT;
	else if (_data[_begin] == _value)
		return _begin;
	else
		return search1(_data, _begin + 1, _end, _value);
}

int search2(int _data[], int _begin, int _end, int _value)
{
	if (_begin > _end)
		return NOT;
	else
	{
		int middle = (_begin + _end) / 2;
		if (_data[middle] == _value)
			return middle;
		int idx = search2(_data, _begin, middle - 1, _value);
		if (idx != NOT)
			return idx;
		else
			return search2(_data, middle + 1, _end, _value);
	}
}

int main(void)
{
	int arr[] = { 1, 7, 99, 12, 6, 54, 12, 31 ,20, 41, 2 };
	const int VALUE = 31;
	printf("%d의 위치: %d\n", VALUE, search1(arr, 0, sizeof(arr) / sizeof(int), VALUE));
	printf("%d의 위치: %d\n", VALUE, search2(arr, 0, sizeof(arr) / sizeof(int), VALUE));
	return 0;
}