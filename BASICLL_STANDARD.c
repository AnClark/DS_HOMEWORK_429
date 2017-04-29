#include<stdio.h>
#include<malloc.h>

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
}

int main()
{
	struct node *head;
	head = createLinkedList();

	printLinkedList(head);
}