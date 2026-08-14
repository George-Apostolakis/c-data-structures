#include "../headers/deque.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * @file deque.c
 * @brief implementation of deque.h functions
 */
#define DEQUE_VALIDATE(ptr, ret_val)                    \
    do                                                  \
    {                                                   \
        if ((ptr) == NULL)                              \
        {                                               \
            fprintf(stderr,                             \
                    "[Deque Error] %s: NULL pointer\n", \
                    __func__);                          \
            return (ret_val);                           \
        }                                               \
    } while (0)

struct Node
{
    int value;
    Node *next;
    Node *prev;
};
struct Deque
{
    int size;
    Node *front;
    Node *rear;
};

int Deque_CreateEmpty(Deque **deque)
{
    DEQUE_VALIDATE(deque, DEQUE_NULL);

    *deque = (Deque *)malloc(sizeof(Deque));
    DEQUE_VALIDATE(*deque, DEQUE_ALLOCATION_FAILED);

    (*deque)->front = NULL;
    (*deque)->rear = NULL;
    (*deque)->size = 0;

    return 1;
}

int Deque_PushFront(Deque **deque, int value)
{
    Node *newNode;

    DEQUE_VALIDATE(deque, DEQUE_NULL);
    DEQUE_VALIDATE(*deque, DEQUE_NULL);

    newNode = (Node *)malloc(sizeof(Node));
    DEQUE_VALIDATE(newNode, DEQUE_ALLOCATION_FAILED);

    newNode->value = value;
    if ((*deque)->size == 0)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        (*deque)->front = newNode;
        (*deque)->rear = newNode;
        (*deque)->size = 1;
    }
    else
    {
        newNode->next = (*deque)->front;
        newNode->prev = NULL;
        (*deque)->front->prev = newNode;
        (*deque)->front = newNode;
        (*deque)->size++;
    }
    return 1;
}

int Deque_PushBack(Deque **deque, int value)
{
    Node *newNode;

    DEQUE_VALIDATE(deque, DEQUE_NULL);
    DEQUE_VALIDATE(*deque, DEQUE_NULL);

    newNode = (Node *)malloc(sizeof(Node));
    DEQUE_VALIDATE(newNode, DEQUE_ALLOCATION_FAILED);

    newNode->value = value;
    if ((*deque)->size == 0)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        (*deque)->front = newNode;
        (*deque)->rear = newNode;
        (*deque)->size = 1;
    }
    else
    {
        newNode->next = NULL;
        newNode->prev = (*deque)->rear;
        (*deque)->rear->next = newNode;
        (*deque)->rear = newNode;
        (*deque)->size++;
    }
    return 1;
}

int Deque_PopFront(Deque **deque)
{
    Node *toFree;
    DEQUE_VALIDATE(deque, DEQUE_NULL);
    DEQUE_VALIDATE(*deque, DEQUE_NULL);
    int returnValue;

    if ((*deque)->size == 0)
    {
        fprintf(stderr, "[Deque Error] %s: Deque cant be empty\n", __func__);
        return (DEQUE_EMPTY);
    }
    else if ((*deque)->size == 1)
    {
        toFree = (*deque)->front;
        returnValue = toFree->value;
        (*deque)->front = NULL;
        (*deque)->rear = NULL;
        (*deque)->size = 0;
        free(toFree);
        return returnValue;
    }
    else
    {
        toFree = (*deque)->front;
        returnValue = toFree->value;
        (*deque)->front = (*deque)->front->next;
        (*deque)->front->prev = NULL;
        (*deque)->size--;
        free(toFree);
        return returnValue;
    }
}

int Deque_PopBack(Deque **deque)
{
    Node *toFree;
    DEQUE_VALIDATE(deque, DEQUE_NULL);
    DEQUE_VALIDATE(*deque, DEQUE_NULL);
    int returnValue;

    if ((*deque)->size == 0)
    {
        fprintf(stderr, "[Deque Error] %s: Deque cant be empty\n", __func__);
        return (DEQUE_EMPTY);
    }
    else if ((*deque)->size == 1)
    {
        toFree = (*deque)->rear;
        returnValue = toFree->value;
        (*deque)->front = NULL;
        (*deque)->rear = NULL;
        (*deque)->size = 0;
        free(toFree);
        return returnValue;
    }
    else
    {
        toFree = (*deque)->rear;
        returnValue = toFree->value;
        (*deque)->rear = (*deque)->rear->prev;
        (*deque)->rear->next = NULL;
        (*deque)->size--;
        free(toFree);
        return returnValue;
    }
}

int Deque_PeekFront(Deque *deque)
{
    DEQUE_VALIDATE(deque, DEQUE_NULL);

    if (deque->size == 0)
    {
        fprintf(stderr, "[Deque Error] %s: Deque cant be empty\n", __func__);
        return (DEQUE_EMPTY);
    }
    else
        return deque->front->value;
}

int Deque_PeekBack(Deque *deque)
{
    DEQUE_VALIDATE(deque, DEQUE_NULL);

    if (deque->size == 0)
    {
        fprintf(stderr, "[Deque Error] %s: Deque cant be empty\n", __func__);
        return (DEQUE_EMPTY);
    }
    else
        return deque->rear->value;
}

int Deque_GetSize(Deque *deque)
{
    DEQUE_VALIDATE(deque, DEQUE_NULL);

    return deque->size;
}

void Deque_Print(Deque *deque)
{
    Node *tmp;
    if(!deque)
        return;
    printf("Queue (size=%d) [", deque->size);
    tmp = deque->front;
    while (tmp)
    {
        printf(" %d ", tmp->value);
        if (tmp != deque->rear)
            printf(",");
        tmp = tmp->next;
    }
    printf("]\n");
}

void Deque_Free(Deque **deque){
    Node*tmp,*toFree;
    if(!deque)
        return;
    if(!*deque)
        return;
    tmp=(*deque)->front;
    while(tmp){
        toFree=tmp;
        tmp=tmp->next;
        free(toFree);
    }
    free(*deque);
    *deque=NULL;
}