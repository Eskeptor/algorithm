#include "priority_queue.h"

typedef struct _ARRAY_QUEUE
{
	int* datas;
	int max;
	int front;
	int rear;
	int count;
}ArrayQueue;

ArrayQueue* queue;

void createQueue(const int _size)
{
	if (queue != NULL)
		free(queue);
	queue = (ArrayQueue*)malloc(sizeof(ArrayQueue));
	queue->datas = (int*)malloc(sizeof(int) * _size);
	queue->max = _size + 1;
	queue->front = 0;
	queue->rear = 0;
	queue->count = 0;
}

BOOL isEmpty()
{
	return queue->front == 0;
}

BOOL isFull()
{
	return queue->count == queue->max - 1;
}

// nÀÇ ÀÚ½ÄÀº
// ¿Þ: 2n
// ¿À: 2n + 1
void maxHeapify(const int _idx, const int _length)
{
	int curIdx = _idx;
	while (1)
	{
		int childIdx = curIdx;
		if (curIdx * 2 + 1 < _length)
		{
			if (queue->datas[curIdx * 2] > queue->datas[curIdx * 2 + 1])
				childIdx = curIdx * 2;
			else
				childIdx = curIdx * 2 + 1;
		}
		else
		{
			childIdx *= 2;
		}

		if (childIdx >= _length)
			break;

		if (queue->datas[curIdx] < queue->datas[childIdx])
		{
			int tmp = queue->datas[childIdx];
			queue->datas[childIdx] = queue->datas[curIdx];
			queue->datas[curIdx] = tmp;
			curIdx = childIdx;
		}
		else
			break;
	}
}

void printQueue()
{
	printf("arr: ");
	for (int i = 1; i <= queue->count; i++)
	{
		printf("%d", queue->datas[i]);
		if (i == queue->count)
			printf("\n");
		else
			printf(", ");
	}
}

void buildMaxHeap(const int _length)
{
	for (int i = (_length - 1) / 2; i > 0; i--)
	{
		maxHeapify(i, _length);
	}
}

void heapSort()
{
	int originalLength = queue->count;
	int length = queue->count;
	buildMaxHeap(length);

	for (int i = 0; i < originalLength - 1; i++)
	{
		int tmp = queue->datas[1];
		queue->datas[1] = queue->datas[length];
		queue->datas[length] = tmp;
		buildMaxHeap(--length);
	}
}

void insertData(const int _data)
{
	if (isFull() && queue->count + 1 >= queue->max)
	{
		printf("Å¥°¡ ²ËÂü\n");
		return;
	}

	queue->datas[++queue->count] = _data;
	if (isEmpty())
	{
		queue->front = queue->count;
	}
	queue->rear = queue->count;
}

int removeData()
{
	if (isEmpty())
	{
		printf("Å¥°¡ ºö\n");
		return 0;
	}

	int delData = queue->datas[queue->count--];
	queue->rear = queue->count;
	return delData;
}

void clear()
{
	free(queue->datas);
	free(queue);
}