// Merge two incremental linked lists.
// NOTICE: Linked list here have no leading node!!!
#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int data;
	struct node *next;
} node;

struct node *createLinkedListIncremental()
{
	struct node *head, *p, *f;
	int d;

	// Create head
	head = malloc(sizeof(struct node));

	// Create the first node
	f = malloc(sizeof(struct node));
	scanf("%d", &d);
	f->data = d;
	f->next = NULL;
	head->next = f;

	// Create the following nodes
	while (scanf("%d", &d) && d != 0)
	{
		// Find out somewhere to insert
		p = head;
		while (p->next != NULL && p->next->data < d)
			p = p->next;

		// Then, insert
		f = malloc(sizeof(node));
		f->data = d;
		f->next = p->next;
		p->next = f;
	}

	return head;
}

void printLinkedList(struct node *head)
{
	struct node *p;
	p = head->next;

	puts("----------- Your linked list -----------");
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	puts("\n----------------------");

}

int main()
{
	struct node *head1, *head2;

	puts("----------- Input List1 -----------");
	head1 = createLinkedListIncremental();
	printLinkedList(head1);

	puts("----------- Input List2 -----------");
	head2 = createLinkedListIncremental();
	printLinkedList(head2);


}