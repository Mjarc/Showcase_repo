# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "LinkedList.h"


////////// Singly Linked List ////////

struct linearNode* createLinearNode(int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
    struct linearNode* newNode = (struct linearNode*)malloc(sizeof(struct linearNode));
    
    if (newNode != NULL) {
        newNode->id = id;
        strncpy(newNode->childName, childName, NUM);
        strncpy(newNode->parentName, parentName, NUM);
        newNode->childBY = childBY;
        newNode->parentPhone = parentPhone;
        newNode->linearNext = NULL;
    }
    
    return newNode;
}

void SL_insertBeginning(struct linearNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
    struct linearNode* newNode = createLinearNode(id, childName, parentName, childBY, parentPhone);

    if (newNode == NULL) {
        printf("Memory allocation failed. Unable to insert node at the beginning.\n");
        return;
    }

    newNode->linearNext = *head;
    *head = newNode;
}

void SL_insertAtEnd(struct linearNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
    struct linearNode* newNode = createLinearNode(id, childName, parentName, childBY, parentPhone);
    if (newNode == NULL) {
        printf("Memory allocation failed. Unable to insert node at the end.\n");
        return;
    }

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct linearNode* temp = *head;
    while (temp->linearNext != NULL) {
        temp = temp->linearNext;
    }
    temp->linearNext = newNode;
}

void SL_insertAfterNode(struct linearNode *prevNode, struct linearNode *newNode)
{
    if (prevNode == NULL){
        printf("Previous node cannot be NULL. Insertion failed.\n");
        return;
    }
    newNode->linearNext = prevNode->linearNext;
    prevNode->linearNext = newNode;
}

void SL_deleteAtBeginning(struct linearNode **head)
{
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct linearNode *temp = *head;
    *head = (*head)->linearNext;
    free(temp);
}

void SL_deleteAtEnd(struct linearNode **head)
{
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct linearNode* temp = *head;
    struct linearNode* temp2 = NULL;

    if (temp->linearNext == NULL) {
        free(temp);
        *head = NULL; 
        return;
    }

    while (temp->linearNext->linearNext != NULL) {
        temp = temp->linearNext;
    }

    temp2 = temp->linearNext;
    temp->linearNext = NULL;
    free(temp2);
} 

void SL_deleteAfterNode(struct linearNode *head, int targetID)
{
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct linearNode *current = head;

    while (current != NULL && current->id != targetID) {
        current = current->linearNext;
    }

    if (current == NULL || current->linearNext == NULL) {
        printf("Node with ID %d not found in the list or no node to delete after it.\n", targetID);
        return;
    }

    
    struct linearNode *nodeToDelete = current->linearNext;
    current->linearNext = nodeToDelete->linearNext;
    free(nodeToDelete);

}

void printSinglyLinearList(struct linearNode* head)
{
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct linearNode *current = head;
    
    while (current != NULL) {
        printf("ID: %d, Child Name: %s, Parent Name: %s, Child Birth Year: %d, Parent Phone: %d\n", current->id, current->childName, current->parentName, current->childBY, current->parentPhone);
        current = current->linearNext;
    }
}

struct linearNode *searchSinglyNode(struct linearNode *head, int targetID)
{
    struct linearNode *current = head;

    while (current != NULL) {
        if (current->id == targetID) {
            return current;
        }
        current = current->linearNext;
    }

    return NULL;
}


////////// Circular Singly Linked List ////////

void CSL_insertBeginning(struct linearNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone) {
    struct linearNode* newNode = createLinearNode(id, childName, parentName, childBY, parentPhone);

    if (newNode == NULL) {
        printf("Memory allocation failed. Unable to insert node at the beginning.\n");
        return;
    }

    if (*head == NULL) {
        newNode->linearNext = newNode;
        *head = newNode;
    } 
    else {
        struct linearNode* tail = *head;
        while (tail->linearNext != *head) {
            tail = tail->linearNext;
        }

        newNode->linearNext = *head;
        *head = newNode;
        tail->linearNext = newNode; 
    }
}


void CSL_insertAtEnd(struct linearNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone) {
    struct linearNode* newNode = createLinearNode(id, childName, parentName, childBY, parentPhone);

    if (newNode == NULL) {
        printf("Memory allocation failed. Unable to insert node at the end.\n");
        return;
    }

    if (*head == NULL) {
        newNode->linearNext = newNode;
        *head = newNode;
    } else {
        struct linearNode* tail = *head;
        while (tail->linearNext != *head) {
            tail = tail->linearNext;
        }

        newNode->linearNext = *head;
        tail->linearNext = newNode; 
    }
}

