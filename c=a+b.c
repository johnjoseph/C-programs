#include <stdio.h>
//to find the triplet such that the sum of the two is the third
int main()
{
	int arr[]={0,3,4,5,6,7};
	int n=sizeof(arr)/sizeof(int);
	int f,b,i,sum;
	for(i=0;i<n;i++)
	{
		f=i+1;
		b=n-1;
		while(b>f)
		{
			sum=arr[b]-(arr[i]+arr[f]);			
			if(sum>0) b--;
			else if(sum<0) f++;
			else {printf("numbers are %d,%d,%d\n",arr[i],arr[f],arr[b]);exit(0);}	
		}		
	}
	printf("not found!\n");
}
