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

BOOL isEmpty()
{
	return tree->start == NULL;
}
void createTree()
{
	tree = (Tree*)malloc(sizeof(Tree));
	tree->count = 0;
	tree->start = NULL;
}
void insertNode(const int _data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = _data;
	newNode->left = NULL;
	newNode->right = NULL;

	if (isEmpty())
	{
		tree->start = newNode;
		tree->count++;
	}
	else
	{
		Node* search = tree->start;
		Node* prev;
		while (search != NULL)
		{
			if (search->data > _data)
			{
				prev = search;
				search = search->left;
			}
			else if (search->data < _data)
			{
				prev = search;
				search = search->right;
			}
			else
			{
				printf("이미 해당 값이 있습니다.\n");
				return;
			}
		}

		if (prev->data > _data)
			prev->left = newNode;
		else
			prev->right = newNode;
	}
}
int deleteNode(const int _data)
{
	Node* search = tree->start;
	Node* parent;
	int direction = 0;
	while (search != NULL)
	{
		if (search->data > _data)
		{
			parent = search;
			search = search->left;
			direction = LEFT;
		}
		else if (search->data < _data)
		{
			parent = search;
			search = search->right;
			direction = RIGHT;
		}
		else
		{
			break;
		}
	}
	
	if (search == NULL)
	{
		printf("찾는 값이 없습니다.\n");
		return 0;
	}

	Node* childRight = search->right;
	Node* childLeft = search->left;
	if (childLeft != NULL && childRight != NULL)
	{
		// TODO 수정필요
	}
	else if (childLeft != NULL || childRight != NULL)
	{
		if (childLeft != NULL)
		{
			parent->left = childLeft;
		}
		else
		{
			parent->right = childRight;
		}
		free(search);
	}
	else
	{
		if (direction == RIGHT)
		{
			parent->right = NULL;
		}
		else
		{
			parent->left = NULL;
		}
		free(search);
	}
}
void print(const int _sel)
{
	switch (_sel)
	{
	case PREORDER:
		printf("Preorder: ");
		printTree(_sel, tree->start);
		printf("\n");
		break;
	case INORDER:
		printf("Inorder: ");
		printTree(_sel, tree->start);
		printf("\n");
		break;
	case POSTORDER:
		printf("Postorder: ");
		printTree(_sel, tree->start);
		printf("\n");
		break;
	default:
		break;
	}
}
void printTree(const int _sel, const Node* _node)
{
	if (_node != NULL)
	{
		switch (_sel)
		{
		case PREORDER:
			printf("%d ", _node->data);
			printTree(_sel, _node->left);
			printTree(_sel, _node->right);
			break;
		case INORDER:
			printTree(_sel, _node->left);
			printf("%d ", _node->data);
			printTree(_sel, _node->right);
			break;
		case POSTORDER:
			printTree(_sel, _node->left);
			printTree(_sel, _node->right);
			printf("%d ", _node->data);
			break;
		default:
			break;
		}
	}
}
void dispose(Node* _node)
{
	if (_node != NULL)
	{
		dispose(_node->left);
		dispose(_node->right);
		free(_node);
	}
}
void clear()
{
	dispose(tree->start);
	free(tree);
}