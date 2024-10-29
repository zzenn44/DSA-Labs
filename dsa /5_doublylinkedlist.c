//
//  4_doublylinkedlist.c
//  dsa labs
//
//  Created by zzen on 23/08/2023.
//




#include <stdio.h>
#include <stdlib.h>

void insertion(void);
void insertionatbeg(int);
void insertionatend(int);
void insertionatspec(int);

void deletion (void);
void deletionatbeg(void);
void deletionatend(void);
void deletionatspec(void);

void display(void);
void search(int);

//defining a structure for node
typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

//function declaration
Node* get_node(void);
  

//initialising the head pointer to null
Node* head=NULL;

int main(void){
    int c,e;
   



      while(1)
    {
    printf("\n\t\t\t MENU\n");
    printf("\t\t1. Insert a node\n");
    printf("\t\t2. Delete a node\n");
    printf("\t\t3. Display a node\n");
     printf("\t\t4. Search an element\n");
    printf("\t\t5.  Invalid option and exit \n");
    
    printf("Enter the choice\n");
    scanf("%d",&c);
        switch(c)
        {
            case(1):
       
                insertion();
    
            break;

            case(2):
                deletion();
                
            break;

            case(3):
              display();
            break;

              case(4):
              printf("Enter the element that you want to search in node\n");
              scanf("%d",&e);

              search(e);
            break;

            

            case(5):
            exit(0);
            
                default : printf("Invalid option  ");
                break;
        }
  
    }
    return 0;

}


        //defining the function to create a new node
        Node* get_node()
    {
        Node* newnode=(Node* )malloc(sizeof(Node));
        newnode->next=NULL;
        return newnode;
    }
    
void insertion(void)
{
  int c,a,b,d;
    printf("\t\t1. Insert a node at beginning\n");
    printf("\t\t2. Insert a node at end\n");
     printf("\t\t3. Insert a node at specific position\n");
    
    printf("\t\t4.  invalid option and go back \n");
    
    printf("Enter the choice\n");
    scanf("%d",&c);
        switch(c)
        {
            case(1):
            printf("enter the element you want to add to data of node at the beginning\n");
            scanf("%d",&a);
            insertionatbeg(a);
            break;

            case(2):
              printf("enter the element you want to add to data of node at the end\n");
            scanf("%d",&b);
                insertionatend(b);
            break;
            case(3):
              printf("enter the data you want to add to data at the specific position of the node  \n");
            scanf("%d",&d);
                insertionatspec(d);
            break;

          case(4):
            exit(0);
            
                default : printf("Invalid option  ");
                break;
        }
}

    //insertion at different positions

//at beginning
    void insertionatbeg(int a)
{

       Node* newnode= get_node();

      if (head == NULL) {
        // If the list is empty, set newnode as the new head.
        newnode->data=a;
        head = newnode;
       
    }  
     else
      {
        newnode->data =a;
       
        newnode->prev=NULL;
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        
        printf("%d is inserted at the beginning",newnode->data);
     }  
     
 
        
        
}
//at end
  void insertionatend(int b)
{
      Node* newnode=get_node();
      newnode->data =b;
      
      newnode->next=NULL;
      //when no node is present
      if(head==NULL)
      {
          
          newnode->prev=NULL;
          head=newnode;
          
      }
      else{
          //when multiple nodes are present
          Node *temp=head;
          while(temp->next!=NULL)
          {
              temp=temp->next;
              
          }
          temp->next=newnode;
          newnode->prev=temp;
        
          printf("%d is inserted at the end",b);
          
          
      }
  }
    void insertionatspec(int d)
{
      Node* newnode=get_node();
      int pos;
      
      newnode->data =d;
      
      newnode->next=NULL;

      
      //when no node is present
      if(head==NULL)
      {
          
         printf("NO insertion possible at specific position\n");
          
      }
     
        
            printf("Enter the position you want to insert the node\n");
            scanf("%d",&pos);
   if (pos < 1)
        {
            printf("Invalid position. Position should be >= 1.\n");
            return;
        }
          //when multiple nodes are present
          Node* temp=head;
            int currentpos=1;
          while(currentpos!=pos-1)
          {
              temp=temp->next;
                 currentpos++;
              
          }
        
          
          
          newnode->next=temp->next;
          newnode->prev=temp;
          temp->next->prev=newnode;
          temp->next=newnode;

        
          printf("%d is inserted at the  specified position ",d);
          
          
      }
  


