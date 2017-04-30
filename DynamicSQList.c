#include<stdio.h>
#include<malloc.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct
{
	int *base;
	int length;
	int listsize;
  } SQList;
  
void initSQList(SQList *L){
	L.base=malloc(LIST_INIT_SIZE * sizeof(int);
	if(!L.base){
		puts("OVERFLOW!");
		return;
		}
	}