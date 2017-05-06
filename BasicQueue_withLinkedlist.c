// Queue with linked list
/** NOTICE: Compared with other data structures, LinkedQueue has no separate head pointer.
Instead, its *front pointer points to leading node directly.
**/
#include<stdio.h>
#include<malloc.h>

typedef struct QNode
{
	int data;
	struct QNode *next;
} QNode;

typedef struct LinkedQueue
{
	QNode *front;
	QNode *rear;
} LinkedQueue;


struct LinkedQueue *initQueue()
{
	struct LinkedQueue *Q;
	Q = malloc(sizeof(LinkedQueue));
	// struct LinkedQueue queue;
	Q->front = malloc(sizeof(QNode));
	Q->rear = Q->front;

	return Q;
}

void printQueue(LinkedQueue * Q)
{
	struct QNode *p = Q->front->next;

	puts("----------- Your queue is: -----------");
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	puts("\n---------------------------------");
}

void enQueue(LinkedQueue * Q, int data)
{
	struct QNode *f;

	f = malloc(sizeof(QNode));
	f->data = data;
	f->next = NULL;

	Q->rear->next = f;
	Q->rear = f;
}

int deQueue(LinkedQueue * queue)
{

}

int main()
{
	struct LinkedQueue *Q;
	Q = initQueue();

	int d;
	while (scanf("%d", &d) && d != 0)
	{
		enQueue(Q, d);
		printQueue(Q);
	}
}