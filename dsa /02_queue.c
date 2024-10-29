#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#define MAXSIZE 100

void enqueue(int[],int);
void dequeue(int[]);
int IsFull(int[]);
int IsEmpty(int[]);
void traverse(int [],int,int);
int rear =-1; 
int front =-1;



int main()
{

    int a,c,i,b,d;

    int x;
    int arr[MAXSIZE];
  
    while(1)
    {
    printf("\n\t\t\t MENU\n");
    printf("\t\t1. enqueue operation\n");
    printf("\t\t2. dequeue operation\n");
    printf("\t\t3. traverse the contents\n");
    printf("\t\t4. Invalid operation and exit\n");
    
    printf("Enter the choice\n");
    scanf("%d",&c);

    switch(c)
        {
            case(1):
            printf("enter the element you want to add in the queue\n");
            scanf("%d",&a);
            printf("\nENQUEUE OPERATION\n");
                enqueue(arr,a);
    
            break;

            case(2):
             printf("\nDEQUEUE OPERATION\n");
          dequeue(arr);
          
            break;

            case(3):
             printf("\nTRAVERSAL OPERATION\n");
            traverse(arr,front,rear);
                
            
            break;

            case(4):
            exit(0);
            
                default : printf("Invalid option  ");
                break;
        }
  
    }
    return 0;

}
void enqueue(int arr[],int x)
{
 if(IsFull(arr)==1)
      
            printf("The Enqueue  operation cannot be performmed and exit \n");
      
    else 
    {
          
           if(front==-1)
           {
            front=0;
           }
        
            rear++;
           arr[rear]=x;

          
        
            printf("The enqueue operation has been performmed \n");
            
    }
}
void dequeue(int arr[])
{
    if(IsEmpty(arr)==1)
    {
   
        printf("The Dequeue operation can't be performmed as the queue is empty\n ");
    }
    else 
    { 
        printf("Thus dequeued value is %d ", arr[front]);
        front++;
        if(front>rear)
        {
                 front=rear=-1;
        }
       
        printf("\nThe Dequeue operation has been performmed\n ");
    }
}
void traverse(int arr[],int front,int rear)
{
    
        if (IsEmpty(arr)==1)
        {
            printf("The queue is empty enter some elements inorder to traverse\n");

        }
        else
        {
                     printf("The elements of the queue are ");
                for (int i=front;i<=rear;i++)
        {
               
                    printf("\n\t\t%d",arr[i]);
                 
        }
        }
    
}
    
    int IsFull(int arr[])   
    {
        if (rear==MAXSIZE-1)
        {
            return 1;
        }
            else 
        {
            return 0;
        }
    }  
    int IsEmpty(int arr[])
    {
        if(front==-1||rear<front)
        {
            return 1;
        }
        
            else 
        {
            return 0;
        }
    }