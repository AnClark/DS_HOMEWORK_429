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


int main()
{
    struct node *head;
    head=createLinkedList();
    printLinkedList(head);
}

