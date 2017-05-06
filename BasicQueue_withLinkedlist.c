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

void deQueue(LinkedQueue * Q, int &out)
{
	struct QNode *p;

	if (Q->front == Q->rear)
	{
		puts("*** NOTICE: LinkedQueue is empty now! ***");
		*out = 0;
		return;
	}

	p = Q->front->next;
	*out = p->data;

	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;

	free(p);
}

int main()
{
	struct LinkedQueue *Q;
	Q = initQueue();

	int d, out;
	char cmd;

	puts("Usage: <command> [<value>]");
	puts("\tCommand list:");
	puts("\te <value>\tEnqueue");
	puts("\td \t\tDequeue");
	puts("\tq \t\tExit");

	while (scanf("%c", &cmd))
	{
		switch (cmd)
		{
		case 'e':
			scanf("%d", &d);
			enQueue(Q, d);
			printQueue(Q);
			break;
		case 'd':
			deQueue(Q, out);
			if (out)
				printf("Dequeued value:\t%d\n", out);
			else
				printf("No value dequeued\n");
			break;
		case 'q':
			break;
		default:
			puts("*** ERROR: Invalid command! ***");
			break;
		}

	}

	puts("\n----------- FINISHED -----------");
}