#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define maxsize 5
int top=-1,stack[maxsize];

void push();
void pop();
void display();
int main()
{
	//push
	int ch;
	while(1)
	{
	
		printf("Enter stack \n");
		printf("1. PUSH\n2. POP");
		printf("Enter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			default:
				printf("Invalid choice.");
		}
	}
//	return 0;
}

void push()
{
	int item;
	if(top==maxsize-1)
	{
		printf("Stack is full");
	}
	else
	{
		printf("Enter the element to add on stack.");
		scanf("%d",&item);
		top=top+1;
		stack[top]=item;
	}
	
}
void pop()
{
	int item;
	if(top<0)
	{
		printf("Stack is empty");
	}
	else
	{
//		printf("Enter the ")
 	printf("\nPopped element %d",stack[top]);
	//item = stack[top];	
	top = top - 1;
	}
}
void display()
{
	if(top == -1)
    {
        printf("Stack is empty.");
    }
    else
    {
        printf("\nElements present in the stack: \n");
		for(int i=top;i>=0;--i)
        {
        	printf("%d\n", stack[i]);
		}
            
    }
}



//#include <stdio.h>
//
//#include <stdlib.h>
//
//#define SIZE 4
//
//int top = -1, inp_array[SIZE];
//void push();
//void pop();
//void show();
//
//int main()
//{
//    int choice;
//
//    while (1)
//    {
//        printf("\nPerform operations on the stack:");
//        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");
//        printf("\n\nEnter the choice: ");
//        scanf("%d", &choice);
//
//        switch (choice)
//        {
//        case 1:
//            push();
//            break;
//        case 2:
//            pop();
//            break;
//        case 3:
//            show();
//            break;
//        case 4:
//            exit(0);
//
//        default:
//            printf("\nInvalid choice!!");
//        }
//    }
//}
//
//void push()
//{
//    int x;
//
//    if (top == SIZE - 1)
//    {
//        printf("\nOverflow!!");
//    }
//    else
//    {
//        printf("\nEnter the element to be added onto the stack: ");
//        scanf("%d", &x);
//        top = top + 1;
//        inp_array[top] = x;
//    }
//}
//
//void pop()
//{
//    if (top == -1)
//    {
//        printf("\nUnderflow!!");
//    }
//    else
//    {
//        printf("\nPopped element: %d", inp_array[top]);
//        top = top - 1;
//    }
//}
//
//void show()
//{
//    if (top == -1)
//    {
//        printf("\nUnderflow!!");
//    }
//    else
//    {
//        printf("\nElements present in the stack: \n");
//for(int i=top;i>=0;--i)
//        {
//        	printf("%d\n", inp_array[i]);
//		}
//            
//    }
//}
