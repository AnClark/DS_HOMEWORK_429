// Looping linked list
#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int data;
	struct node *next;
} node;


struct node *createLinkedList()
{
	struct node *head, *p, *f;
	int d;

	// Create header
	head = malloc(sizeof(node));
	f = malloc(sizeof(node));

	head->next = f;
	p = head->next;

	// Input the main part of the linked list
	puts("Input numbers you want to construct this list. 0 for EOL:");
	while (scanf("%d", &d) && d != 0)
	{
		f = malloc(sizeof(node));
		f->data = d;
		p->next = f;
		p = p->next;
	}

	// Link the final node to head.
	// So we can make it loop.
	p->next = head->next;

	return head;

}

int countLoopedLinkedListNodes(struct node *head)
{
	struct node *p, *first;
	int count = 0;

	first = head->next;
	p = first->next;

	while (p != first)
	{
		count++;
		p = p->next;
	}

	return count;
}

int main()
{
	struct node *head;

	puts("Now input linked list nodes.");
	head = createLinkedList();

	puts("Let's count how many nodes in your list.");
	printf("\tCount: %d\n", countLoopedLinkedListNodes(head));
}

