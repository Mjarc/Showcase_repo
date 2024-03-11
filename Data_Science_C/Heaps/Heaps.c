#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include "Heaps.h"

void print_heap(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void max_heapify_recursive(int *arr, int index, int size) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != index) {
        SWAP(arr[index], arr[largest]);
        max_heapify_recursive(arr, largest, size);
    }
}

void build_max_heap(int *arr, int size) {
    for (int i = size / 2 - 1; i >= 0; --i) {
        max_heapify_recursive(arr, i, size);
    }
}

int extractMax(int *arr, int *size) {
    if (*size <= 0) {
        printf("Heap underflow\n");
        return INT_MIN;
    }
    if (*size == 1) {
        (*size)--;
        return arr[0];
    }

    int max = arr[0];
    arr[0] = arr[(*size) - 1];
    (*size)--;
    max_heapify_recursive(arr, 0, *size);
    return max;
}

void bubbleUp(int *arr, int index) {
    while (index > 0 && arr[(index - 1) / 2] < arr[index]) {
        SWAP(arr[index], arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void insertData(int *arr, int *size, int data) {
    (*size)++;
    int index = *size - 1;
    arr[index] = data;
    bubbleUp(arr, index);
}

void removeIndex(int *arr, int *size, int index) {
    arr[index] = INT_MAX;
    bubbleUp(arr, index);
    extractMax(arr, size);
}

void changePriority(int *arr, int *size, int index, int priority) {
    int oldPriority = arr[index];
    arr[index] = priority;
    if (priority > oldPriority) {
        bubbleUp(arr, index);
    } else {
        max_heapify_recursive(arr, index, *size);
    }
}

