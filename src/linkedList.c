#include "../headers/linkedList.h"
#include <stdlib.h> // for NUll
#include <stdio.h>

struct Node
{
    int value;
    struct Node *next;
};

struct List
{
    int size;
    Node *head;
    Node *tail;
};

int LinkedList_CreateEmpty(List **list)
{
    if (!list)
    {
        fprintf(stderr, "LinkedList_CreateEmpty: ERROR double pointer is NULL\n");
        return LINKEDLIST_NULL;
    }

    *list = (List *)malloc(sizeof(List));
    if (!(*list))
    {
        fprintf(stderr, "LinkedList_CreateEmpty: Memory allocation failed\n");
        return LINKEDLIST_ALLOCATION_FAILED;
    }

    (*list)->head = NULL;
    (*list)->tail = NULL;
    (*list)->size = 0;
}

int LinkedList_AddToEnd(List **list, int value)
{
    Node *newNode;
    if (!list)
    {
        fprintf(stderr, "LinkedList_AddToEnd: ERROR double pointer is NULL\n");
        return LINKEDLIST_NULL;
    }

    if (!(*list))
    {
        fprintf(stderr, "LinkedList_AddToEnd: ERROR list pointer is NULL\n");
        return LINKEDLIST_NULL;
    }

    newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        fprintf(stderr, "LinkedList_AddToEnd: Memory allocation failed\n");
        return LINKEDLIST_ALLOCATION_FAILED;
    }
    newNode->value = value;
    newNode->next = NULL;

    if ((*list)->tail == NULL)
    {
        (*list)->head = newNode;
        (*list)->tail = newNode;
    }
    else
    {
        (*list)->tail->next = newNode;
        (*list)->tail = newNode;
    }
    (*list)->size++;
    return 1;
}

int LinkedList_AddToStart(List **list, int value)
{
    Node *newNode;

    if (!list)
    {
        fprintf(stderr, "LinkedList_AddToStart: ERROR double pointer is NULL\n");
        return LINKEDLIST_NULL;
    }
    if (!*list)
    {
        fprintf(stderr, "LinkedList_AddToStart: ERROR list is NULL\n");
        return LINKEDLIST_NULL;
    }
    newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        fprintf(stderr, "LinkedList_AddToStart: Memory allocation failed\n");
        return LINKEDLIST_ALLOCATION_FAILED;
    }

    newNode->value = value;
    newNode->next = (*list)->head;
    (*list)->head = newNode;

    if ((*list)->tail == NULL)
        (*list)->tail = newNode;

    (*list)->size++;
    return 1;
}

