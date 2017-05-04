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


void printLinkedList(struct node *head)
{
	struct node *p, *first;
	first = head->next;
	p = first->next;

	puts("----------- LINKED LIST IS -----------");
	while (p != first)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	puts("\n---------------------------------");
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


void removeNodeByPosition(struct node *head, int position)
{
	struct node *p, *first, *q;
	int i = 1;

	// NOTICE: Position starts from 1 here.
	// Check if input position value invalid
	int len = countLoopedLinkedListNodes(head);
	if (position < 0 || position > len)
	{
		puts("*** FATAL: Invalid position! ***");
		return;
	}

	// Initialize
	first = head->next;
	p = first;

	// Find out the target node
	while (p->next != first && i < position)
	{
		p = p->next;
		i++;
	}

	// Remove
	q = p->next;
	p->next = q->next;
	free(q);

}


void insertNodeBeforePosition(struct node *head, int position, int data)
{
	struct node *p, *first, *f;
	int i = 1;

	// Check if position value invalid
	int len = countLoopedLinkedListNodes(head);
	if (position < 0 || position > len)
	{
		puts("*** FATAL: Invalid position! ***");
		return;
	}

	// Initialize
	first = head->next;
	p = first;

	// Find out somewhere to insert
	while (p->next != first && i < position)
	{
		p = p->next;
		i++;
	}

	// Now let's insert
	f = malloc(sizeof(node));
	f->data = data;

	f->next = p->next;
	p->next = f;
}


// #define TEST_REMOVE_BY_POSITION
#define TEST_INSERT_BEFORE_POSITION
int main()
{
	struct node *head;

	puts("Now input linked list nodes.");
	head = createLinkedList();

	puts("Now print out what you have constructed.");
	printLinkedList(head);

	puts("Let's count how many nodes in your list.");
	printf("\tCount: %d\n", countLoopedLinkedListNodes(head));


#ifdef TEST_REMOVE_BY_POSITION
	int p;
	puts("\nNow test removing nodes by position. Position starts from 1. 0 for EOL.");
	while (scanf("%d", &p) && p != 0)
	{
		if (countLoopedLinkedListNodes(head) <= 0)
		{
			puts("--- Linked list is empty now ---");
			break;
		}

		removeNodeByPosition(head, p);
		printLinkedList(head);
	}
#endif


#ifdef TEST_INSERT_BEFORE_POSITION
	int p, d;
	puts("\nNow test inserting nodes before position. Position starts from 1; 0 for EOL.");
	while (scanf("%d%d", &p, &d) && p != 0)
	{
		insertNodeBeforePosition(head, p, d);
		printLinkedList(head);
	}
#endif
}

