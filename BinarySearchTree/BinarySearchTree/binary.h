#pragma once
#include <stdio.h>
#include <stdlib.h>

#define LEFT -1
#define RIGHT 1

typedef struct _NODE Node;

void createTree();
void insert(const int _data);
Node* search(const int _data);
int remove(const int _data);
void print(const Node* _node);
void printTree();
void clearTree(Node* _node);
void clear();