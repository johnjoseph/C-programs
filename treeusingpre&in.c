// takes the inorder and preorder of a tree and prints the postorder after building the tree. 
#include <stdio.h>
#include <stdlib.h>

int pre[]={10,5,3,1,8,6,9,14,12,16,15};
int in[]={1,3,5,6,8,9,10,12,14,15,16};
int len=sizeof(pre)/sizeof(int);

struct node
{
	int val;
	struct node * left;
	struct node * right;
};

int getindex(int n)
{
	int i;
	for(i=0;i<len;i++)
		if(n==in[i]) return i;
}

struct node * build(int start,int end)
{
	static preindex=0;
	
	if(start>end) return NULL;

	struct node * temp=malloc(sizeof(struct node));
	temp->val=pre[preindex];
	int index=getindex(pre[preindex++]);		
	if(start==end) return temp;

	temp->left=build(start,index-1);
	temp->right=build(index+1,end);
	return temp;
	
}

void postorder(struct node * foo)
{
	if(foo)
	{
		postorder(foo->left);
		postorder(foo->right);		
		printf("%d ",foo->val);		
	}
}
int main()
{
	struct node * root=build(0,len-1);
	postorder(root);
	return 0;
}	
