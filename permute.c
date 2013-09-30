// printing all permutations of the given string
#include<stdio.h>
int len;
void swap(char *a,char * b)
{
	if(a!=b)
	*a=*a^*b,
	*b=*a^*b,
	*a=*a^*b;
}

char * permute(char * str,int d)
{
	int i;
	if(len==d)
	{
		printf("%s\n",str);
	}
	else
	{
		for(i=d;i<len;i++)
		{
			swap(str+i,str+d);
			permute(str,d+1);
			swap(str+i,str+d);
		}
	}
}

int main(int argc,char ** argv)
{
	char * temp=*++argv;
	while(*temp!='\0') len++,temp++;
	permute(*argv,0);
	return 0;
}