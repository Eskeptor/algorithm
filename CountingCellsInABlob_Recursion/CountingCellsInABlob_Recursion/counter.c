#include "counter.h"
#include <stdio.h>
#include <Windows.h>

int Cell[MAX][MAX] =
{
{ 1,0,0,0,0,0,0,1 },
{ 0,1,1,0,0,1,0,0 },
{ 1,1,0,0,1,0,1,0 },
{ 0,0,0,0,0,1,0,0 },
{ 0,1,0,1,0,1,0,0 },
{ 0,1,0,1,0,1,0,0 },
{ 1,0,0,0,1,0,0,1 },
{ 0,1,1,0,0,1,1,1 }
};

int count = 0;

int findCell(const int _x, const int _y)
{
	if (_x < 0 || _y < 0 || _x >= MAX || _y >= MAX || Cell[_y][_x] == SELECT)
		return 0;
	else if (Cell[_y][_x] == BLOCK)
	{
		Cell[_y][_x] = SELECT;
		count++;
		if (findCell(_x, _y + 1) || findCell(_x, _y - 1) || findCell(_x + 1, _y) || findCell(_x - 1, _y) ||
			findCell(_x - 1, _y - 1) || findCell(_x + 1, _y - 1) || findCell(_x - 1, _y + 1) || findCell(_x + 1, _y + 1))
		{
			return 1;
		}
	}
	return 0;
}

void countingCellsInABlob(const int _x, const int _y)
{
	findCell(_x, _y);
	printf("(%d, %d)로 시작되는 블랍의 셀 개수: %d\n", _x, _y, count);
}

void printCell()
{
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hc, &csbi);
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			switch (Cell[i][j])
			{
			case NONE:
				SetConsoleTextAttribute(hc, 7);
				printf("□");
				break;
			case BLOCK:
				SetConsoleTextAttribute(hc, 7);
				printf("■");
				break;
			case SELECT:
				SetConsoleTextAttribute(hc, 12);
				printf("■");
				break;
			}
			SetConsoleTextAttribute(hc, 7);
		}
		printf("\n");
	}
	printf("\n\n");
}