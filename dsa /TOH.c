#include <stdio.h>
#include <stdlib.h>

void toh(int,char,char,char);
int main()
{
    int n ;
    char a='A';
    char b='B';
    char c='C';

    printf("Enter the number of disks\n");
    scanf("%d",&n);
    toh(n,a,b,c);
    return 0;

}
void toh(int N,char beg,char aux,char end)
{
    if(N==0)
    {
           printf("Tower of hanoi cannot be implemented\n");
        return;
    }
   
     

   
    else if(N==1)
   
   {
      printf("Move the disks %d from tower %c to %c\n",N,beg,end);
       
   }
      
       
  else
   {
        toh(N-1,beg,end,aux);
       

            printf("\n move disc %d from %c to %c\n" ,N,beg,end);

            toh(N-1,aux,beg,end);
           
        
               

        
     
    }
}