//deletion operations
void deletion(void)
{
    int c;
    //Incase of no node
    if(head==NULL)
    {
        printf("There is no deletion\n");
        return ;
        
    }
    
    
    printf("\t\t1. Delete a node at beginning\n");
    printf("\t\t2. Delete a node at end\n");
       printf("\t\t3. Delete a node at specific position \n");
    
    printf("\t\t4.  invalid option and go back \n");
    
    printf("Enter the choice\n");
    scanf("%d",&c);
    switch(c)
    {
        case(1):
            
            deletionatbeg();
            break;
            
        case(2):
         deletionatend();
            break;

             case(3):
            deletionatspec();
            break;

         

        case(4):
            exit(0);
            
        default : printf("Invalid option  ");
            break;
    }
}
    
    
    //deleteion at beginning
    void deletionatbeg(void)

    {
        
        //incase of only one node
        if (head->next==NULL)
        {
            int data_to_del;
            data_to_del=head->data;
            head=NULL;
            printf("%d data was taken out\n",data_to_del);
        }
        else{
                 Node* temp =head;
        printf("The %d is taken out from the beginning ",head->data);
        head=head->next;
        
        head->prev=NULL;
        free(temp);
        }
       
    }
    
    //deleting at end
    void deletionatend(void)
    {
    
        //incase of only one data
        if (head->next==NULL)
        {
            int data_to_del;
            data_to_del=head->data;
            head=NULL;
            printf("%d data was taken out\n",data_to_del);
        }
        else
        {
                 Node *temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
            
        }
        printf("The data to be deleted is %d",temp->next->data);
        free(temp->next);
        temp->next=NULL;
    }
        }


         //deletion at specific position 
            void deletionatspec()
{

    //when no node is present
      if(head==NULL)
      {
          
         printf("NO deletion possible at specific position\n");
          return;
      }int pos;
      printf("Enter the position you want to delete the node\n");
            scanf("%d",&pos);
       if (pos < 1 )
    {
        printf("Invalid position. Position should be >= 1.\n");
        return;
    }

    //when multiple nodes are present
          Node* temp=head;
          int currentpos=1;

          while(temp != NULL && currentpos < pos)
          {
              temp=temp->next;
              currentpos++;
              
          }
           if (temp == NULL) {
        printf("Position %d is beyond the end of the list.\n", pos);
        return;
    }
          
          
          
         
        if(temp->next!=NULL)
        {
          Node* nodeToDelete = temp->next;
          temp->prev->next=temp->next;
          temp->next->prev=temp->prev;
        printf("At the specified position %d is deleted",temp->next->data);

          free(nodeToDelete);
        }
         



        
         
          
          
      }
    
  
        


//to display element of the node 
void display(void)
 {
    Node* temp = head;

    if (temp == NULL) {
        printf("The linked list is empty. No nodes to display.\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        
        temp = temp->next;
    }
   printf(" NULL\n");
 
}
//to search element of the node 
void search(int element) {
    Node* current = head;//setting a pointer to node to get the head 
    int found = 0;
    int pos = 0;

    while (current != NULL) {
        pos++;
        if (current->data == element) 
        {
            found = 1;
            printf("%d found at position %d\n", element, pos);
            break;
        }
        current = current->next;
   
    }

    if(found==0) {
        printf("%d not found in the linked list\n", element);
    }
}
