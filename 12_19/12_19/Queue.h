#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int QUDataType;


typedef struct QueueNode
{
	struct QueueNode *next;
	QUDataType data;
}QueueNode;
typedef struct	Queue
{
	QueueNode *front;
	QueueNode *rear;
	int size;
}Queue;

void QueueInit(Queue *queue)
{
	queue->front = queue->rear = NULL;
	queue->size = 0;
}
void QueueDestory(Queue *queue)
{
	QueueNode*next;
	for (QueueNode *cur = queue->front; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	queue->front = queue->rear = NULL;
	queue->size = 0;
}
QueueNode *BuyQueueNode(QUDataType val)
{
	QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
	assert(node);
	node->data = val;
	node->next = NULL;
	return node;
}
void QueuePush(Queue *queue, QUDataType val) {
	// ÉêÇë½áµã
	QueueNode *node = BuyQueueNode(val);
	assert(node);
	queue->size++;

	if (queue->rear == NULL) {
		queue->front = queue->rear = node;
	}
	else {
		queue->rear->next = node;
		queue->rear = node;
	}
}

void QueuePop(Queue *queue) {
	assert(queue->size > 0);
	queue->size--;

	QueueNode *old_front = queue->front;
	queue->front = queue->front->next;
	free(old_front);

	if (queue->front == NULL) {
		queue->rear = NULL;
	}
}

QUDataType QueueFront(const Queue *queue) {
	assert(queue->size > 0);

	return queue->front->data;
}

// ¿Õ / size
int QueueEmpty(const Queue *queue) {
	return queue->size == 0 ? 1 : 0;
}

int QueueSize(const Queue *queue) {
	return queue->size;
}