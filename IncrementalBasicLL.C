// Incremental Basic Linkedlist
#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int data;
	struct node *next;
} node;


int main()
{
	struct node *head, *p, *f;
	int d;

	// Initialize linked list first
	// NOTICE: This Linkedlist has leading node.
	head = malloc(sizeof(node));
	// create and link leading node
	f = malloc(sizeof(node));
	f->next = NULL;
	head->next = f;

	puts("Now input number you want to add to linked list. 0 for EOL.");
	while (scanf("%d", &d) && d != 0)
	{
		// Find out a suitable point
		p = head->next;
		while (p->next != NULL && p->next->data <= d)
			p = p->next;

		// Then insert
		f = malloc(sizeof(node));
		f->data = d;
		f->next = p->next;
		p->next = f;
	}

	// Print out linked list
	puts("----------- Final list is: -----------");
	// NOTICE: head->next is the leading node.
	p = head->next->next;
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
}
