
#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int key;
    struct node *left, *right;
};
 

struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 

void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}
 

struct node* insert(struct node* node, int key)
{
   
    if (node == NULL)
        return newNode(key);
 
    
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
 
   
    return node;
}
 

int main()
{
   
      
    struct node* root = NULL;
    root = insert(root, 25);
    insert(root, 35);
    insert(root, 24);
    insert(root, 40);
    insert(root, 75);
    insert(root, 65);
    insert(root, 85);
 

    inorder(root);
 
    return 0;
}

