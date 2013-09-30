#include <stdio.h>
//to find the triplet such that the sum of the three is zero
int main()
{
	int arr[]={-3,-2,-1,0,1,2,5,6};
	int n=sizeof(arr)/sizeof(int);
	int f,b,i,sum;
	for(i=0;i<n;i++)
	{
		f=i+1;
		b=n-1;
		while(b>f)
		{
			sum=arr[i]+arr[f]+arr[b];			
			if(sum>0) b--;
			else if(sum<0) f++;
			else {printf("numbers are %d,%d,%d\n",arr[i],arr[f],arr[b]);exit(0);}	
		}		
	}
	printf("not found!\n");
}
