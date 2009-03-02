#include "mergesort.h"

void merge(int a[], int a1[], int n1, int a2[], int n2);

/*
static void printArray(int a[], int n){
    int i = 0;
    printf("{");
    for (i=0; i < n ; i ++ ) {
        printf("%d",a[i]);
        if (i < n-1) printf(", ");
    }
    printf("}\n");
}
*/

/*
 * Mergesort
 * Mergesort takes an array of size n and sorts it in ascending order
 * 
 * params:
 * int a[]      Array to be sorted
 * int n        Array size
 */

void d_mergesort(int a[], int n) {
    int *a1,*a2;
    int n1,n2;
    if (n <= 1) return;
    // Divide the array in half, and mergesort both halves
    a1 = a;
    n1 = n/2;
//    printf("Sorting: ");
//    printArray(a,n);
    
    d_mergesort(a1,n1);
    
    a2 = a + n/2;
    n2 = n/2 + n%2;
    d_mergesort(a2,n2);
    
//    printf("Merging a1: ");
//    printArray(a1,n1);
    
//    printf("Merging a2: ");
//    printArray(a2,n1);
    
    merge(a,a1,n1,a2,n2);
}

void merge(int a[], int a1[], int n1, int a2[], int n2) {
    int i,j,k;
    int n = n1+n2;
    int *tmp;
    
    tmp = (int*)malloc(n*sizeof(int));
    
    j=0;
    k=0;
    for (i = 0 ; i < n ; i ++ ){
        if ( ((j<n1 && k<n2) && (a1[j] < a2[k])) || (j<n1 && k==n2) ){
            tmp[i] = a1[j];
            j++;
        } else {
            tmp[i] = a2[k];
            k++;
        }
    }
    
    
    for(i = 0 ; i < n; i++)
        a[i] = tmp[i];
    free(tmp);
}
