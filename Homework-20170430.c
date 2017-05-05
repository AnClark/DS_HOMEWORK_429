// Data structure homework 2017-4-30
// Try to remove all the repeating nodes with same absolution in a linked
// list.
// REQUIREMENT: Use as little time as you can.

#include<stdio.h>
#include<malloc.h>
#include<math.h>

typedef struct node
{
	int data;
	struct node *next;
} node;


struct node *createLinkedList()
{
	struct node *head, *tail, *f;
	int d;

	// Initialize linked list
	// NOTICE: This linked list has leading node.
	head = malloc(sizeof(struct node));
	tail = malloc(sizeof(struct node));
	tail->next = NULL;
	head->next = tail;

	// INTERACTIVE FUNCTION
	// Add nodes. 0 for EOL.
	while (scanf("%d", &d) && d != 0)
	{
		f = malloc(sizeof(struct node));
		f->data = d;
		f->next = NULL;
		tail->next = f;
		tail = f;

	}

	return head;
}

void printLinkedList(struct node *head)
{
	struct node *p;
	p = head->next;

	printf("\n====== Your linked list ======\n");
	while ((p != NULL) && (p = p->next))
		printf("%d  ", p->data);

	puts("\n================================");
}


void Homework430(struct node *head)
{
	struct node *p, *q, *r;
	int currData;

	p = head->next;

	// Loop Level 1: Pick a number
	while ((p != NULL) && (p = p->next))
	{
		currData = p->data;

		// Loop Level 2: Remove numbers with same abs
		q = p;
		while ((q->next != NULL) && (q = q->next))
		{
			if (abs(currData) == abs(q->data))
			{
				r = q->next;
				q->next = r->next;
				free(r);
			}
		}
	}
}

int main()
{
	struct node *head;
	head = createLinkedList();

	puts("########### Before Process ###########");
	printLinkedList(head);

	puts("\n");
	puts("########### After Process ###########");
	Homework430(head);
	printLinkedList(head);

}

