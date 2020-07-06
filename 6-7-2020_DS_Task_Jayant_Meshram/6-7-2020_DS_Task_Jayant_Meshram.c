/*Create a linked list with 4 nodes and two functions-
1. Addition/Insertion of a Node
2. Deletion of a Node*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};

struct node * createLinkedist()
{
    printf("\nCreating Linked list with 4 nodes....\n\n");

    struct node * head=NULL;
    struct node * temp;
    struct node * p;

    for(int i=0;i<4;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->next=NULL;
        printf("Enter the data for no. %d node: ",i+1);
        scanf("%d",&(temp->data));

        if(head==NULL)
            head=temp;
        
        else
        {
            p = head;
            while(p->next!=NULL)
            {
                p= p->next;
            }
            p->next= temp; 
        }
    }
    return head; 
}

void deleteNode(struct node * head,int n)
{
    if (head == NULL)
    {
      printf("Linked list is empty");
      return; 
    }
    
    if (n == 1) 
    {   
        head->data = head->next->data;
        head->next = head->next->next;
        return;
    }

    struct node *p = head;

    for(int i=1;i<=n-2;i++)
    {
        p=p->next;
    }

    if(p->next->next!=NULL)
    {
        struct node * temp_next= p->next->next;
        free(p->next);
        p->next=temp_next;
    }
    else
    {
        free(p->next);
        p->next=NULL;
    }
}

void insertNode(struct node * head,int n,int m)
{
    struct node * new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=m;
    new_node->next=NULL;


    if (head == NULL)
    {
      head->data=m;
      head->next=NULL;
      return;
    }

    struct node *p = head;
    for(int i=1;i<=n-2;i++)
    {
        p=p->next;
    }

    struct node * temp_next= p->next;
    new_node->next=temp_next;
    p->next=new_node;
}

struct node * insertNodefirst(struct node * head, int m)
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp -> data = m;
    temp -> next = head;
    return temp;
}

void display(struct node * head)
{
    struct node *p = head;
    while(p!=NULL)
    {   
        printf("%d->",p->data);
        p = p->next;
    }
    printf("NULL");
}

int main()
{   
    int p,choice,v;
    struct node * HEAD;    
    HEAD= createLinkedist();
    printf("\nYour Linked list is:\n");
    display(HEAD);
    printf("\n\nEnter choice:  1.Delete Node   2.Insert/Add Node:\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("\nEnter node's position which has to be deleted: ");
            scanf("%d",&p);
            printf("\nLinked list after deletion of node with position %d:\n",p);
            deleteNode(HEAD,p);
            display(HEAD);
            break;
            
        case 2:
            printf("\nEnter position and value that has to be inserted respectively: ");
            scanf("%d%d",&p,&v);
            printf("\nLinked list after insertiing %d at position %d:\n",v,p);
            if(p!=1)
            {
                insertNode(HEAD,p,v);
                display(HEAD);

            }
            else
            {
                display(insertNodefirst(HEAD,v));
            }
            break;
    }
}