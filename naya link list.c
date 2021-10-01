#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data ;
    struct node *next;
}node;
struct node * node_creation(int n);
void displaySLL(struct node *root);
void main()
{
    int n;
    struct node *root;
    printf("Enter the no. of nodes for creation.\n");
    scanf("%d",&n);
    root = node_creation(n);
    displaySLL();

}
struct node * node_creation(int n)
{
 struct node *head;
 struct node *temp;
 struct node *newnode;

 for(int i=0;i<n;i++)
 {
     newnode = (struct node*)malloc(sizeof(struct node));
     newnode-> next = NULL;
     printf("Enter data for the node. \n");
     scanf("%d",&(newnode->data));
     if(head == NULL)
        head = newnode;
     else
     {
         temp= head;
         while(temp->next != NULL );
         temp = temp->next;
         temp-> next = newnode;
     }
 }
     return head;

}
void displaySLL(struct node *root)
{
    struct node *temp;
    temp= root;
    while(temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
}
