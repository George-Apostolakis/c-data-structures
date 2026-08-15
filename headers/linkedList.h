#pragma once

/**
 * @file linkedList.h
 * @brief Dynamic singly linked list implementation in C.
 *
 * Provides basic operations for creating, modifying, querying, and freeing
 * linked lists. Designed for educational and general-purpose usage.
 */

/*  --------------------------------------------------------------------------
                              Error Code Macros                             
    -------------------------------------------------------------------------- */
#define LINKEDLIST_EMPTY -9999             /**< List is empty. */
#define LINKEDLIST_OUTOFBOUNDS -9998       /**< Index out of bounds. */
#define LINKEDLIST_NULL -9997              /**< Null pointer passed as list. */
#define LINKEDLIST_NOTFOUND -9996          /**< Element not found in list. */
#define LINKEDLIST_ALLOCATION_FAILED -9995 /**< Malloc failed */
// #define DEBUG

/**
 * @struct Node
 * @brief Represents a single node in the linked list.
 */
typedef struct Node Node;

/**
 * @struct List
 * @brief Represents the linked list itself.
 */
typedef struct List List;

/**
 * @brief Creates an empty linked list
 * @param list a pointer to the list itself
 * @return 1 if process is successful , appropriate MACRO in case of error
 * @note Caller must call LinkedList_Free() to avoid memory leaks
 */
int LinkedList_CreateEmpty(List **list);

/**
 * @brief Add a new node at the end of the list
 * @param list a pointer to the list itself
 * @param value the value of the new element
 * @return returns 1 if addition of new element succeeds, Appropriate MACRO in case it fails
 */
int LinkedList_AddToEnd(List **list, int value);

/**
 * @brief Add a new node at the start of the list
 * @param list a pointer to the list itself
 * @param value the value of the new element
 * @return returns 1 if addition of new element succeeds, Appropriate MACRO in case it fails
 */
int LinkedList_AddToStart(List **list, int value);

/**
 * @brief Add a new node at a specific index number of the list
 * @param list a pointer to the list itself
 * @param value the value of the new element
 * @param index the index of the list which the new element will be added
 * @return returns 1 if addition of new element succeeds, Appropriate MACRO in case it fails
 */
int LinkedList_AddAtIndex(List **list, int value, int index);

/**
 * @brief Searches for the value in the list, if it exists the function returns its index
 * @param list a pointer to the list itself
 * @param value the value that will be searched through the list
 * @return returns index of element if process succeeds, Appropriate MACRO if process fails
 */
int LinkedList_Search(const List *list, int value);

/**
 * @brief Searches for the value in the list, if it exists it removes it
 * @param list a pointer to the list itself
 * @param search the value that will be searched through the list
 * @return returns value of removed node if process succeeds, Appropriate MACRO if process fails
 */
int LinkedList_RemoveNode(List **list, int search);

/**
 * @brief Removes the last node of the list
 * @param list a pointer to the list itself
 * @return returns value of Last node, Appropriate MACRO if process fails
 */
int LinkedList_RemoveLast(List **list);

/**
 * @brief Removes the first node of the list
 * @param list a pointer to the list itself
 * @return returns value of First node, Appropriate MACRO if process fails
 */
int LinkedList_RemoveFirst(List **list);

/**
 * @brief Removes the node at the specified index of the list
 * @param list a pointer to the list itself
 * @param index the index of the node that will be deleted
 * @return returns value of node at index, Appropriate MACRO if process fails
 */
int LinkedList_RemoveIndex(List **list, int index);

/**
 * @brief Returns the size of the list
 * @param list the list
 * @return an integer equal to the size of the list, Appropriate MACRO if process fails
 */
int LinkedList_GetLength(const List *list);

/**
 * @brief Frees all the memory the list has occupied
 * @param list a pointer to the list itself
 */
void LinkedList_Free(List **list);

/**
 * @brief Prints the list in format [ value[0] , value[1] , ... value[n] ]
 * @param list the list to print
 */
void LinkedList_Print(const List *list);