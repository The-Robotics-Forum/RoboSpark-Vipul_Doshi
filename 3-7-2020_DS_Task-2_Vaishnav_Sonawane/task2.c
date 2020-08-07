#include<stdio.h>
#include<stdlib.h>
struct node
{
    int key,flag;
    struct node *left,*right;
};
struct node *new_node(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node ));
    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct node *create_node(struct node *node,int item)
{
    if(node == NULL)
        return new_node(item);
    else if(item < node->key)
        node->left = create_node(node->left,item);
    else if(item > node->key)
        node->right = create_node(node->right,item);
    return node;
}
struct node* search(struct node* root, int key)
{
    if (root == NULL || root->key == key)
       return root;
    if (root->key < key)
       return search(root->right, key);
    return search(root->left, key);
}

void printPostorder(struct node* node)
{
     if (node == NULL)
        return;
     printPostorder(node->left);
     printPostorder(node->right);
     printf("%d ", node->key);
}

int main()
{
   struct node* root = NULL, *temp;
   int item,srch,choice,i = 2;
   while(i == 2)
   {
    printf("1.Build / Insert");
    printf("\n2. Display");
    printf("\n3.  Search");
    printf("\n\nEnter choice  :");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("\nENTER THE KEY:");
        scanf("%d",&item);
        if(root==NULL)
            root=create_node(root,item);
        else
            create_node(root,item);
        break;
        case 2:printf(".POSTORDER TRAVERSAL\n");
            printf("POSTORDER TRAVERSAL IS:");
                       printPostorder(root);
                   break;
        case 3:printf("ENTER THE ELEMENT");
        scanf("%d",&srch);
        temp = search(root,srch);
        if(temp == NULL)
            printf("ELEMENT NOT PRESENT");
        else
            printf("ELEMENT PRESENT");
        break;

    }
    printf("\n\nPRESS 2 TO CONTINUE\t\t");
    scanf("%d",&i);
   }
   return 0;

}
