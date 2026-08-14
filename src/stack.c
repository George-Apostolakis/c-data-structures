#include "../headers/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @file stack.c
 */

typedef struct Node
{
    void* value;
    struct Node *next;
}Node;

struct Stack
{
    Node *top;
    size_t elementSize;
    int size;
};

int Stack_Init(Stack **stack, size_t elem_size)
{
    if (!stack)
    {
        fprintf(stderr, "Stack_Init: Double pointer cannot be NULL\n");
        return STACK_NULL;
    }
    (*stack) = (Stack *)malloc(sizeof(Stack));
    if (!(*stack))
    {
        fprintf(stderr, "Stack_Init: Malloc Failed\n");
        return STACK_ALLOCATION_FAILED;
    }
    (*stack)->size = 0;
    (*stack)->elementSize = elem_size;
    (*stack)->top = NULL;

    return STACK_SUCCESS;
}

int Stack_Push(Stack **stack, const void* value)
{
    Node *newNode;
    size_t elem_size;

    if (!stack)
    {
        fprintf(stderr, "Stack_Push: Double pointer cannot be NULL\n");
        return STACK_NULL;
    }
    if (!(*stack))
    {
        fprintf(stderr, "Stack_Push: Stack cannot be NULL\n");
        return STACK_NULL;
    }
    elem_size = (*stack)->elementSize;
    
    newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        fprintf(stderr, "Stack_Push: Memory allocation Failed\n");
        return STACK_ALLOCATION_FAILED;
    }

    newNode->value = (void*) malloc(elem_size);
    if(!newNode->value){
        free(newNode);
        fprintf(stderr, "Stack_Push: Memory allocation Failed\n");
        return STACK_ALLOCATION_FAILED;
    }
    memcpy(newNode->value,value,elem_size);

    newNode->next = (*stack)->top;

    (*stack)->size++;
    (*stack)->top = newNode;
    return STACK_SUCCESS;
}
    
int Stack_Pop(Stack **stack, void* out)
{
    Node *toFree;
    if (!stack)
    {
        fprintf(stderr, "Stack_Pop: Double pointer cannot be NULL\n");
        return STACK_NULL;
    }
    if (!(*stack))
    {
        fprintf(stderr, "Stack_Pop: Stack cannot be NULL\n");
        return STACK_NULL;
    }
    if ((*stack)->size == 0)
    {
        fprintf(stderr, "Stack_Pop: Stack is Empty\n");
        return STACK_EMPTY;
    }
    memcpy(out,(*stack)->top->value,(*stack)->elementSize);

    toFree = (*stack)->top;
    (*stack)->top = (*stack)->top->next;

    free(toFree->value);
    free(toFree);
    (*stack)->size--;

    return STACK_SUCCESS;
}

int Stack_Peek(const Stack *stack, void* out)
{
    if (!stack)
    {
        fprintf(stderr, "Stack_Peek: Stack cannot be NULL\n");
        return STACK_NULL;
    }

    if (stack->size == 0)
    {
        fprintf(stderr, "Stack_Peek: Stack is Empty\n");
        return STACK_EMPTY;
    }

    memcpy(out,stack->top->value,stack->elementSize);
    return STACK_SUCCESS;
}

int Stack_GetSize(const Stack *stack)
{
    if (!stack)
    {
        fprintf(stderr, "Stack_GetSize: Stack cannot be NULL\n");
        return STACK_NULL;
    }

    return stack->size;
}

bool Stack_IsEmpty(const Stack *stack)
{
    if (!stack)
    {
        return true;
    }

    return (stack->size == 0) ? true : false;
}

void Stack_Free(Stack **stack)
{
    Node *toFree, *tmp;

    if (!stack)
        return;

    if (!(*stack))
        return;

    tmp = (*stack)->top;
    while (tmp != NULL)
    {
        toFree = tmp;
        tmp = tmp->next;
        free(toFree->value);
        free(toFree);
    }
    free(*stack);
    *stack = NULL;
}
