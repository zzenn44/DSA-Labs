

#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#define MAXSIZE 100

void enqueue(int[],int);
void dequeue(int[]);
void display(int []);
int rear =-1; int front =-1;



int main()
{

    int a,c;
    int i;
    

 
    int c_queue[MAXSIZE];
  
    while(1)
    {
    printf("        \t\t MENU\n");
    printf("\t\t1. enqueue operation\n");
    printf("\t\t2. dequeue operation\n");
    printf("\t\t3. display the contents\n");
    printf("\t\t4. Invalid operation and exit\n");
    
    printf("Enter the choice\n");
    scanf("%d",&c);

    switch(c)
        {
            case(1):
            printf("enter the element you want to add in the queue\n");
            scanf("%d",&a);
                enqueue(c_queue,a);
    
            break;

            case(2):
          dequeue(c_queue);
          
            break;

            case(3):
            display(c_queue);
            break;

            case(4):
            exit(0);
            
                default : printf("Invalid option  ");
                break;
        }
  
    }
    return 0;

}
void enqueue(int c_queue[],int x)
{
 if(front==rear+1 &&  rear== MAXSIZE -1 || front == 0 && rear == MAXSIZE - 1)
      
            printf("The circular queue ia full and Enqueue  operation cannot be performmed and exit \n");
      
    else
    {
          //queue is empty
           if(front == -1 && rear == -1 )
           {
            front=rear=0;
               c_queue[rear]=x;
           }
           //When the first position is empty
        
        else if (rear==MAXSIZE-1)
        {
            rear=0;
            
            c_queue[rear]=x;

        }
        //At normal position
        else
        {
            rear++;
            c_queue[rear]=x;
            
        }
           
           printf("The enqueue operation has been performmed \n");
    }
}
void dequeue(int c_queue[])
{
    if(front == -1 && rear == -1)
    {
   
        printf("The Dequeue operation can't be performmed as the circular queue is empty\n ");
    }
    //when front is the end
    else if (front==MAXSIZE-1)
    {
        printf("Thus dequeued value is %d ", c_queue[front]);
        front=0;
    }
    //only one element
    else if (front==rear)
    {
     
         printf("Thus dequeued value is %d ", c_queue[front]);
        front=rear=-1;
    }
    else
    //
    {
        printf("Thus dequeued value is %d ", c_queue[front]);
        front++;
        
    }
 
       
        printf("\nThe Dequeue operation has been performmed\n ");
    }

void display(int c_queue[]) {
    if (front == -1) {
        printf("The queue is empty\n");
    } else {
        int i = front;

        if (front <= rear) {
            // In case of one or more elements
            while (i <= rear) {
                printf("%d\t", c_queue[i]);
                i++;
            }
        } else {
            // In case of one or more elements when the queue is full
            while (i <= MAXSIZE - 1) {
                printf("%d\t", c_queue[i]);
                i++;
            }

            i = 0;  // Reset i to 0 to continue from the beginning of the array
            while (i <= rear) {
                printf("%d\t", c_queue[i]);
                i++;
            }
        }
    }
    printf("\n");
}
