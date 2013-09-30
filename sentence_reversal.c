//reversing a sentence
#include <stdio.h>
int main(int argc,char ** argv)
{
  char ** temp=argv;char ** foo;int count=argc,i;
  while(count) temp++,count--;
  temp--;
  for(i=0;i<argc/2;i++)
  {
    *foo=*temp;
    *temp=*argv;
    *argv=*foo;
    printf("%s\t",*argv++);
    temp--;
  }
  for(i=argc/2;i<argc;i++) printf("%s\t",*argv++);
  return 0;
}