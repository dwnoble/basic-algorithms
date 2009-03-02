#ifndef TEST_CASES_H
#define TEST_CASES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selection.h"

// Run all test cases
void runTests();


// Run individual test cases
void testPartition();
void testSelection();
void testMergesort();
void testRuntimes();

// Print methods
void printArray(int a[], int n);

#endif
