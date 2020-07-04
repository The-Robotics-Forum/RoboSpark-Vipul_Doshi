#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
}Node;
Node* NewNode(int data)
{
     Node* node = (Node*)malloc(sizeof(Node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;

     return(node);
};
void Postorder(Node* node)
{
     if(node == NULL)
        return;

     Postorder(node->left);
     Postorder(node->right);
     printf("%d ", node->data);
}
int main()
{
     Node *root                 = NewNode(1);
     root->left                 = NewNode(2);
     root->right                = NewNode(3);
     root->left->left           = NewNode(4);
     root->left->right          = NewNode(5);
     root->right->right         = NewNode(6);
     root->left->left->left     = NewNode(7);
     root->right->right->left   = NewNode(8);
     root->right->right->right  = NewNode(9);
     printf("\nPostorder traversal is : ");
     Postorder(root);
}
