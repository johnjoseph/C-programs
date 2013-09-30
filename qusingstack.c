// implementation of a queue using one stack
#include <stdio.h>
#include <stdlib.h>

struct stack
{
	int val;
	struct stack * next;
}*top=NULL;

void push(int value)
{
	struct stack * temp=malloc(sizeof(struct stack));
	temp->val=value;
	if(!top) top=temp,temp->next=NULL;
	else temp->next=top,top=temp;	
}

int pop()
{
	int temp;
	if(top) temp=top->val,top=top->next;
	return temp;
}

void enqueue(int val)
{
	push(val);
}

int isstackempty()
{
	return (top==NULL)?1:0;
}

int dequeue()
{
	if(isstackempty()) return 1;
	int temp=pop();
	int flag=dequeue();
	if(!flag) push(temp);
	return 0;
}

void print()
{
	struct stack * temp=top;
	while(temp)	printf("%d\t",temp->val),temp=temp->next;
	printf("\n");
}

int main(int argc, char ** argv)
{
	argc--;argv++;
	while(argc--)
	{
		enqueue(atoi(*argv));
		argv++;
	}
	print();
	dequeue();
	print();
	dequeue();
	print();
}
