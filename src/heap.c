#include "../headers/heap.h"

#include <stdio.h>
#include <stdlib.h>

struct Heap{
    void* data;
    //size_t elem_size;
    //Heap_CompareFn compare;
    int total;
    int capacity;
};

int Heap_CreateHeap(Heap** heap){
    if(!heap)
    {
        fprintf(stderr,"Heap_CreateHeap: ERROR double pointer is NULL\n");
        return HEAP_NULL;
    }
    *heap = (Heap*)malloc(sizeof(Heap));

    (*heap)->capacity ;
    return HEAP_SUCCESS;
}

/**
 * @brief Adds element to the heap.
 * @param[in,out] heap Pointer to the heap.
 * @param[in] element Element that will be added to the heap.
 * @return HEAP_SUCCESS if operation is successfull,
 *         HEAP_NULL or HEAP_MALLOC_FAILED if operation fails
 */
int Heap_Add(Heap** heap, int element){
    if(!heap)
    {
        fprintf(stderr,"Heap_Add: ERROR double pointer is NULL\n");
        return HEAP_NULL;
    }


}

/**
 * @brief Removes top element of the heap.
 * @param[in,out] heap Pointer to the heap.
 * @return Removed number if operation is successfull,
 *         HEAP_NULL if operation fails
 */
int Heap_Remove(Heap** heap);
