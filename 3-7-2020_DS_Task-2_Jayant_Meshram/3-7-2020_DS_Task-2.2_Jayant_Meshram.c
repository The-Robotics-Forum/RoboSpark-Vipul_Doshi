/*Understand and write the code for inserting a new node/searching whether node with given value is present in Binary Search Tree(BST).*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data; //node will store an integer
    struct node *right_child; // right child
    struct node *left_child; // left child
};
struct node* new_node(int x)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;

    return p;
}
struct node* search(struct node *root, int x)
{
    if(root==NULL)
        printf("Value is Not in Tree");   
    else if(root->data==x)
        printf("Value is in tree");             //if root data equals x
    else if(x>root->data)                       //right subtree
        return search(root->right_child, x);
    else                                        //smaller, left subtree
        return search(root->left_child,x);
}


struct node* insert(struct node *root, int x)
{
    //search for the place to insert
    if(root==NULL)
        return new_node(x);
    else if(x>root->data)                       //greater,inserted to right
        root->right_child = insert(root->right_child, x);
    else                                        //smaller,inserted to left
        root->left_child = insert(root->left_child,x);
    return root;
}
int main()
{
    int s;
    struct node *root;
    root = new_node(20);
    insert(root,5);
    insert(root,1);
    insert(root,15);
    insert(root,9);
    insert(root,7);
    insert(root,12);
    insert(root,30);
    insert(root,25);
    insert(root,40);
    insert(root, 45);
    insert(root, 42);

    printf("Enter the value you want to search: ");
    scanf("%d",&s);
    search(root,s);

}