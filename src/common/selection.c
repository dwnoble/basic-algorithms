#include "selection.h"

static void exchange(int *a, int *b);

/*
 * Selection
 * Given an unsorted array and the index of a particular element in this array, selection will determine element
 * would be in its position if the array were sorted.  
 * NOTE: Does not maintain array order
 * 
 * params:
 * int [] a     Array
 * int n        Array Size
 * int m        Index of an element to find the position of if the array were sorted
 * returns:
 * int          Element at position m if the array were sorted
 */

int selection(int a[], int n, int m){
    // Base case: Array size is 1, thus the element already resides in its final position
    if (n == 1) return a[0];
    int k;
    
    // Partition the array, putting element 'k' in its final resting place
    k = partition(a,n);
    
    // Check to see if k is the element we are trying to sort (element 'm')
    if (k == m) return a[k];
    
    // See which side of the resultant array we should continue searching:
    if (k < m) return selection(a+k+1,n-k-1,m-k-1);
    else return selection(a,k,m);
}

/*
 * Partition
 * Given an array: 
 *      1. Put the first element, or the partition element, in its final sorted position
 *      2. Put all elements less than the partition element to its left
 *      3. Put all elements greater than the partition element to its right
 * 
 * params:
 * int [] a     Array
 * int n        Array Size
 * returns:
 * int          The index of a partition element in its final sorted postion. 
 *              All elements in array to the left of partition element are smaller than the partition
 *              All elements in array to the right of partition element are larger than the partition
 */
int partition(int a[], int n){
    // Base case - if the array only has one element, then it is already sorted - return the index of the first element
    if (n == 1) return 0;
    
    // Set the partition element to the first element, "low" to the second element, and "high" to the last element
    int *partition = a;
    int *low = a+1;
    int *high = a+n-1;
    
    // Rearrange the array so that:
    // Everything in the bottom half is less than the partition element
    // Everything in the top half is greater than the partition element
    while (low < high){
        while (*low < *partition && low < a+n-1) low++;
        while (*high > *partition && high > a+1) high--;
        if (low < high) exchange(low,high);
    }
    
    // Put the partition element in its final location, and return
    if (*high < *partition){
        exchange(partition,high);
        return high-a;
    } else {
        return partition-a;
    }
}

static void exchange(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
