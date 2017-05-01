// Merge two incremental linked lists.
// REQUIREMENTS: Try not to depend on a third linked list.
#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int data;
	struct node *next;
} node;


void printLinkedList(struct node *head)
{
	struct node *p;
	// Print out linked list
	puts("----------- Linked list is: -----------");
	// NOTICE: head->next is the leading node.
	p = head->next->next;
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
}

struct node *createLinkedList()
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
	return head;
}



struct node *mergeIncrementals(struct node *list1, struct node *list2)
{
	// NOTICE: The two will be merged into list1.

	struct node *p, *q, *f, *t;
	// head->next is the leading node.
	p = list1->next;
	q = list2->next;

	while (p != NULL)
	{
		while (q != NULL && (q->next->data > p->data))
		{
			f = malloc(sizeof(node));
			f->data = q->next->data;
			f->next = p->next;
			p->next = f;

			t = q->next;
			q->next = t->next;
			free(t);

			q = q->next;
		}

		p = p->next->next;
	}

	return list1;
}

int main()
{
	struct node *head1, *head2, *head_result;


	// Create two incremental linked lists
	puts("Input list1:");
	head1 = createLinkedList();
	puts("Input list2:");
	head2 = createLinkedList();

	// Merge them
	head_result = mergeIncrementals(head1, head2);

	// Print out result
	puts("----------- RESULT -----------");
	printLinkedList(head_result);
}