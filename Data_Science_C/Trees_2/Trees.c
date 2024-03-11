#include "Trees.h"

struct node *createNode(int data) 
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node *rightRotate(struct node *x) 
{
    struct node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

struct node *leftRotate(struct node *x) 
{
    struct node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

struct node *splay(struct node *root, int key) 
{
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data) 
    {
        if (root->left == NULL)
            return root;

        if (key < root->left->data) 
        {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        } 
        else if (key > root->left->data) 
        {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }

        return (root->left == NULL) ? root : rightRotate(root);
    } 
    else if (key > root->data) 
    {
        if (root->right == NULL)
            return root;

        if (key < root->right->data) 
        {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        } 
        else if (key > root->right->data) 
        {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }

        return (root->right == NULL) ? root : leftRotate(root);
    }

    return root;
}

struct node *insertNode(struct node *root, int data) 
{
    if (root == NULL)
        return createNode(data);

    root = splay(root, data);

    if (root->data == data)
        return root;

    struct node *newNode = createNode(data);

    if (data < root->data) 
    {
        newNode->right = root;
        newNode->left = root->left;
        root->left = NULL;
    } 
    else 
    {
        newNode->left = root;
        newNode->right = root->right;
        root->right = NULL;
    }

    return newNode;
}

struct node *search(struct node *root, int key) 
{
    return splay(root, key);
}

void printTreePreOrder(struct node *root) 
{
    if (root != NULL) 
    {
        printf("%d ", root->data);
        printTreePreOrder(root->left);
        printTreePreOrder(root->right);
    }
}





