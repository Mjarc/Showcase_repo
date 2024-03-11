#include <stdio.h>
#include <stdlib.h>
struct node 
{
	int data;
    struct node *left;
    struct node *right;
};


struct node *createNode(int data) ;
struct node *rightRotate(struct node *x) ;
struct node *leftRotate(struct node *x) ;
struct node *splay(struct node *root, int key) ;
struct node *insertNode(struct node *root, int data) ;
struct node *search(struct node *root, int key) ;
void printTreePreOrder(struct node *root) ;