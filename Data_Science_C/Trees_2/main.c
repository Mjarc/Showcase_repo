#include "Trees.h"

void printTreeStructure(struct node *root) 
{
    if (root != NULL) 
    {
        printf("%d ", root->data);
        printTreeStructure(root->left);
        printTreeStructure(root->right);
    }
}

int main(int argc, char *argv[]) 
{
    if (argc <= 1) 
    {
        printf("Where is my splay?!?!\n");
        return 1;
    }

    struct node *root = NULL;

    printf("Tree structure after each insertion:\n");

    for (int i = 1; i < argc; i++) 
    {
        char *endptr;
        int value = strtol(argv[i], &endptr, 10);

        if (*endptr != '\0') 
        {
            printf("Invalid input: %s\n", argv[i]);
            return 1;
        }

        root = insertNode(root, value);

        printTreeStructure(root);
        printf("\n");
    }

    int key_to_search = 10;
    printf("\nPreorder traversal after searching for %d:\n", key_to_search);
    root = search(root, key_to_search);
    printTreePreOrder(root);
    printf("\n");

    return 0;
}




