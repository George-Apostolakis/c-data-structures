#include <stdio.h>
#include <stdbool.h>

/**
 * Time Complexity of O(n^2)
 * 
 * Pros:
 *      Better even than mergesort( O())
 */
void bubblesort(int array[], int size)
{
    int tmp;
    bool changed;
    for (int i = 0; i < size - 1; i++)
    {
        changed = false;
        for (int j = 0; j < size - i - 1; j++)
            if (array[j] > array[j + 1])
            {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                changed = true;
            }
        if (!changed)
            break;
    }
}

int main()
{
    int array[10] = {16, 32, 12, 54, 24, 87, 45, 25, 70, 17};

    printf("Starting Array: [ ");
    for (int i = 0; i < 10; i++)
        printf("%d ", array[i]);
    printf(" ]\n");

    bubblesort(array, 10);

    printf("Sorted Array: [ ");
    for (int i = 0; i < 10; i++)
        printf("%d ", array[i]);
    printf(" ]\n");
    return 0;
}