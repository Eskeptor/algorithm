#include "queue.h"

typedef struct _NODE
{
	struct _NODE* next;
	int data;
}Node;

typedef struct _QUEUE
{
	Node* front;
	Node* rear;
	int count;
}Queue;

Queue *queue;

void createQueue()
{
	queue = (Queue*)malloc(sizeof(Queue));
	queue->front = NULL;
	queue->rear = NULL;
	queue->count = 0;
}

BOOL isEmpty()
{
	return queue->front == NULL;
}

void enqueue(const int _data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = _data;

	if (isEmpty(queue))
	{
		queue->front = newNode;
		queue->rear = newNode;
	}
	else
	{
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
	queue->count++;
}

int dequeue()
{
	if (isEmpty(queue))
	{
		printf("큐가 비었음\n");
		return 0;
	}
	else
	{
		Node* deNode = queue->front;
		int delData = deNode->data;

		queue->front = queue->front->next;
		free(deNode);
		queue->count--;
		return delData;
	}
}

int getSize()
{
	return queue->count;
}

void printQueue()
{
	Node* node = queue->front;
	printf("queue: ");
	while (1)
	{
		printf("%d", node->data);
		node = node->next;
		if (node == NULL)
		{
			printf("\n");
			break;
		}
		else
		{
			printf(", ");
		}
	}
}

void clear()
{
	if (isEmpty(queue))
	{
		printf("큐가 비었음\n");
		return;
	}
	else
	{
		while (1)
		{
			Node* node = queue->front;
			if (node == NULL)
				break;
			queue->front = queue->front->next;
			free(node);
		}
	}
	free(queue);
}