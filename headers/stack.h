#pragma once
/**
 *  @file stack.h
 *  @brief Dynamic stack implementation in C.
 *
 *  Provides functions to initialize, manipulate, inspect, and free stacks.
 *  Designed with dynamic memory management and generic type data.
 */
#include <stdbool.h>
#include <stddef.h>
/*  -------------------------------------------------------------------------- 
                                STACK MACROS
    -------------------------------------------------------------------------- */
#define STACK_EMPTY             -9999   /**< Stack is empty. */
#define STACK_NULL              -9998   /**< Null pointer passed as Stack. */
#define STACK_ALLOCATION_FAILED -9997   /**< Memory Allocation failed */

#define STACK_SUCCESS           1       /**< Operation was successful */

/**
 * @struct Stack
 * @brief Represents the Stack itself
 */
typedef struct Stack Stack;

/**
 * @brief Initializes the stack and allocates the necessary memory
 * @param[out] stack Pointer to the stack
 * @param[in] elem_size Size in bytes of the elements that will be stored in the stack
 * @return Appropriate MACRO depending the result
 * @note Caller must call Stack_Free() to avoid memory leaks
 */
int Stack_Init(Stack **stack,size_t elem_size);
/**
 * @brief Pushes a new value onto the top of the stack
 * @param[in,out] stack Pointer to the stack
 * @param[in] value Pointer to the value to copy onto the stack
 * @return Appropriate MACRO depending the result
 */
int Stack_Push(Stack **stack, const void* value);
/**
 * @brief Pops the top element off the stack (removes it and copies out its value)
 * @param[in,out] stack Pointer to the stack
 * @param[out] out Buffer to copy the top element's value into.
 * @return Appropriate MACRO depending on the result.
 */
int Stack_Pop(Stack **stack,void* out);
/**
 * @brief Returns the value of the top element if one exists
 * @param[in] stack The stack
 * @param[out] out Buffer to copy the top element's value into
 * @return Appropriate MACRO depending the result
 */
int Stack_Peek(const Stack *stack,void* out);
/**
 * @brief Returns the size of the stack
 * @param[in] stack The stack
 * @return Size of stack , appropriate MACRO in case of error
 */
int Stack_GetSize(const Stack *stack);

/**
 * @brief Gives a bool value of whether the stack is empty or not
 * @param stack The stack
 * @return true if the stack is empty, false if the stack isn't empty
 */
bool Stack_IsEmpty(const Stack *stack);
/**
 * @brief Frees all the allocated memory the stack has occupied
 * @param stack Pointer to the stack
 */
void Stack_Free(Stack **stack);
