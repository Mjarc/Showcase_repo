#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Trees.h"

// New node create function
struct node* newNode(int data) 
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Write a function that recursively adds a new node to the tree.
struct node* insertNode(struct node* n, int data) 
{
	if (n == NULL) {
        return newNode(data);
    }

    if (data < n->data) {
        n->left = insertNode(n->left, data);
    } else if (data > n->data) {
        n->right = insertNode(n->right, data);
    }

    return n;
}

// Write a function that finds the lowest value in the tree and returns it
int findMin(struct node *tree) 
{
	if (tree == NULL) {
        printf("Tree is empty.\n");
        return -1;
    }
    while (tree->left != NULL) {
        tree = tree->left;
    }
    return tree->data;
}

// Write a function that finds the max value in the tree and returns it
int findMax(struct node *tree) 
{
	if (tree == NULL) {
        printf("Tree is empty.\n");
        return -1;
    }
    while (tree->right != NULL) {
        tree = tree->right;
    }
    return tree->data;
}

// Write a function that returns the address of the highest value node in the tree.
struct node* findMaxNode(struct node *tree) 
{
	if (tree == NULL) {
        printf("Tree is empty.\n");
        return NULL;
    }
    while (tree->right != NULL) {
        tree = tree->right;
    }
    return tree;
}

struct node* findInOrderSuccessor(struct node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Write a function that recursively deletes nodes from the tree. If the node to be deleted has 2 children, update the deleted node as the maximum valued node of the left sub-tree.
// (like the Delete function at https://www.cs.usfca.edu/~galles/visualization/BST.html)
struct node* deleteNode(struct node *tree, int data) 
{
	if (tree == NULL) {
        return tree;
    }

    if (data < tree->data) {
        tree->left = deleteNode(tree->left, data);
    } else if (data > tree->data) {
        tree->right = deleteNode(tree->right, data);
    } else {
        // Node with only one child or no child
        if (tree->left == NULL) {
            struct node* temp = tree->right;
            free(tree);
            return temp;
        } else if (tree->right == NULL) {
            struct node* temp = tree->left;
            free(tree);
            return temp;
        }

        // Node with two children, get the in-order successor (smallest in the right subtree)
        struct node* temp = findInOrderSuccessor(tree->right);

        // Copy the in-order successor's data to this node
        tree->data = temp->data;

        // Delete the in-order successor
        tree->right = deleteNode(tree->right, temp->data);
    }

    return tree;
}

// Write a function that traverses the tree recursively using the "in-order" method and prints the values to the screen.
void printTreeInOrder(struct node* tree) 
{
	if (tree == NULL) {
        return;
    }
    printTreeInOrder(tree->left);
    printf("%d ", tree->data);
    printTreeInOrder(tree->right);
}

// Write a function that traverses the tree recursively using the "pre-order" method and prints the values to the screen.
void printTreePreOrder(struct node* tree) 
{
	if (tree == NULL) {
        return;
    }
    printf("%d ", tree->data);
    printTreePreOrder(tree->left);
    printTreePreOrder(tree->right);
}

// Write a function that traverses the tree recursively using the "post-order" method and prints the values to the screen.	
void printTreePostOrder(struct node* tree) 
{
	if (tree == NULL) {
        return;
    }
    printTreePostOrder(tree->left);
    printTreePostOrder(tree->right);
    printf("%d ", tree->data);
}

// Level-order method
// Function that calculates the height of the tree recursively
int findHeight(struct node *tree) 
{
	if (tree == NULL) {
        return -1;
    }

    int leftHeight = findHeight(tree->left);
    int rightHeight = findHeight(tree->right);

    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

// Function that recursively suppresses nodes in the same alignment (level)
void printLevel(struct node *tree, int level)
{
	if (tree == NULL) {
        return;
    }
    if (level == 0) {
        printf("%d ", tree->data);
    } else {
        printLevel(tree->left, level - 1);
        printLevel(tree->right, level - 1);
    }
}


// Using the two functions above, write the function that traverses the tree with the "level-order" method and prints the values to the screen	
void printTreeLevelOrder(struct node* tree)
{
	int height = findHeight(tree);
    for (int i = 0; i <= height; i++) {
        printLevel(tree, i);
    }
}
