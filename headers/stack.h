#pragma once
/**
 *  @file stack.h
 *  @brief Dynamic stack implementation in C
 *
 *  Provides functions to initialize, manipulate, inspect, and free stacks.
 *  Designed with dynamic memory management and generic type data.
 * 
 *  Author: Giorgos Apostolakis
 *  Date: 2025-10-21
 */
#include <stdbool.h>
/*  -------------------------------------------------------------------------- 
                                STACK MACROS
    -------------------------------------------------------------------------- */
#define STACK_EMPTY             -9999   /**< Stack is empty. */
#define STACK_NULL              -9998   /**< Null pointer passed as Stack. */
#define STACK_ALLOCATION_FAILED -9997   /**< Memory Allocation failed */

#define STACK_SUCCESS           1       /**< Operation is successfull */

/**
 * @struct Stack
 * @brief Represents the Stack itself
 */
typedef struct Stack Stack;

/**
 * @brief Initialises the stack and allocates the necessary memory
 * @param[out] stack Pointer to the stack
 * @return Appropriate MACRO depending the result
 * @note Caller must call Stack_Free() to avoid memory leaks
 */
int Stack_Init(Stack **stack,size_t elem_size);
/**
 * @brief Pushes a new node to the top of the stack
 * @param[in,out] stack Pointer to the stack
 * @param[in] value Value of the new node
 * @return Appropriate MACRO depending the result
 */
int Stack_Push(Stack **stack, const void* value);
/**
 * @brief Pops the top node of the stack ( removes it and returns its value)
 * @param[in,out] stack Pointer to the stack
 * @param[out] out Value of top element.
 * @return Appropriate MACRO depending on the result.
 */
int Stack_Pop(Stack **stack,void* out);
/**
 * @brief returns the value of the top node if a node exists
 * @param[in] stack The stack
 * @param[out] out Value of top element
 * @return Appropriate MACRO depending the result
 */
int Stack_Peek(const Stack *stack,void* out);
/**
 * @brief returns the size of the stack
 * @param[in] stack The stack
 * @return Size of stack , appropriate MACRO in case of error
 */
int Stack_GetSize(const Stack *stack);

/**
 * @brief Gives a bool value of the stack being empty or not
 * @param stack The stack
 * @return true in case the stack is empty , false in case the stack isnt empty
 */
bool Stack_IsEmpty(const Stack *stack);
/**
 * @brief Frees all the allocated memory the stack has occupied
 * @param stack Pointer to the stack
 */
void Stack_Free(Stack **stack);
