#include <stdio.h>
#define MAXSIZE 10
  void linearSearch(int[] ,int);
int main()
{
     int key,arr[MAXSIZE];
    printf("Enter the key value\n");
    scanf("%d",&key);
    printf("Enter the elements of the array\n");
    for(int i=0;i<MAXSIZE;i++)
    {
        scanf("%d",&arr[i]);

    }
   
     linearSearch(arr,key);
    
    
    

}
  void linearSearch(int arr[MAXSIZE],int key)
  {
   int count=0,pos;
    for(int i=0;i<MAXSIZE;i++)
    {
        if(arr[i]==key)
        {
           count++;
           pos=i+1;
           


        }
    }
    if(count==1)
    {
         printf("Element %d found at postion %d\t SEARCH SUCESSFUL\n",key,pos);
    }
    else 
    {
         printf("Element not found\t SEARCH NOTSUCESSFUL\n");
    }

    }
  

