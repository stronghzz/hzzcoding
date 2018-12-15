#pragma once


typedef int QDataType;

// 用单链表实现队列

// 链表的结点
typedef struct QNode {
	QDataType val;
	struct QNode *next;
}	QNode;

// 队列
typedef struct Queue {
	QNode *front;	// 指向链表的第一个结点，如果链表为空， == NULL
	QNode *rear;	// 指向链表的最后一个结点，如果链表为空， == NULL
	int size;		// 表示队列中数据个数
}	Queue;

// 初始化/销毁
void QueueInit(Queue *queue) {
	queue->front = queue->rear = NULL;
	queue->size = 0;
}

void QueueDestroy(Queue *queue) {
	QNode *next;
	for (QNode *cur = queue->front; cur != NULL; cur = next) {
		next = cur->next;
		free(cur);
	}

	queue->front = queue->rear = NULL;
	queue->size = 0;
}

// 增删改查
void QueuePush(Queue *queue, QDataType val) {
	// 申请结点
	QNode *node = (QNode *)malloc(sizeof(QNode));
	assert(node);
	node->val = val;
	node->next = NULL;
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

	QNode *old_front = queue->front;
	queue->front = queue->front->next;
	free(old_front);

	if (queue->front == NULL) {
		queue->rear = NULL;
	}
}

QDataType QueueFront(const Queue *queue) {
	assert(queue->size > 0);

	return queue->front->val;
}

// 空 / size
int QueueEmpty(const Queue *queue) {
	return queue->size == 0 ? 1 : 0;
}

int QueueSize(const Queue *queue) {
	return queue->size;
}