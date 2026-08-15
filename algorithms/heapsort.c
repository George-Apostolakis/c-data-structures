/**
 * @file heapsort.c
 * @brief Implementation of the heapsort algorithm using the Heap from heap.h.
 */

/**
 * How heapsort works:
 *
 * Steps:
 *      - Add every element to a heap (here, a min heap).
 *      - Repeatedly remove the root (the smallest remaining element)
 *        to build the sorted output. That's basically it.
 *
 * Complexity:
 *      best case       O(n log(n))
 *      worst case      O(n log(n))
 *      average case    O(n log(n))
 */

#include "../headers/heap.h"
#include <stdio.h>

int array_to_sort[10] = {1, 5, 12, 2, 7, 6, 86, 32, 21, 6};
int sorted_array[10];

// This will create a min heap
int heap_cmpr(const void*a , const void* b){
    return *((int*)a) - *((int *)b);
}

int main(){
    Heap* myHeap;
    int i;
    Heap_CreateHeap(&myHeap,sizeof(int),heap_cmpr);

    for(i=0;i<10;i++)
        Heap_Add(&myHeap, array_to_sort+i);
    
    for(i=0;i<10;i++){
        Heap_Remove(&myHeap,sorted_array+i);
        printf("%d ", sorted_array[i]);
    }

    return 0;
}