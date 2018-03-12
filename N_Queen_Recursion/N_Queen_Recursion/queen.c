#include "queen.h"
#include <stdio.h>
#include <stdlib.h>

BOOL* arr;
int n = 0;

BOOL isPromissing(const int _level)
{
	for (int i = 1; i < _level; i++)
	{
		if (arr[i] == arr[_level])	// 같은 열인지
		{
			return FALSE;
		}
		else if (abs(i - _level) == abs(arr[i] - arr[_level]))	// 대각선인지
		{
			return FALSE;
		}
	}
	return TRUE;
}

void printQueen(const int _n)
{
	for (int i = 1; i <= _n; i++)
	{
		for (int j = 1; j <= _n; j++)
		{
			if (arr[i] == j)
				printf("■");
			else
				printf("□");
		}
		printf("     arr[%d] = %d", i, arr[i]);
		printf("\n");
	}
	printf("\n");
}

BOOL queenCheck(const int _level)
{
	if (!isPromissing(_level))
	{
		return FALSE;
	}
	else if (_level == n)
	{
		return TRUE;
	}
	for (int i = 1; i <= n; i++)
	{
		arr[_level + 1] = i;
		if (queenCheck(_level + 1))
		{
			return TRUE;
		}
	}

	return FALSE;
}

void queenStart(const int _n)
{
	arr = (BOOL*)malloc(sizeof(BOOL) * (_n + 1));
	n = _n;
	for (int i = 0; i <= _n; i++)
	{
		arr[i] = 0;
	}

	queenCheck(0);
	printQueen(_n);

	free(arr);
	arr = NULL;
}
