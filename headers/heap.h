#pragma once

/**
 * @file heap.h
 * @brief Dynamic max heap implementation in C.
 *
 * Provides basic operations for creating, adding, deleting elements, and freeing
 * the heap. Designed for educational and general-purpose usage.
 */

#include <stddef.h>

#define HEAP_INITIAL_CAPACITY 8

typedef int (*Heap_CompareFn)(const void *a, const void *b);

/**
 * @struct Heap
 * @brief  Represents the max heap itself.
 */
typedef struct Heap Heap;

/*  -----------------------------------------------------------
                        Heap Return Codes
    -----------------------------------------------------------*/
#define HEAP_NULL -9999          /**< Null pointer is passed as heap*/
#define HEAP_MALLOC_FAILED -9998 /**< Malloc failed */
#define HEAP_EMPTY -9997         /**< Heap is empty when it shouldn't be */
#define HEAP_SUCCESS 1           /**< Operation was completed successfully */

/**
 * @brief Creates an empty heap.
 * @param[out] heap Pointer to the heap.
 * @param[in]  elements_size Size of elements that will be saved inside the heap
 * @param[in]  compare_function Function that decides which of 2 elements is bigger
 * @return  HEAP_SUCCESS if the operation is successful,
 *          HEAP_NULL or HEAP_MALLOC_FAILED if the operation fails
 * @note Time Complexity O(1).
 */
int Heap_CreateHeap(Heap **heap, size_t elements_size, Heap_CompareFn compare_function);

/**
 * @brief Adds element to the heap.
 * @param[in,out] heap Pointer to the heap.
 * @param[in] element Element that will be added to the heap.
 * @return HEAP_SUCCESS if the operation is successful,
 *         HEAP_NULL or HEAP_MALLOC_FAILED if the operation fails
 * @note Time Complexity worst & avg case: O(logn), best case O(1).
 */
int Heap_Add(Heap **heap, const void *element);

/**
 * @brief Removes top element of the heap.
 * @param[in,out] heap Pointer to the heap.
 * @param[out] out Top element that was removed.
 * @return HEAP_SUCCESS if the operation is successful,
 *         HEAP_NULL, HEAP_EMPTY, or HEAP_MALLOC_FAILED
 *         if the operation fails
 * @note Time Complexity O(logn).
 */
int Heap_Remove(Heap **heap, void *out);

/**
 * @brief Creates a heap from an array.
 * @param[in] array_to_heap Starting unordered array.
 * @param[in] array_size Number of elemets on the array.
 * @param[in] elements_size Size of elements that will be saved inside the heap.
 * @param[in] compare_function Function that decides which of 2 elements is bigger.
 * @return Pointer to the created heap.
 */
Heap *Heap_Heapify(void *array_to_heap,int array_size, size_t element_size, Heap_CompareFn compare_function);