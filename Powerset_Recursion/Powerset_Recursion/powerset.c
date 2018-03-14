#include "powerset.h"

typedef struct _TREE_NODE
{
	char data;
	BOOL isInclude;
}Node;

Node datas[MAX] = { {'a', FALSE}, {'b', FALSE}, {'c', FALSE}, {'d', FALSE}, {'e', FALSE}, {'f', FALSE}, {'g', FALSE} };
int count = 0;

void powerset(const int _k)
{
	if (_k == MAX)
	{
		BOOL check = FALSE;
		for (int i = 0; i < MAX; i++)
		{
			if (datas[i].isInclude)
			{
				printf("%c ", datas[i].data);
				check = TRUE;
			}
			if (i == MAX - 1 && check)
			{
				count++;
				check = FALSE;
			}
		}
		printf("\n");
		return;
	}
	datas[_k].isInclude = FALSE;
	powerset(_k + 1);
	datas[_k].isInclude = TRUE;
	powerset(_k + 1);
}

int getCount()
{
	return count;
}