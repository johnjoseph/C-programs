// reversing a string
#include <stdio.h>
char * str_rev(char * str)
{
  char * temp=str;int count=0,i;
  while(*str!='\0') str++,count++;
  for(i=0;i<count/2;i++)
  {
    str--;
    *str=*str^*temp;
    *temp=*str^*temp;
    *str=*str^*temp;
    temp++;
  }
  for(i=count/2;i<count;i++) str--;
  printf("%s\n",str);  
}

int main(int argc,char ** argv)
{
  while(argc)
  {
   str_rev(*argv);
    argv++;
    argc--;
  }
  return 0;
}