void CSL_insertAfterNode(struct linearNode *prevNode, struct linearNode *newNode) {
    if (prevNode == NULL){
        printf("Previous node cannot be NULL. Insertion failed.\n");
        return;
    }

    newNode->linearNext = prevNode->linearNext;
    prevNode->linearNext = newNode;
}

void CSL_deleteAtBeginning(struct linearNode **head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct linearNode* tail = *head;
    while (tail->linearNext != *head) {
        tail = tail->linearNext;
    }

    struct linearNode *temp = *head;
    *head = (*head)->linearNext;
    tail->linearNext = *head; 
    free(temp);
}

void CSL_deleteAtEnd(struct linearNode **head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct linearNode* tail = *head;
    while (tail->linearNext->linearNext != *head) {
        tail = tail->linearNext;
    }

    struct linearNode* temp = tail->linearNext;
    tail->linearNext = *head;
    free(temp);
}

void CSL_deleteAfterNode(struct linearNode* head, int targetID) {
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct linearNode *current = head;

    while (current != NULL && current->id != targetID) {
        current = current->linearNext;
    }

    if (current == NULL || current->linearNext == head) {
        printf("Node with ID %d not found in the list or no node to delete after it.\n", targetID);
        return;
    }

    struct linearNode *nodeToDelete = current->linearNext;
    current->linearNext = nodeToDelete->linearNext;
    free(nodeToDelete);
}

struct linearNode *searchCircularSinglyNode(struct linearNode *head, int id) {
    struct linearNode *current = head;

    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->linearNext;
        if (current == head) {
            break; 
        }
    }

    return NULL;
}

void printSinglyCircularList(struct linearNode* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct linearNode *current = head;
    
    do {
        printf("ID: %d, Child Name: %s, Parent Name: %s, Child Birth Year: %d, Parent Phone: %d\n", current->id, current->childName, current->parentName, current->childBY, current->parentPhone);
        current = current->linearNext;
    } while (current != head);
}


////////// Doubly Linked List ////////

struct doublyNode *createDoublyNode(int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
    struct doublyNode *newNode = (struct doublyNode *)malloc(sizeof(struct doublyNode));

    if (newNode != NULL) {
        newNode->id = id;
        strncpy(newNode->childName, childName, NUM);
        strncpy(newNode->parentName, parentName, NUM);
        newNode->childBY = childBY;
        newNode->parentPhone = parentPhone;
        newNode->doublyNext = NULL;
        newNode->doublyPrev = NULL;
    }

    return newNode;
}


void DL_insertBeginning(struct doublyNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone)
{
    struct doublyNode* newNode = createDoublyNode(id, childName, parentName, childBY, parentPhone);
    
    if (newNode == NULL) {
        printf("Memory allocation failed. Unable to insert node at the beginning.\n");
        return;
    }
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    newNode->doublyNext = *head;
    (*head)->doublyPrev = newNode;
    *head = newNode;
}

void DL_insertAtEnd(struct doublyNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone)
{
    struct doublyNode* newNode = createDoublyNode(id, childName, parentName, childBY, parentPhone);

    if (newNode == NULL) {
        printf("Memory allocation failed. Unable to insert node at the end.\n");
        return;
    }

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct doublyNode* current = *head;
    while (current->doublyNext != NULL) {
        current = current->doublyNext;
    }
    
    current->doublyNext = newNode;
    newNode->doublyPrev = current;
}


void DL_insertAfterNode(struct doublyNode* prevNode, struct doublyNode* newNode) 
{
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL. Insertion failed.\n");
        return;
    }
    
    newNode->doublyNext = prevNode->doublyNext;
    if (prevNode->doublyNext != NULL) {
        prevNode->doublyNext->doublyPrev = newNode; 
    }
    prevNode->doublyNext = newNode;
    newNode->doublyPrev = prevNode;
}

void DL_deleteAtBeginning(struct doublyNode** head) 
{
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    
    struct doublyNode* temp = *head;
    if (temp->doublyNext != NULL) {
        temp->doublyNext->doublyPrev = NULL; 
    }
    *head = temp->doublyNext;
    free(temp);
}

void DL_deleteAtEnd(struct doublyNode** head)
{
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct doublyNode* current = *head;

    if (current->doublyNext == NULL) {
        free(current);
        *head = NULL;
        return;
    }

    while (current->doublyNext->doublyNext != NULL) {
        current = current->doublyNext;
    }

    free(current->doublyNext);
    current->doublyNext = NULL;
}


