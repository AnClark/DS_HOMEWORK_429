// Bidirection linked list
#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
} node;


struct node *createLinkedList()
{
	struct node *head, *p, *f;
	int d;

	// Create head
	head = malloc(sizeof(node));

	// Create leading node
	f = malloc(sizeof(node));
	f->prev = head;
	head->next = f;

	p = head->next;

	// Create the other nodes
	puts("Input numbers you want to construct a linked list. 0 for EOL.");
	while (scanf("%d", &d) && d != 0)
	{
		f = malloc(sizeof(node));
		f->data = d;
		f->prev = p;
		p->next = f;
		f->next = NULL;

		p = p->next;
	}

	return head;
}

void printLinkedList(struct node *head)
{
	struct node *p;
	p = head->next->next;

	puts("----------- LINKED LIST IS -----------");
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	puts("\n---------------------------------");
}


void removeNodeByData(struct node *head, int data)
{
	// Benefit of using bidirection linked list:
	// You can just use one pointer to remove/insert nodes.

	// Initialize
	struct node *p;
	p = head->next->next;

	// Find out the node we want to remove
	while (p != NULL && p->data != data)
		p = p->next;

	// If not found, give out error msg, then exit
	if (p == NULL)
	{
		puts("*** FATAL: Node not found! ***");
		return;
	}

	// If found, then remove it
	// NOTICE: Must handle removing the last node properly!
	p->prev->next = p->next;
	if (p->next)
		p->next->prev = p->prev;
	free(p);

}

#define TEST_REMOVE_BY_DATA
int main()
{
	struct node *head;
	head = createLinkedList();
	printLinkedList(head);

#ifdef TEST_REMOVE_BY_DATA
	int d;
	puts("Now let's test removing a node by data. 0 for EOL.");
	while (scanf("%d", &d) && d != 0)
	{
		removeNodeByData(head, d);
		printLinkedList(head);
	}
#endif
}