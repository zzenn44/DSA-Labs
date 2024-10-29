 
#include<stdio.h>
#include<stdlib.h>
//#include<pch.h> 


struct node{
             int data;
             struct node *left;
             struct node *right;
      }*tree;
      //struct node *tree;
      void create_tree(struct node *);
      struct node *insertElement(struct node *, int);
      void inorderTraversal(struct node *);
      struct node *deleteElement(struct node *, int);
int main()
{
       int option, val;
       struct node *ptr = NULL;
       create_tree(tree);

do {
        printf("\n ******MAIN MENU******* \n");
        printf("\n 1. Insert Element");;
        printf("\n 2. Inorder Traversal");;
        printf("\n 3. Delete an element");
        printf("\n 4. Exit");
        printf("\n\n Enter your option : ");
scanf("%d", &option);
switch(option)
{
case 1:
printf("\n Enter the value of the new node : ");
scanf("%d", &val);
tree = insertElement(tree, val);
break;
case 2:
printf("\n The elements of the tree are : \n");
inorderTraversal(tree);
break;
case 3:
printf("\n Enter the element to be deleted : ");
scanf("%d", &val);
tree = deleteElement(tree, val);
break;
case 4:
exit(0);
default:
printf("please enter the value between 1-4:\n");
} }while(1);
return 0;
}
void create_tree(struct node *tree)
{
tree = NULL;
}
struct node *insertElement(struct node *tree, int val)
{
struct node *ptr, *nodeptr, *parentptr;
ptr = (struct node*)malloc(sizeof(struct node));
ptr->data = val;
ptr->left = NULL;
ptr->right = NULL;
if(tree==NULL)
{
tree=ptr;
tree->left=NULL;
tree->right=NULL;
}
else {
  parentptr=NULL;
  nodeptr=tree;
  while(nodeptr!=NULL) {
  parentptr=nodeptr;
  if(val < nodeptr->data)
    nodeptr=nodeptr->left;
 else
   nodeptr = nodeptr->right;
}
 if(val < parentptr->data)
   parentptr->left = ptr;
else
  parentptr->right = ptr;
}
       return tree;
}

void inorderTraversal(struct node *tree)
{
if(tree != NULL){
inorderTraversal(tree->left); 
printf("%d\t", tree->data); 
inorderTraversal(tree->right);
}
}
struct node *deleteElement(struct node *tree, int val)
{
  struct node *cur, *parent, *suc, *psuc, *ptr;
  if(tree->left==NULL)
   {
    printf("\n The tree is empty ");
    return(tree);
   }
parent = tree;
cur = tree->left;
while(cur!=NULL && val!= cur->data) {
parent = cur;
cur = (val<cur->data)? cur->left:cur->right;
}
if(cur == NULL) {
printf("\n The value to be deleted is not present in the tree"); 
return(tree);
}
if(cur->left == NULL)
ptr = cur->right;
else if(cur->right == NULL)
ptr = cur->left;
else
{
// Find the in–order successor and its parent 
psuc = cur;
cur = cur->left;
while(suc->left!=NULL)
{
  psuc = suc;
  suc = suc->left;
}
if(cur==psuc) {
// Situation 1 
suc->left = cur->right;
}
else {
// Situation 2
   suc->left = cur->left;
   psuc->left = suc->right;
   suc->right = cur->right;
   }
   ptr = suc;
}
// Attach ptr to the parent node
if(parent->left == cur)
parent->left=ptr;
else
parent->right=ptr;
free(cur);
return tree;
}