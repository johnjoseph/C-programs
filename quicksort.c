// quicksort
#include <stdio.h>

int arr[]={5,4,3,2,1};

int main()
{
	int i;
	int n=sizeof(arr)/sizeof(int);
	quicksort(0,n-1);
	for(i=0;i<n;i++) printf("%d ",arr[i]);
	printf("\n");
	return 0;
}

int quicksort(int m,int n)
{
	if(n>m)
	{
		int p=partition(m,n);
		quicksort(m,p-1);
		quicksort(p+1,n);
	}
}

void swap(int x,int y)
{
	int temp;
	temp=arr[x];
	arr[x]=arr[y];
	arr[y]=temp;	
}

int partition(int a,int b)
{
	int p=arr[a],s=a,f=b;
	while(f>s)
	{
	   while(p>=arr[s]&&s<=b) s++;
	   while(p<arr[f]) f--;
	   if(f>s) swap(f,s);
	}
	swap(a,f);
	return f;	
}
