// Basic stack realized in linked list
// Pointer top points to the head of the linked list.
// NOTICE: This linked list has NO LEADING NODE.
#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int data;
	struct node *next;
} node;


struct node *initializeStack()
{
	struct node *top;
	top = malloc(sizeof(node));
	top->next = NULL;

	return top;
}

void Push(struct node *top, int data)
{
	struct node *f;

	f = malloc(sizeof(node));
	f->data = data;
	f->next = top->next;
	top->next = f;
}

int Pop(struct node *top)
{
	struct node *p;
	int data;
	p = top->next;

	if (top->next == NULL)
	{
		puts("*** FATAL: Stack is empty! ***");
		return -1;
	}
	else
	{
		data = p->data;
		top->next = p->next;
		free(p);
	}
	return data;
}

void printStack(struct node *top)
{
	struct node *p;
	p = top->next;

	if (top->next == NULL)
	{
		puts("*** NOTICE: Empty stack! ***");
	}
	else
	{
		puts("----------- Current stack -----------");
		while (p != NULL)
		{
			printf("%d\n", p->data);
			p = p->next;
		}
		puts("---------------------------------");
	}
}

int main()
{
	struct node *top;
	char cmd;
	int d;

	// Create a stack first
	top = initializeStack();

	// Make an interactive interface
	puts("Input format: <command> <value>");
	puts("Commands:\n"
		 "\t i <value> \tPush value into stack.\n"
		 "\t o \tPop and print value.\n" "\t p \tPrint current stack.\n" "\t q \tExit program.");

	while (scanf("%c", &cmd))
	{
		switch (cmd)
		{
		case 'i':
			scanf("%d", &d);
			Push(top, d);
			printStack(top);
			break;
		case 'o':
			d = Pop(top);
			if (d != -1)
			{
				printf("*** Poped item: %d ***\n", d);
				printStack(top);
			}
			break;

		case 'p':
			printStack(top);
			break;

		case 'q':
			puts("Exit program...");
			return 0;
			break;

			// default:
			// puts("*** FATAL: Invalid command! ***");
		}
	}
}