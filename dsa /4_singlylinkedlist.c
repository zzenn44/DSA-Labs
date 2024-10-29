


#include <stdio.h>
#include <stdlib.h>

void insertion();
void insertionatbeg(int);
void insertionatend(int);
void insertionatspec(int);

void deletion ();
void deletionatbeg();
void deletionatend();
void deletionatspec(void);

void display();
void search(int);

//defining a structure for node
typedef struct Node{
    int data;
    struct Node* next;
}Node;

//function declaration
Node* get_node();

//initialising the head pointer to null
Node* head=NULL;

int main(){
    int c,a,e;
   



      while(1)
    {
    printf("\n\t\t\t MENU\n");
    printf("\t\t1. Insert a node\n");
    printf("\t\t2. Delete a node\n");
    printf("\t\t3. Display a node\n");
    printf("\t\t4. Search a element in the  node\n");
    printf("\t\t5.  invalid option and exit \n");
    
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
            printf("Enter the element you want to search for: ");
                int e;
                scanf("%d", &e);
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
    
void insertion()
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
            printf("enter the element you want to add to node at the beginning\n");
            scanf("%d",&a);
            insertionatbeg(a);
            break;

            case(2):
              printf("enter the element you want to add node at the end\n");
            scanf("%d",&b);
                insertionatend(b);
            break;

            case(3):
              printf("enter the element you want to add node at the specific posistion\n");
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
    void insertionatbeg(int a )
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
        newnode->next=head;
        head=newnode;
        printf("%d is inserted at the beginnig",a);
       }
      
        
        
}
//at end
  void insertionatend(int b)
{
      Node *newnode=get_node();
      newnode->data =b;
       newnode->next=NULL;
       //when no node is present 
         if (head == NULL) {
        head = newnode;
    } else {
      Node *temp=head;
      while(temp->next!=NULL)
      {
          temp=temp->next;
          
      }
      temp->next=newnode;
     
   
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
      else{
        int pos;
            printf("Enter the position you want to insert the node\n");
            scanf("%d",&pos);
          //when multiple nodes are present
          Node* temp=head;
          int currentpos=1;
          while(currentpos!=pos-1)
          {
              temp=temp->next;
              currentpos++;
              
          }
          
          
          newnode->next=temp->next;
          temp->next=newnode;

        
          printf("%d is inserted at the end",d);
          
          
      }
  }



//deletion operations
void deletion()
{
    int data_to_del,c;
    //Incase of no node
    if(head==NULL)
    {
        printf("There is no deletion\n");
        return ;
        
    }
   
        
    printf("\t\t1. Delete a node at beginning\n");
    printf("\t\t2. Delete a node at end\n");
    printf("\t\t3. Delete a node at specific position\n");
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
void deletionatbeg()

{
    int data_to_del;
     //incase of only one node
    if (head->next==NULL)
    {
        data_to_del=head->data;
        head=NULL;
        printf("%d data was taken out\n",data_to_del);
    }
    else
    {
         Node* temp =head;
    printf("The %d is taken out from the beginning ",head->data);
    head=temp->next;
    free(temp);
    }
   
}

//deleting at end
void deletionatend()
{
    int data_to_del;
     //incase of only one node
    if (head->next==NULL)
    {
        data_to_del=head->data;
        head=NULL;
        printf("%d data was taken out\n",data_to_del);
    }
    Node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
        
    }
    printf("The data to be deleted is %d",temp->next->data);
    free(temp->next);
    temp->next=NULL;
}
 //deletion at specific position 
            void deletionatspec()
{
     
      int pos;
      
     
      
  

      
      //when no node is present
      if(head==NULL)
      {
          
         printf("NO deletion possible at specific position\n");
          return;
      }
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

          while(currentpos!=pos-1)
          {
              temp=temp->next;
              currentpos++;
              
          }
           printf("At the specified position %d is deleted",temp->next->data);
          
          
         

        
         //temp->next=temp->next->next;
         Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);

          //free(temp);



        
         
          
          
      }
  
        


void display() {
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
    printf("NULL\n");//for last element 
}
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

        /* //deletion at specific position 
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

          while(temp!=pos)
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
         



        
         
          
          
      }*/
