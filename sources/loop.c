#include <stdio.h>
int main(int argc, char *argv[])
{
   int i;
   int y = atoi(argv[1]); 

   for (i=0; i <= y; i++)
   {
       printf("%d\n", i);
       sleep(5);
   }
   return 0;
}
