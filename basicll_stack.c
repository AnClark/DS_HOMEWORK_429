#include<stdio.h>
#include<malloc.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

struct Node *head;

int main()
{
	struct Node *p, *f;
	int d;

	// Initialize linked list
	// NOTICE: This list has a leading node.
	head = malloc(sizeof(struct Node));
	f = malloc(sizeof(struct Node));
	head->next = f;

	p = head->next;

	// Input first node
	scanf("%d", &d);
	f = malloc(sizeof(struct Node));
	f->data = d;
	f->next = NULL;

	p->next = f;

	// Input the following node. 0 for EOL.
	// My algorithms: insert new node between head and the node following head.
	while (scanf("%d", &d) && d != 0)
	{
		f = malloc(sizeof(struct Node));
		f->data = d;
		f->next = p->next;
		p->next = f;
	}

	// Print out the linked list
	printf("\n====== LINKED LIST ======\n");

	f = p;
	while ((f != NULL) && (f = f->next))
		printf("%d  ", f->data);

	return 0;
}