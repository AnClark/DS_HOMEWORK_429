/**
* Basic Linkedlist homework
* NOTICE: Linkedlist here has leading node.
*/

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
}


void removeNodeByPosition(struct node *head, int i)
{
	// NOTICE: Position starts from 1 instead of 0. (Not correspond with
	// book?)
	struct node *n, *q;
	int j = 0;

	n = head->next;

	while (n->next != NULL && j < i)
	{
		n = n->next;
		j++;
	}

	if (n->next == NULL)
	{
		printf("** Not found");
		return;
	}

	q = n->next;
	n->next = q->next;
	free(q);

}


void removeNodeByData(struct node *head, int data)
{
	struct node *p, *q;
	p = head;

	while (p->next != NULL && p->next->data != data)
		p = p->next;

	if (p->next == NULL)
	{
		printf("** Not found");
		return;
	}
	
	q=p->next;
	p->next=q->next;
	free(q);
}



void insertNodeBeforePosition(struct node *head, int i, int newdata)
{
	struct node *p, *f;
	int j=0;
	
	p=head->next;
	
	//Locate to where we insert
	while(p->next != NULL && j < i){
		p=p->next;
		j++;
		}
	
}



int main()
{
	int a;

	struct node *head;
	head = createLinkedList();

	printLinkedList(head);

#define TEST_REMOVE_BY_POSITION

#ifdef TEST_REMOVE_BY_POSITION
	printf("\nWhich to remove? Input<0 to break.  ");
	while (scanf("%d", &a) && a >= 0)
	{
		removeNodeByPosition(head, a);
		printLinkedList(head);
		printf("\n");
	}
#endif

#ifdef TEST_REMOVE_BY_DATA
	printf("\nWhich data do you wanna remove?\n");
		while (scanf("%d", &a) && a >= 0)
	{
		removeNodeByData(head, a);
		printLinkedList(head);
		printf("\n");
	}
#endif

puts("----------- FINISHED -----------");
}