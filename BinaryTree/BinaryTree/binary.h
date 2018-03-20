#pragma once
#include <stdio.h>
#include <stdlib.h>
#define BOOL int
#define TRUE 1
#define FALSE 0

#define RIGHT 1
#define LEFT -1

#define PREORDER 1
#define INORDER 2
#define POSTORDER 3

typedef struct _NODE Node;

BOOL isEmpty();
void createTree();
void insertNode(const int _data);
int deleteNode(const int _data);
void print(const int _sel);
void printTree(const int _sel, const Node* _node);
void dispose(Node* _node);
void clear();
