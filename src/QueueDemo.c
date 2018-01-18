/*
 ============================================================================
 Name        : QueueDemo.c
 Author      : Adam
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct items ITEM;
/**
 * Data node
 */
struct items {
	int data;
	ITEM *next;
};

/**
 * Queue container
 */
typedef struct queue {
	int size;
	ITEM *front;
	ITEM *back;
}QUEUE;

/**
 * initial queue
 */
void initQueue(QUEUE *q)
{
	q->size = 0;
	q->front = q->back = NULL;
}

/**
 * Check whether the data in queue
 */
int isQueueEmpty(QUEUE *q)
{
	return q->front == NULL;
}

/**
 * The size of the queue
 */
int QueueSize(QUEUE *q)
{
	return q->size;
}

/**
 * Put data in Queue
 */
void enQueue(QUEUE *q, int value)
{
	ITEM *new  =  (ITEM*)malloc(sizeof(ITEM));
	new->data = value;
	new->next = NULL;
	if(q->front == NULL) {
		q->front = new;
	}
	else {
		q->back->next = new;
	}

	q->back = new;
    q->size++;
}

/**
 * Get data from queue
 */
int deQueue(QUEUE *q)
{
	ITEM *now = q->front;
	int d =  now->data;
	q->front = now->next;
	if(q->front == NULL)
		q->back = NULL;
    q->size--;
    free(now);
	return d;
}

/**
 * main function
 */
int main(void)
{
	int i;
	QUEUE q;
	initQueue(&q);

	for(i = 0; i < 10; i++) {
		printf(" en queue i = %d\n", i);
		enQueue(&q, i);
	}
	printf("=======================\n");
	while(!isQueueEmpty(&q)) {
		printf("dequeue = %d\n", deQueue(&q));
	}

	return EXIT_SUCCESS;
}