int LinkedList_AddAtIndex(List **list, int value, int index)
{
    Node *newNode, *temp;
    int i;
    if (!list)
    {
        fprintf(stderr, "LinkedList_AddAtIndex: ERROR double pointer is NULL\n");
        return LINKEDLIST_NULL;
    }
    if (!(*list))
    {
        fprintf(stderr, "LinkedList_AddAtIndex: ERROR list is NULL\n");
        return LINKEDLIST_NULL;
    }

    if (index > (*list)->size || index < 0)
    {
        fprintf(stderr, "LinkedList_AddAtIndex: ERROR list is too small to add to index %d\n", index);
        return LINKEDLIST_OUTOFBOUNDS;
    }

    newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        fprintf(stderr, "LinkedList_AddAtIndex: Memory allocation failed\n");
        return LINKEDLIST_ALLOCATION_FAILED;
    }

    newNode->value = value;
    // Case 1: Empty List
    if ((*list)->head == NULL)
    {
        newNode->next = NULL;
        (*list)->head = newNode;
        (*list)->tail = newNode;
    }
    // Case 2: Insert At head
    else if (index == 0)
    {
        newNode->next = (*list)->head;
        (*list)->head = newNode;
    }
    // Case 3: Insert At tail
    else if (index == (*list)->size)
    {
        newNode->next = NULL;
        (*list)->tail->next = newNode;
        (*list)->tail = newNode;
    }
    // Case 4: Insert At middle
    else
    {
        temp = (*list)->head;
        i = 0;
        while (i < index - 1)
        {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    (*list)->size++;
    return 1;
}

int LinkedList_Search(const List *list, int value)
{
    Node *tmp;
    int i;
    if (!list)
    {
        fprintf(stderr, "LinkedList_Search: ERROR list is NULL\n");
        return LINKEDLIST_NULL;
    }
    // CASE1: Empty list
    if (list->size == 0)
    {
        fprintf(stderr, "LinkedList_Search: ERROR list EMPTY\n");
        return LINKEDLIST_EMPTY;
    }
    i = 0;
    tmp = list->head;
    while (tmp != NULL)
    {
        if (tmp->value == value)
            return i;
        i++;
        tmp = tmp->next;
    }
    return LINKEDLIST_NOTFOUND;
}

int LinkedList_RemoveNode(List **list, int search)
{
    int index, i, return_value;
    Node *tmp, *to_beFreed;

    if (!list)
    {
        fprintf(stderr, "LinkedList_RemoveNode: ERROR double pointer is NULL\n");
        return LINKEDLIST_NULL;
    }
    if (!(*list))
    {
        fprintf(stderr, "LinkedList_RemoveNode: ERROR list is NULL\n");
        return LINKEDLIST_NULL;
    }
    if ((*list)->size == 0)
    {
        fprintf(stderr, "LinkedList_RemoveNode: ERROR list EMPTY\n");
        return LINKEDLIST_EMPTY;
    }
    if ((index = LinkedList_Search(*list, search)) != LINKEDLIST_NOTFOUND)
    {
        // case 1 : remove first
        if (index == 0)
            return LinkedList_RemoveFirst(list);
        // case 2 : remove last
        if (index == (*list)->size - 1)
            return LinkedList_RemoveLast(list);

        tmp = (*list)->head;
        i = 0;
        while (i < index - 1)
        {
            if (tmp != NULL)
            {
                i++;
                tmp = tmp->next;
            }
            else
            {
                return LINKEDLIST_NOTFOUND;
            }
        }
        return_value = tmp->next->value;
        to_beFreed = tmp->next;
        tmp->next = tmp->next->next;
        (*list)->size--;
        free(to_beFreed);
        return return_value;
    }
    else
    {
        return LINKEDLIST_NOTFOUND;
    }
}

int LinkedList_RemoveLast(List **list)
{
    Node *free_node, *tmp;
    int return_value;
    if (!list)
    {
        fprintf(stderr, "LinkedList_RemoveLast: ERROR double pointer is NULL\n");
        return LINKEDLIST_NULL;
    }
    if (!(*list))
    {
        fprintf(stderr, "LinkedList_RemoveLast: ERROR list is NULL\n");
        return LINKEDLIST_NULL;
    }
    // CASE1: Empty list
    if ((*list)->size == 0)
    {
        fprintf(stderr, "LinkedList_RemoveLast: ERROR list EMPTY\n");
        return LINKEDLIST_EMPTY;
    }
    // CASE2: 1 Node (head == tail)
    if ((*list)->size == 1)
    {
        free_node = (*list)->head;
        return_value = free_node->value;
        (*list)->head = NULL;
        (*list)->tail = NULL;
        (*list)->size = 0;
        free(free_node);
        return return_value;
    }

    // CASE3: >1 Node
    tmp = (*list)->head;
    while (tmp->next != (*list)->tail)
    {
        tmp = tmp->next;
    }

    free_node = (*list)->tail;
    return_value = free_node->value;
    tmp->next = NULL;
    (*list)->tail = tmp;
    free(free_node);
    (*list)->size--;

    return return_value;
}

int LinkedList_RemoveFirst(List **list)
{
    Node *toBeFreed;
    int return_value;
    // CASE1: NULL LIST
    if (!list)
    {
        fprintf(stderr, "LinkedList_RemoveFirst: ERROR double pointer is NULL\n");
        return LINKEDLIST_NULL;
    }
    if (!(*list))
    {
        fprintf(stderr, "LinkedList_RemoveFirst: ERROR list is NULL\n");
        return LINKEDLIST_NULL;
    }
    // CASE2: Empty list
    if ((*list)->size == 0)
    {
        fprintf(stderr, "LinkedList_RemoveFirst: ERROR list EMPTY\n");
        return LINKEDLIST_EMPTY;
    }
    return_value = (*list)->head->value;
    toBeFreed = (*list)->head;
    (*list)->head = (*list)->head->next;
    free(toBeFreed);
    // CASE : LIST IS NOW EMPTY
    if ((*list)->head == NULL)
    {
        (*list)->tail = NULL;
    }
    (*list)->size--;
    return return_value;
}

int LinkedList_RemoveIndex(List **list, int index)
{
    int i, return_value;
    Node *tmp, *to_beFreed;

    if (!list)
    {
        fprintf(stderr, "LinkedList_RemoveIndex: ERROR double pointer is NULL\n");
        return LINKEDLIST_NULL;
    }
    if (!(*list))
    {
        fprintf(stderr, "LinkedList_RemoveIndex: ERROR list is NULL\n");
        return LINKEDLIST_NULL;
    }
    if ((*list)->size == 0)
    {
        fprintf(stderr, "LinkedList_RemoveIndex: ERROR list EMPTY\n");
        return LINKEDLIST_EMPTY;
    }
    // case 1 : remove first
    if (index == 0)
        return LinkedList_RemoveFirst(list);
    // case 2 : remove last
    if (index == (*list)->size - 1)
        return LinkedList_RemoveLast(list);

    tmp = (*list)->head;
    i = 0;
    while (i < index - 1)
    {
        if (tmp != NULL)
        {
            i++;
            tmp = tmp->next;
        }
        else
        {
            return LINKEDLIST_NOTFOUND;
        }
    }
    return_value = tmp->next->value;
    to_beFreed = tmp->next;
    tmp->next = tmp->next->next;
    (*list)->size--;
    free(to_beFreed);
    return return_value;
}

int LinkedList_GetLength(const List *list)
{
    if (!list)
        return LINKEDLIST_NULL;

    return list->size;
}

void LinkedList_Free(List **list)
{
    Node *tmp, *toBeFreed;

    // CASE1: NULL LIST
    if (!list)
        return;

    if (!(*list))
        return;
    // CASE2: Empty list
    if ((*list)->size == 0)
    {
        fprintf(stderr, "LinkedList_Free: ERROR list EMPTY\n");
        return;
    }
    // CASE3: NORMAL CASE
    tmp = (*list)->head;
    while (tmp != NULL)
    {
        toBeFreed = tmp;
        tmp = tmp->next;
        free(toBeFreed);
    }
    // Reset the list to empty state
    free(*list);
    *list = NULL;
}

void LinkedList_Print(const List *list)
{
    Node *tmp;

    if (!list)
    {
        fprintf(stderr, "LinkedList_Print: ERROR list is NULL\n");
        return;
    }

    printf("head = \"%p\"\n", list->head);
#ifdef DEBUG
    tmp = list->head;
    while (tmp != NULL)
    {
        printf("(%p)[ %d --> %p ] --> ", tmp, tmp->value, tmp->next);
        tmp = tmp->next;
    }
#else
    tmp = list->head;
    printf("[ ");
    while (tmp != NULL)
    {
        printf("%d", tmp->value);
        if (tmp->next != NULL)
            printf(" , ");
        tmp = tmp->next;
    }
    printf(" ]");

#endif
    printf("\ntail = \"%p\"\n", list->tail);
}