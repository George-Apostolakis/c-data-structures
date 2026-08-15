/**
 * @file 1_ab_binary_search.c
 * @brief Implementation of the binary search algorithm, based on Abdul Bari's
 * Algorithms and Complexity course.
 */

/**
 * How binary search works:
 * (Divide and conquer strategy)
 *
 * Requirements:
 *      - Array A of size n, already sorted.
 *
 * Steps:
 *      - We keep l (low), h (high), and m (middle) indexes, starting at l=0, h=n, m=(l+h)/2.
 *      - At each step we compare A[m] with key and either find the key or keep the half
 *      of the array that makes sense, by moving either low = middle+1 or high = middle-1,
 *      then recalculating m.
 *      - We exit when h<l.
 *
 * Complexity:
 *      best case       O(1)
 *      worst case      O(log(n))
 *      average case    O(log(n))
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int A[10]={1,4,6,7,8,10,13,20,23,24};

/**
 * Recursive implementation.
 * Caller should invoke with l=0, h=n.
 */
int binary_search(int l,int h,int key){
    int m;
    if(l>h)
        return -1;
    
    m =(l+h)/2;
    if(A[m] == key)
        return m;
    else if(A[m]<key)
        l=m+1;
    else
        h=m-1;
    
    return binary_search(l,h,key);
}

int main(int argc, char** argv){
    int l, h, m ,key;

    char* ptr;
    if(argc!= 2 || ((key = strtol(argv[1], &ptr ,10))==0 && *ptr!='\0'))
    {
        fprintf(stderr,"Pass as an argument the key you are searching for");
        return -1;
    }
    printf("key = %d\n", key);

    l=0;
    h=9;
    while(l<h){
        m=(l+h)/2;
        if(A[m] == key)
        {
            printf("Found on index %d\n",m);
            break;
        }
        else if(A[m]<key)
            l=m+1;
        else
            h=m-1;   
    }

    printf("Binary search result: %d\n", binary_search(0,9,key));
    return 0;
}