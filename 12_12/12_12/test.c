

#include<stdlib.h>



// 利用 size 和 capacity 来判断满/空的情况
typedef struct {
	int *array;
	int capacity;
	int size;
	int front;  // 队首元素所在的下标
	int rear;   // 下一个可用空间的下标
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue * obj = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
	obj->array = (int *)malloc(sizeof(int)* k);
	obj->capacity = k;
	obj->size = 0;
	obj->front = 0;
	obj->rear = 0;

	return obj;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (obj->size == obj->capacity) {
		return false;
	}

	obj->array[obj->rear] = value;
	obj->size++;
	obj->rear = (obj->rear + 1) % obj->capacity;

	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (obj->size == 0) {
		return false;
	}

	obj->size--;
	obj->front = (obj->front + 1) % obj->capacity;

	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (obj->size == 0) {
		return -1;
	}

	return obj->array[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (obj->size == 0) {
		return -1;
	}

	// 这里是重点
	return obj->array[(obj->rear + obj->capacity - 1) % obj->capacity];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->size == 0;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return obj->size == obj->capacity;
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->array);
	free(obj);
}

int main()
{
	return 0
}