void DL_deleteAfterNode(struct doublyNode* head, int targetID) 
{
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    
    struct doublyNode* current = head;
    
    while (current != NULL && current->id != targetID) {
        current = current->doublyNext;
    }
    
    if (current == NULL || current->doublyNext == NULL) {
        printf("Node with ID %d not found in the list or no node to delete after it.\n", targetID);
        return;
    }
    
    struct doublyNode* nodeToDelete = current->doublyNext;
    current->doublyNext = nodeToDelete->doublyNext;
    if (nodeToDelete->doublyNext != NULL) {
        nodeToDelete->doublyNext->doublyPrev = current; 
    }
    free(nodeToDelete);
}

void printDoublyLinearList(struct doublyNode* head) 
{
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct doublyNode* current = head;
    
    while (current != NULL) {
        printf("ID: %d, Child Name: %s, Parent Name: %s, Child Birth Year: %d, Parent Phone: %d\n", current->id, current->childName, current->parentName, current->childBY, current->parentPhone);
        current = current->doublyNext;
    }
}

struct doublyNode* searchDoublyNode(struct doublyNode* head, int id) 
{
    struct doublyNode* current = head;
    
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->doublyNext;
    }
    
    return NULL;
}

/////// Circular Doubly Linked List /////////////

void CDL_insertBeginning(struct doublyNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone)
{
    struct doublyNode* newNode = createDoublyNode(id, childName, parentName, childBY, parentPhone);

    if (newNode == NULL) {
        printf("Memory allocation failed. Unable to insert node at the beginning.\n");
        return;
    }

    if (*head == NULL) {
        *head = newNode;
        newNode->doublyNext = newNode;
        newNode->doublyPrev = newNode;
    } else {
        newNode->doublyNext = *head;
        newNode->doublyPrev = (*head)->doublyPrev;
        (*head)->doublyPrev->doublyNext = newNode;
        (*head)->doublyPrev = newNode;
        *head = newNode;
    }
}

void CDL_insertAtEnd(struct doublyNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
    struct doublyNode* newNode = createDoublyNode(id, childName, parentName, childBY, parentPhone);
    
    if (newNode == NULL) {
        printf("Memory allocation failed. Unable to insert node at the end.\n");
        return;
    }

    if (*head == NULL) {
        *head = newNode;
        newNode->doublyNext = newNode;
        newNode->doublyPrev = newNode;
    } else {
        newNode->doublyNext = *head;
        newNode->doublyPrev = (*head)->doublyPrev;
        (*head)->doublyPrev->doublyNext = newNode;
        (*head)->doublyPrev = newNode;
    }
}


void CDL_insertAfterNode(struct doublyNode* prevNode, struct doublyNode* newNode) 
{
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL. Insertion failed.\n");
        return;
    }
    
    newNode->doublyNext = prevNode->doublyNext;
    newNode->doublyPrev = prevNode;
    prevNode->doublyNext = newNode;
    newNode->doublyNext->doublyPrev = newNode;
}

void CDL_deleteAtBeginning(struct doublyNode** head) 
{
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    
    struct doublyNode* temp = *head;

    if (temp->doublyNext == temp) {
        *head = NULL;
    } else {
        *head = temp->doublyNext;
        temp->doublyNext->doublyPrev = (*head)->doublyPrev;
        (*head)->doublyPrev->doublyNext = *head;
    }

    free(temp);
}

void CDL_deleteAtEnd(struct doublyNode** head) 
{
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct doublyNode* temp = (*head)->doublyPrev;

    if (temp == *head) {
        free(temp);
        *head = NULL;
    } 
    else {
        (*head)->doublyPrev = temp->doublyPrev;
        temp->doublyPrev->doublyNext = *head;
        free(temp);
    }
}

void CDL_deleteAfterNode(struct doublyNode* head, int targetID) 
{
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    
    struct doublyNode* current = head;

    while (current != NULL && current->id != targetID) {
        current = current->doublyNext;
    }

    if (current == NULL || current->doublyNext == current) {
        printf("Node with ID %d not found in the list or no node to delete after it.\n", targetID);
        return;
    }
    
    struct doublyNode* nodeToDelete = current->doublyNext;
    current->doublyNext = nodeToDelete->doublyNext;
    nodeToDelete->doublyNext->doublyPrev = current;
    
    if (nodeToDelete == head) {
        head = current;
    }
    
    free(nodeToDelete);
}

void printDoublyCircularList(struct doublyNode* head) 
{
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct doublyNode* current = head;
    
    do {
        printf("ID: %d, Child Name: %s, Parent Name: %s, Child Birth Year: %d, Parent Phone: %d\n", current->id, current->childName, current->parentName, current->childBY, current->parentPhone);
        current = current->doublyNext;
    } while (current != head);
}

struct doublyNode* searchCircularDoublyNode(struct doublyNode* head, int id) 
{
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    
    struct doublyNode* current = head;
    
    do {
        if (current->id == id) {
            return current;
        }
        current = current->doublyNext;
    } while (current != head);

    return NULL;
}



