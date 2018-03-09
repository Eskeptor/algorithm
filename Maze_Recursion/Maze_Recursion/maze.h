#pragma once

#define TRACE 3
#define GO 2
#define WALL 1
#define PATH 0

#define BOOL int
#define TRUE 1
#define FALSE 0

#define MAX 8

BOOL findPath(const int _x, const int _y);

void printPath();