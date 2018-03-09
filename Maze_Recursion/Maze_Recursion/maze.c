#include <Windows.h>
#include <stdio.h>
#include "maze.h"

int MAZE2[MAX][MAX] =
{
{ 0,0,0,0,0,0,0,1 },
{ 0,1,1,0,1,1,0,1 },
{ 0,0,0,1,0,0,0,1 },
{ 0,1,0,0,1,1,0,0 },
{ 0,1,1,1,0,0,1,1 },
{ 0,1,0,0,0,1,0,1 },
{ 0,0,0,1,0,0,0,1 },
{ 0,1,1,1,0,1,0,0 }
};

int MAZE[MAX][MAX] =
{
{ 0,0,0,0,0,0,0,1 },
{ 0,1,1,0,1,1,0,1 },
{ 0,0,0,1,0,0,0,1 },
{ 0,1,0,0,1,1,0,0 },
{ 0,1,1,1,0,0,0,1 },
{ 0,1,0,1,0,1,1,1 },
{ 0,0,0,1,0,0,0,1 },
{ 1,1,1,1,0,1,0,0 }
};


BOOL findPath(const int _x, const int _y)
{
	if (_x == MAX - 1 && _y == MAX - 1)
	{
		MAZE[_y][_x] = GO;
		return TRUE;
	}
	else if (_x >= MAX || _y >= MAX || _x < 0 || _y < 0)
		return FALSE;
	else if (MAZE[_y][_x] == PATH)
	{
		MAZE[_y][_x] = GO;
		if (findPath(_x, _y + 1) || findPath(_x, _y - 1) || findPath(_x + 1, _y) || findPath(_x - 1, _y))
		{
			return TRUE;
		} 
		else
		{
			MAZE[_y][_x] = TRACE;
		}
	}
	
	return FALSE;
}

void printPath()
{
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hc, &csbi);

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			switch (MAZE[i][j])
			{
			case GO:
				SetConsoleTextAttribute(hc, 12);
				printf("бр");
				break;
			case PATH: case TRACE:
				SetConsoleTextAttribute(hc, 7);
				printf("бр");
				break;
			case WALL:
				SetConsoleTextAttribute(hc, 7);
				printf("бс");
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
	printf("\n\n\n");
}