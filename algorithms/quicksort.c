#include <stdio.h>

/**
 * @file    quicksort.c
 * @brief   Implementations of QuickSort Algorithm
 */

static void ArrayPrint(int *array, int arraySize)
{
    if (!array)
    {
        printf("[]\n");
        return;
    }

    printf("[ ");
    for (int i = 0; i < arraySize; i++)
        printf("%d%s", array[i], (i == arraySize - 1) ? "" : ", ");
    printf(" ]\n");
}


static int Partition(int *array, int lowIndex, int highIndex)
{
    int pivot = array[lowIndex];
    int i = lowIndex;
    int j = highIndex;
    int temp;

    while (i < j)
    {
        while (array[i] <= pivot && i < highIndex) i++;
        while (array[j] > pivot) j--;

        if (i < j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    
    temp = array[lowIndex];
    array[lowIndex] = array[j];
    array[j] = temp;
    
    return j;
}

/**
 * @brief Sorts array[low..high] in place using the QuickSort algorithm.
 * @param array Array to sort.
 * @param low Lower bound index (inclusive).
 * @param high Upper bound index (inclusive).
 * @param numberOfCalls Counter incremented once per recursive call, for tracking call depth.
 */
void Quicksort(int *array, int low, int high , int* numberOfCalls)
{
    (*numberOfCalls)++;
    if (low < high)
    {
        int pivotIndex = Partition(array, low, high);

        Quicksort(array, low, pivotIndex - 1,numberOfCalls);
        Quicksort(array, pivotIndex + 1, high,numberOfCalls);
    }
}

int main()
{
    int array[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2,1};
    int size = 10;

    printf("Original array: ");
    ArrayPrint(array, size);

    int noc = 0;
    Quicksort(array, 0, size - 1,&noc);
    printf("noc: %d\n",noc);
    printf("Sorted array:   ");
    ArrayPrint(array, size);

    return 0;
}