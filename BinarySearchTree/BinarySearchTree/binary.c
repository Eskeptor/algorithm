#include "binary.h"

typedef struct _NODE
{
	struct _NODE* right;
	struct _NODE* left;
	int data;
}Node;

typedef struct _TREE
{
	Node* start;
	int count;
}Tree;

Tree* tree;

void createTree()
{
	if (tree != NULL)
		clear();
	tree = (Tree*)malloc(sizeof(Tree));
	tree->start = NULL;
	tree->count = 0;
}
void insert(const int _data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = _data;
	newNode->left = NULL;
	newNode->right = NULL;

	if (tree->start == NULL)
	{
		tree->start = newNode;
	}
	else
	{
		Node* cur = tree->start;
		Node* prev;
		int direction = 0;
		while (cur != NULL)
		{
			if (cur->data > _data)
			{
				prev = cur;
				cur = cur->left;
				direction = LEFT;
			}
			else if (cur->data < _data)
			{
				prev = cur;
				cur = cur->right;
				direction = RIGHT;
			}
			else
			{
				printf("에러: 동일한 값이 있습니다.\n");
				direction = 0;
				return;
			}
		}

		if (direction == LEFT)
		{
			prev->left = newNode;
		}
		else
		{
			prev->right = newNode;
		}
	}
}
Node* search(const int _data)
{
	Node* cur = tree->start;
	Node* prev;
	while (cur != NULL)
	{
		if (cur->data > _data)
		{
			prev = cur;
			cur = cur->left;
		}
		else if (cur->data < _data)
		{
			prev = cur;
			cur = cur->right;
		}
		else
		{
			return cur;
		}
	}
	printf("에러: 값이 없습니다.\n");
	return NULL;
}
int remove(const int _data)
{
	Node* parent = search(_data);

	if (parent == NULL)
	{
		printf("찾는 값이 없습니다.\n");
		return 0;
	}

	Node* childRight = parent->right;
	Node* childLeft = parent->left;
	if (childLeft != NULL && childRight != NULL)
	{
		Node* cur = parent;
		Node* prev;
		while (cur != NULL)
		{
			if (cur->right != NULL)
			{
				int tmp = cur->right->data;
				cur->data = tmp;
				prev = cur;
				cur = cur->right;
			}
			else
			{
				prev->right = NULL;
				free(cur);
				break;
			}
		}
	}
	else if (childLeft != NULL || childRight != NULL)
	{
		Node* del = parent;
		if (childLeft != NULL)
		{
			parent = childLeft;
		}
		else
		{
			parent = childRight;
		}
		free(del);
	}
	else
	{
		free(parent);
	}
}
void print(const Node* _node)
{
	if (_node != NULL)
	{
		if (_node->left != NULL && _node->right != NULL)
		{
			printf("%-5d  |", _node->left->data);
			printf("%-5d|", _node->data);
			printf("%-5d\n", _node->right->data);
		}
		else if (_node->left != NULL)
		{
			printf("%-5d  |", _node->left->data);
			printf("%-5d|", _node->data);
			printf("\n");
		}
		else if (_node->right != NULL)
		{
			printf("       |");
			printf("%-5d|", _node->data);
			printf("%-5d\n", _node->right->data);
		}
		print(_node->left);
		print(_node->right);
	}
}
void printTree()
{
	print(tree->start);
	printf("\n");
}
void clearTree(Node* _node)
{
	if (_node != NULL)
	{
		clearTree(_node->left);
		clearTree(_node->right);
		free(_node);
	}
}
void clear()
{
	clearTree(tree->start);
	free(tree);
}