#pragma once
#include <stdio.h>
#include <stdlib.h>
#define BOOL int
#define TRUE 1
#define FALSE 0

void createQueue();
void enqueue(const int _data);
int dequeue();
int getSize();
BOOL isEmpty();
void printQueue();
void clear();