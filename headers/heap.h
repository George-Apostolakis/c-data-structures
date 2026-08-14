#pragma once

/**
 * @file heap.h
 * @brief Dynamic max heap implementation in C.
 *
 * Provides basic operations for creating, adding, deleting elements, and freeing
 * the heap. Designed for educational and general-purpose usage.
 *
 * Author: Giorgos Apostolakis
 * @date   2026-8-14
 */

#define HEAP_INITIAL_CAPACITY   8

/**
 * @struct Heap
 * @brief  Represents the max heap itself.
 */
typedef struct Heap Heap;

/*  -----------------------------------------------------------
                        Heap Return Codes
    -----------------------------------------------------------*/
#define HEAP_NULL           -9999   /**< Null pointer is passed as heap*/
#define HEAP_MALLOC_FAILED  -9998   /**< Malloc failed */
#define HEAP_SUCCESS        1       /**< Operation was completed successfully */

/**
 * @brief Creates an empty heap.
 * @param[out] heap Pointer to the heap.
 * @return  HEAP_SUCCESS if operation is successfull,
 *          HEAP_NULL or HEAP_MALLOC_FAILED if operation fails
 */
int Heap_CreateHeap(Heap** heap);

/**
 * @brief Adds element to the heap.
 * @param[in,out] heap Pointer to the heap.
 * @param[in] element Element that will be added to the heap.
 * @return HEAP_SUCCESS if operation is successfull,
 *         HEAP_NULL or HEAP_MALLOC_FAILED if operation fails
 */
int Heap_Add(Heap** heap, int element);

/**
 * @brief Removes top element of the heap.
 * @param[in,out] heap Pointer to the heap.
 * @return Removed number if operation is successfull,
 *         HEAP_NULL if operation fails
 */
int Heap_Remove(Heap** heap);
