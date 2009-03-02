#include <test_cases.h>


#define SIZE    6
#define SIZE_N  1000000


void runTests() {
//    testPartition();
//    testSelection();
//    testMergesort();

    testRuntimes();
}


void testRuntimes() {
    int i;
    int a[SIZE_N];
    int copy[SIZE_N];
    int size;
    srand(time(0));
    
    
    for (size = 10; size <= SIZE_N ; size=size*10){
        clock_t start, end;
        double elapsed;
        int val;
        
        for (i = 0; i < size ; i ++){
            a[i] = rand();
            copy[i] = a[i];
        }
        
        printf("Calculating runtimes for selecting element N/2=%d from a random array of size N=%d\n",size/2,size);
        
        // Determine element N/2 using mergesort:
        start = clock();
        d_mergesort(copy,size);
        end = clock();
        elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("  Mergesort (N=%d): Determined N/2 element is equal to %d after %f CPU time\n",size,copy[size/2],elapsed);
        
        
        // Reset copy
        for (i = 0; i < size ; i ++)
            copy[i] = a[i];
        
        // Determine element N/2 using selection:
        start = clock();
        val = selection(copy,size,size/2);
        end = clock();
        elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("  Selection (N=%d): Determined N/2 element is equal to %d after %f CPU time\n",size,val,elapsed);
        
        
    }
}


void testMergesort(){
    int a[SIZE][5] = {
        {1,2,3,4,5},
        {5,4,3,2,1},
        {5,1,2,3,4},
        {4,1,2,3,5},
        {3,1,2,4,5},
        {2,1,3,4,5}
    };
    int i;
    for (i=0;i<SIZE;i++){
        printf("original array[%d]: ",i);
        printArray(a[i],5);
    }
    
    for (i=0;i<SIZE;i++){
        d_mergesort(a[i],5);
        printf("sorted array[%d]: ",i);
        printArray(a[i],5);
    }
}

void testSelection(){
    int a[SIZE][5] = {
        {1,2,3,4,5},
        {5,4,3,2,1},
        {5,1,2,3,4},
        {4,1,2,3,5},
        {3,1,2,4,5},
        {2,1,3,4,5}
    };
    int i;
    
    for (i=0;i<SIZE;i++){
        int index = 2;
        int sortedVal;
        printf("original array: ");
        printArray(a[i],5);
        sortedVal = selection(a[i],5,index);
        printf("array after selection: ");
        printArray(a[i],5);
        printf("Sorted value of a[%d] = %d\n",index,sortedVal);
        printf("***********\n");
    }
    
}

void testPartition(){
    int a[SIZE][5] = {
        {1,2,3,4,5},
        {5,4,3,2,1},
        {5,1,2,3,4},
        {4,1,2,3,5},
        {3,1,2,4,5},
        {2,1,3,4,5}
    };
    int i;
    
    for (i=0;i<SIZE;i++){
        int k;
        printf("original array: ");
        printArray(a[i],5);
        k = partition(a[i],5);
        printf("array after partition: ");
        printArray(a[i],5);
        printf("Partition element's new index: k = %d\n",k);
        printf("***********\n");
    }
}



void printArray(int a[], int n){
    int i = 0;
    printf("{");
    for (i=0; i < n ; i ++ ) {
        printf("%d",a[i]);
        if (i < n-1) printf(", ");
    }
    printf("}\n");
}

