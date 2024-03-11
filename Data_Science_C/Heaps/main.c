#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include "Heaps.h"

int main() {

    int arr1[] = { 16, 4, 10, 14, 7, 9, 3, 2, 8, 1 };
    int arr2[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    int heap[] = { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 };
    int SIZE = 10;

    printf(">> max_heapify_recursive called for arr1\n");
    max_heapify_recursive(arr1, 1, SIZE);

    printf("heap: ");
    print_heap(arr1, SIZE);

    printf("\n>> max_heapify_recursive is working smoothly, continue on your way...\n");

    printf(">> build_max_heap called for arr2\n");
    build_max_heap(arr2, SIZE);

    printf("heap: ");
    print_heap(arr2, SIZE);

    printf("\n>> build_max_heap is working smoothly, continue on your way...\n");

    printf("----- Priority Queue -----\n");

    int max = extractMax(heap, &SIZE);
    printf(">> extracted max = %d\nqueue: ", max);
    print_heap(heap, SIZE);

    int max2 = extractMax(heap, &SIZE);
    printf("\n>> extracted max = %d\nqueue: ", max2);
    print_heap(heap, SIZE);
    printf("\n");

    insertData(heap, &SIZE, 35);
    printf(">> 35 is added\nqueue: ");
    print_heap(heap, SIZE);
    printf("\n");

    removeIndex(heap, &SIZE, 5);
    printf(">> The element with priority %d is removed from the queue\nqueue: ", heap[5]);
    print_heap(heap, SIZE);
    printf("\n");

    changePriority(heap, &SIZE, 3, 41);
    printf(">> The priority of the element with priority %d has been updated\nqueue: ", heap[3]);
    print_heap(heap, SIZE);

    return 0;
}
