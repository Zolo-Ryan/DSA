#include<stdio.h>
#define BUFSIZE 1000
typedef struct STACK Stack;
typedef struct STACK{
	int buf[BUFSIZE];
	int top;
	void (*push)(Stack*,int);
	int (*pop)(Stack*);
} Stack;
Stack nice;
Stack init(Stack*);
void push(Stack*,int);
int pop(Stack*);

//Stack name = init(&name);
//push usage -> push(&name,val)
//pop usage -> pop(&name)

void push(Stack *name,int n)
{
	if(name->top<BUFSIZE-1)
		name->buf[++name->top] = n;
	else
		fprintf(stderr,"Oops Stack full\n");
}
int pop(Stack *name)
{
	if(name->top>=0)
		return name->buf[name->top--];
	else
		fprintf(stderr,"Stack empty already");
	return 0;
}
Stack init(Stack *name){
	name->push = push;
	name->pop = pop;
	name->top = -1;
}
