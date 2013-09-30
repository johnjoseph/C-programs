// finding the longest palindrome in the string
#include <stdio.h>

int main(int argc,char ** argv)
{
  char *f= *(++argv),*b1,*b2,*start;
  int length=0,max_length=0;
  while(*f!='\0')
  {
    b1=f-1;
    b2=f-2;
    while(*f==*b1&&*f!='\0') //even
    {
      length++;
      if(length>max_length) max_length=length,start=b1;
      f++;
      b1--;
    }
    length=0;
    while(*f==*b2&&*f!='\0') //odd
    {
      length++;
      if(length>max_length) max_length=length+1,start=b2; //middle
      f++;
      b2--;
    }    
    length=0;
    f++;
  }
  max_length*=2;
  start--;
  while(max_length+1) printf("%c",*start++),max_length--;
  printf("\n");
  return 0;
}
