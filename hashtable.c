// hashtable
#include<stdio.h>
#include<stdlib.h>

struct hash
{
	int count;
	char val;
	struct hash *next;
};

# define tablesize 7
struct hash * table[tablesize];

int insert(char foo)
{
	int h=foo%tablesize;
	struct hash * temp=table[h];
	while(temp)
	{
		if(temp->val==foo) {temp->count++;return 0;}
		else temp=temp->next;
	}
	struct hash * imp= malloc(sizeof(struct hash));
	imp->val=foo,imp->count=1,imp->next=table[h],table[h]=imp;
	return 0;	
}

void print()
{
	int i;
	for(i=0;i<tablesize;i++)
	{
		struct hash * foo=table[i];
		while(foo)
		{
			printf("%c:%d--",foo->val,foo->count);
			foo=foo->next;
		}
		printf("\n");
		
	}	
} 

int main(int argc,char ** argv)
{
	argv++,argc--;
	while(argc--)
	{
		insert(**argv);
		argv++;
	}
	print();
	return 0;
}

