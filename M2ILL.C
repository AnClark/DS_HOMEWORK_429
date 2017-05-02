// Merge two incremental linked lists.
// NOTICE: Linked list here have NO LEADING NODE!!!
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
	puts("\n--------------------------------------------");

}


struct node *startMerge(struct node *head1, struct node *head2)
{
	struct node *p, *q, *f;
	p = head1;
	q = head2->next;

	// Traverse all the nodes in list2,
	// then find somewhere suitable to insert in list1.
	while (q != NULL)
	{
		// Find somewhere to insert
		while (p->next != NULL && p->next->data < q->data)
			p = p->next;

        //Then, RELINK node in list2
        // By relinking, you can save a lot of time and space!
		f = q;
		q = q->next;
		f->next = p->next;
		p->next = f;

	}

    // At this time, nodes in list2 are all relinked out. So just delete it.
	free(head2);
	
	// All nodes are merged to list1.
	return head1;

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

	puts("\n\n----------- MERGED LIST -----------");
	printLinkedList(startMerge(head1, head2));
}