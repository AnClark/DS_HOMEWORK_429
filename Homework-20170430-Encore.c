// Data structure homework 2017-4-30 ENCORE
// Try to remove all the repeating nodes with same absolution in a linked
// list.
// IMPROVED with a classmate's bucket method --- win time with space.
// REQUIREMENT: Know the max value possible to insert. Max value is defined by 
// 
// macro.

#include<stdio.h>
#include<malloc.h>
#include<math.h>

// Define max input value
#define MAX_VALUE 999999

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


void Homework430_Bucket(struct node *head)
{
	int bucket[MAX_VALUE] = { 0 };

	struct node *p, *q;
	int currData;

	p = head->next;

	// Loop: Pick a number
	while ((p->next != NULL))
	{
		// Bucket level 1
		currData = p->next->data;
		bucket[abs(currData)]++;

		// Bucket level 2
		if (bucket[abs(currData)] > 1)
		{
			q = p->next;
			p->next = q->next;
			free(q);

            
		}

       
	}
}

int main()
{
	struct node *head;
	head = createLinkedList();

	puts("----------- ENCORE VERSION -----------");
	puts("########### Before Process ###########");
	printLinkedList(head);

	puts("\n");
	puts("########### After Process ###########");
	Homework430_Bucket(head);
	printLinkedList(head);

}