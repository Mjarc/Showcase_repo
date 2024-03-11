#include "queue.h"

struct queue *create(int capacity) 
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->people = (struct person *)malloc(sizeof(struct person) * capacity);
    return q;
}


bool is_full(struct queue *q) 
{
    return (q->size == q->capacity);
}


bool is_empty(struct queue *q) 
{
    return (q->size == 0);
}

void add(struct queue *q, struct person k) 
{
    if (is_full(q)) {
        printf("Queue is full, failed to add person.\n");
    } else {
        q->rear = (q->rear + 1) % q->capacity;
        q->people[q->rear] = k;
        q->size++;
    }

}


struct person remove_person(struct queue *q) 
{
    struct person empty_person = {false, 0.0};
    if (is_empty(q)) {
        printf("Queue is empty, cannot be removed.\n");
        return empty_person;
    } 
    else {
        struct person removed = q->people[q->front];
        q->front = (q->front + 1) % q->capacity;
        q->size--;
        return removed;
    }
}


void shift_all(struct queue *q) 
{
    if (is_full(q) || is_empty(q)) {
        printf("Queue is full or empty, cannot be shifted.\n");
    } else {

        for (int i = q->front; i != q->rear; i = (i + 1) % q->capacity) {
            q->people[i] = q->people[(i + 1) % q->capacity];
        }

        q->rear = (q->rear - 1 + q->capacity) % q->capacity;
        q->size--;
    }
}


void add_customer(struct queue *q, struct person k) 
{
    shift_all(q);  
    add(q, k);     
}


void display_all(struct queue *q) 
{
    if (is_empty(q)) {
        printf("Queue is empty.\n");
    } 
    else {
        printf("Queue Status:\n");
        for (int i = q->front; i != (q->rear + 1) % q->capacity; i = (i + 1) % q->capacity) {
            printf("Is Client: %s, Money: %.2f\n", q->people[i].isClient ? "Yes" : "No", q->people[i].money);
        }
    }
}
