#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#define MAXSIZE 100

void push(int[] ,int );
void pop(int []);
void display(int [] );
void peek(int[]);


int IsEmpty();
int  IsFull();
int top=-1,i;

int  main()
{
    int c;
    int arr[MAXSIZE];
    int x;
    while(1)
    {
    printf("\n\t\t\t MENU\n");
    printf("\t\t1. Push operation\n");
    printf("\t\t2. Pop operation\n");
    printf("\t\t3. Display the contents\n");
    printf("\t\t4.  Peek operation \n");
     printf("\t\t5. Invalid operation and exit\n");
    
    printf("Enter the choice\n");
    scanf("%d",&c);
    

    switch(c)
     {
        case(1):
        printf("enter the element you want to add in the stack\n");
        scanf("%d",&x);
        push(arr,x);
   
        break;

        case(2):
        pop(arr);
     
        break;

        case(3):
        display(arr);
        
        break;
        case(4):
        peek(arr);
        break;


        case(5):
        exit(0);
        break;

        default:
        printf("Invalid option\n");
        break;
    }
   
}
 return 0;
}


    void push(int arr[MAXSIZE],int x)
    {
        if(IsFull()==1)
        {
            printf("The push operation cannot be performmed and exit \n");
        }
                   else
     
            {
               
                  
                    top =top+1;
                    arr[top]=x;
               
              
                      printf("PUSH OPERATION \nThe push operation is been performmed\n");
                    printf("Now, the value on the top of the stack is %d\n",arr[top]);
            
        }
     }

     void pop(int arr[MAXSIZE])
     {
        if(IsEmpty()==1)
        {
            printf("The stack is empty and pop not performmed");
        }
        else 
        {
     
          
            printf("POP OPERATION \nHence the deleted element fom the stack is %d\t \n",arr[top]);
             top--;

        }
     }
  
         void display(int arr[MAXSIZE])
    {
        if (IsEmpty()==1)
        {
            printf("The stack is empty enter some elements inorder to display\n");

        }
        else
        {
                     printf("DISPLAY OPERATION \nThe elements of the stacks are ");
                        for(int i=0;i<=top;i++)
                      {
                                printf("\n\t\t%d",arr[i]);
                              
                      }
                        printf("\nThe elements of the stack has been displayed\n");
                                
                    
               
                
     
        }
    }
        void peek(int arr[MAXSIZE])
    {
        if (IsEmpty()==1)
        {
            printf("PEEK OPERATION \nThe stack is empty enter some elements inorder to display\n");

        }
        else
        {
                     printf("The elements at the top of the stacks is");
                
        
               
                    printf("\n\t\t%d",arr[top]);
                    printf("\nThe elements at the top of the stack has been displayed\n");
      
        }
    }

    
    int IsFull()   
    {
        if (top==MAXSIZE-1)
        {
            return 1;
        }
            else 
        {
            return 0;
        }
    }  
    int IsEmpty()
    {
        if(top==-1)
        {
            return 1;
        }
        
            else 
        {
            return 0;
        }
    }