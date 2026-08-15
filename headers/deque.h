#pragma once
/**
 * @file Deque.h
 * @brief Dynamically allocated implementation of a deque
 * (a doubly linked queue whose front and rear can both be enqueued
 * and dequeued, supporting both FIFO and LIFO usage).
 *
 * Provides all the basic operations of a deque: adding new elements (enqueue),
 * removing elements (dequeue) from either end, printing the list, and inspecting
 * elements of the list.
 */

#include <stdbool.h>
/*------------------------------------------------------------------------------*/
/*                           ERROR CODE MACROS                                  */
/*------------------------------------------------------------------------------*/
#define DEQUE_EMPTY             -9999   /**< Deque is empty. */
#define DEQUE_NULL              -9998   /**< Null pointer passed as Deque. */
#define DEQUE_ALLOCATION_FAILED -9997   /**< Memory allocation failed. */
/**
 * @struct Node
 * @brief Represents a single Node of the Deque
 */
typedef struct Node Node;
/**
 * @struct Deque
 * @brief Represents the Deque
 */
typedef struct Deque Deque;

/**
 * @brief Creates an empty deque ( Allocates the necessary memory ).
 * @param[out] deque Double pointer to the deque.
 * @return 1 in case process is successful , appropriate DEQUE_* if it is not
 * @note Caller must call Deque_Free() to avoid memory leaks.
 */
int Deque_CreateEmpty(Deque **deque);
/**
 * @brief Inserts a value at the front of the deque.
 * @param[in,out] deque Double pointer to the deque.
 * @param[in] value Integer value to insert.
 * @return 1 if process is successful, or appropriate DEQUE_* error code.
 */
int Deque_PushFront(Deque **deque, int value);

/**
 * @brief Inserts a value at the rear of the deque.
 * @param[in,out] deque Double pointer to the deque.
 * @param[in] value Integer value to insert.
 * @return 1 if process is successful, or appropriate DEQUE_* error code.
 */
int Deque_PushBack(Deque **deque, int value);
/**
 * @brief Removes a value from the front of the deque.
 * @param[in,out] deque Double pointer to the deque.
 * @return Value removed, or appropriate DEQUE_* error code.
 */
int Deque_PopFront(Deque **deque);

/**
 * @brief Removes a value from the rear of the deque
 * @param[in,out] deque Double pointer to the deque
 * @return Value removed, or appropriate DEQUE_* error code
 */
int Deque_PopBack(Deque **deque);
/**
 * @brief Retrieves the value of the front Node
 * @param[in] deque Pointer to the deque
 * @return Value of first element , or appropriate DEQUE_* error code
 */
int Deque_PeekFront(Deque *deque);

/**
 * @brief Retrieves the value of the rear Node
 * @param[in] deque Pointer to the deque.
 * @return Value of last element , or appropriate DEQUE_* error code
 */
int Deque_PeekBack(Deque *deque);
/**
 * @brief Returns the size of the deque (Number of the elements).
 * @param deque Pointer to the deque.
 * @return Number of elements, or appropriate DEQUE_* error code
 */
int Deque_GetSize(Deque *deque);

/**
 * @brief Prints the deque (front to rear)
 * @param[in] deque Pointer to the deque
 */
void Deque_Print(Deque *deque);
/**
 * @brief Frees all memory associated with the deque.
 * @param[in,out] deque Double pointer to the deque , set to NULL after call.
 */
void Deque_Free(Deque **deque);