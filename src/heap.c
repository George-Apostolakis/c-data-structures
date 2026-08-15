#include "../headers/heap.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Heap
{
    void *data;
    size_t elem_size;
    Heap_CompareFn compare_fn;

    int size;
    int capacity;
};

int Heap_CreateHeap(Heap **heap, size_t elements_size, Heap_CompareFn compare_function)
{
    if (!heap)
    {
        fprintf(stderr, "Heap_CreateHeap: ERROR double pointer is NULL\n");
        return HEAP_NULL;
    }
    *heap = (Heap *)malloc(sizeof(Heap));
    if (!(*heap))
    {
        fprintf(stderr, "Heap_CreateHeap: ERROR Memory allocaton failed\n");
        return HEAP_MALLOC_FAILED;
    }

    (*heap)->data = (void *)malloc(elements_size * HEAP_INITIAL_CAPACITY);
    if (!(*heap)->data)
    {
        fprintf(stderr, "Heap_CreateHeap: ERROR Memory allocaton failed\n");
        return HEAP_MALLOC_FAILED;
    }
    (*heap)->compare_fn = compare_function;
    (*heap)->capacity = HEAP_INITIAL_CAPACITY;
    (*heap)->size = 0;
    return HEAP_SUCCESS;
}

static int Heap_Grow(Heap *heap)
{
    int newCapacity = heap->capacity * 2;
    void *newData = realloc(heap->data, newCapacity * heap->elem_size);
    if (!newData) return HEAP_MALLOC_FAILED;
    heap->data = newData;
    heap->capacity = newCapacity;
    return HEAP_SUCCESS;
}
/**
 * @brief Adds element to the heap.
 * @param[in,out] heap Pointer to the heap.
 * @param[in] element Element that will be added to the heap.
 * @return HEAP_SUCCESS if operation is successfull,
 *         HEAP_NULL or HEAP_MALLOC_FAILED if operation fails
 */
int Heap_Add(Heap **heap, const void *element)
{
    Heap *dHeap;
    size_t elem_size;
    int i, parent, n, parentN;
    char *buf;
    char *tmp;

    if (!heap)
    {
        fprintf(stderr, "Heap_Add: ERROR double pointer is NULL\n");
        return HEAP_NULL;
    }
    if (!(*heap))
    {
        fprintf(stderr, "Heap_Add: ERROR pointer is NULL (call Heap_CreateHeap first)\n");
        return HEAP_NULL;
    }
    dHeap = *heap;
    elem_size = dHeap->elem_size;

    if (dHeap->size + 1 > dHeap->capacity)
    {
        if (Heap_Grow(dHeap) != HEAP_SUCCESS)
        {
            fprintf(stderr, "Heap_Add: Memory allocation Failed\n");
            return HEAP_MALLOC_FAILED;
        }
    }

    buf = (char *)dHeap->data;
    i = dHeap->size;
    n = i * elem_size;
    memcpy(buf + n, element, elem_size);
    dHeap->size++;

    tmp = malloc(elem_size);
    if (!tmp)
    {
        fprintf(stderr, "Heap_Add: Memory allocation Failed\n");
        return HEAP_MALLOC_FAILED;
    }

    while (i > 0)
    {
        parent = (i - 1) / 2;
        parentN = parent * elem_size;

        if (dHeap->compare_fn(buf + n, buf + parentN) < 0)
        {
            memcpy(tmp, buf + n, elem_size);
            memcpy(buf + n, buf + parentN, elem_size);
            memcpy(buf + parentN, tmp, elem_size);
            i = parent;
            n = parentN;
        }
        else
            break;
    }

    free(tmp);
    return HEAP_SUCCESS;
}

int Heap_Remove(Heap **heap, void *out)
{
    Heap *Dheap;
    int n, child1, child2, chosen;
    size_t element_size;
    bool c1_exists, c2_exists;
    char *tmp;

    if (!heap)
    {
        fprintf(stderr, "Heap_Remove: ERROR double pointer is NULL\n");
        return HEAP_NULL;
    }

    Dheap = *heap;
    if (!Dheap)
    {
        fprintf(stderr, "Heap_Remove: ERROR pointer is NULL (call Heap_CreateHeap first)\n");
        return HEAP_NULL;
    }

    if (Dheap->size == 0)
    {
        fprintf(stderr, "Heap_Remove: ERROR Heap is empty nothing can be removed\n");
        return HEAP_EMPTY;
    }

    element_size = Dheap->elem_size;
    tmp = malloc(element_size);
    if (!tmp)
    {
        fprintf(stderr, "Heap_Remove: ERROR malloc failed\n");
        return HEAP_MALLOC_FAILED;
    }

    memcpy(out, Dheap->data, element_size);

    if (Dheap->size == 1)
    {
        Dheap->size--;
        free(tmp);
        return HEAP_SUCCESS;
    }

    Dheap->size--;
    n = Dheap->size;   /* last original element's index */
    memcpy(Dheap->data, (char *)Dheap->data + n * element_size, element_size);

    n = 0;
    while (1)
    {
        child1 = (n + 1) * 2 - 1;
        child2 = (n + 1) * 2;

        c1_exists = child1 < Dheap->size;
        c2_exists = child2 < Dheap->size;

        if (c1_exists && c2_exists)
            chosen = (Dheap->compare_fn((char *)Dheap->data + child1 * element_size,
                                        (char *)Dheap->data + child2 * element_size) < 0) ? child1 : child2;
        else if (c1_exists)
            chosen = child1;
        else if (c2_exists)
            chosen = child2;
        else
            break;

        memcpy(tmp, (char *)Dheap->data + n * element_size, element_size);
        memcpy((char *)Dheap->data + n * element_size, (char *)Dheap->data + chosen * element_size, element_size);
        memcpy((char *)Dheap->data + chosen * element_size, tmp, element_size);

        n = chosen;
    }

    free(tmp);
    return HEAP_SUCCESS;
}