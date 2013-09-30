// reversing a linked list
#include <stdio.h>
#include <stdlib.h>

struct link
{
	char val;
	struct link * next;
}*hd=NULL;

void insert(char value)
{
	struct link * temp=malloc(sizeof(struct link));
	temp->val=value;
	struct link * foo=hd;
		
	if(foo)
	{
		while(foo->next) foo=foo->next;
		foo->next=temp;
	}
	else hd=temp;
}

void rev(struct link * p1,struct link * p2, struct link * p3)
{
	while(p3)
	{
		struct link * temp=p1;
		p1=p2;
		p2=p3;
		p3=p3->next;
		p1->next=temp;
	}
	p2->next=p1;	
	hd=p2;
}	

void link_rev()
{
	struct link * p1=hd;
	struct link * p2=p1->next;
	struct link * p3=p2->next;
	p1->next=NULL;
	rev(p1,p2,p3);
}

void print()
{
	struct link * foo=hd;
	while(foo)
	{
		printf("%c\t",foo->val);
		foo=foo->next;
	}
}

int main(int argc, char ** argv)
{
	argv++,argc--;
	while(argc--)
	{
		insert(**argv);
		argv++;
	}
	print();
	link_rev();
	printf("\n");
	print();
}
