#include <stdio.h>
#define MAXSIZE 5
  int binary_Search(int[] ,int,int,int);
int main()
{
     int key,arr[MAXSIZE],left=0,right=MAXSIZE-1;
   
    printf("Enter the key value\n");
    scanf("%d",&key);
    printf("Enter the elements of the array\n");
    for(int i=0;i<MAXSIZE;i++)
    {
        scanf("%d",&arr[i]);

    }
   
     binary_Search(arr,left,right,key);
    
    
 return 0;   

}
 int binary_Search(int arr[MAXSIZE],int left,int right,int key)
  {
    int count=0,m;
    while(left<=right)
    {
     m=(left+right)/2;
    
    if(arr[m]==key)
    {
      count++;
    } 
    else
    {
        if(key<=arr[m])
        {
            right=m-1;
        }
        else
     {
        left=m+1;

        }
    }
    if(count==1)
    {
           printf("Element %d found at postion %d\t SEARCH SUCESSFUL\n",key,m+1);
          
          
    }
   

    }
    if(left>right)
    {
        printf("%d not found \t SEARCH UNSUCESSFUL",key);
       
    
    }
     return 0;

    }
    

   
  

