#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>
#include <string.h>
#include <sys/time.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#define OK 1
#define NOK 0
#define NELM 100                /* default 100 elements */
#define N 1048576               /* 2^30 or 1 meg elements  */
//#define N 2097152
//#define N 4194304
//#define N 8388608
//#define N 16777216
//#define N 33554432

// Selection sort algorithm
void selection_sort(int *list, int n);

// Swaps the contents of a and b
void swap(int *a, int *b);

// Performs mergesort on the list of n elements
void merge_sort(int *list, long n);
// Merges two lists in sorted order
void merge(int *left, long llen, int *right, long rlen, int *sorted);

void radix_sort();
void float_radix_sort();

// Checks that the array is correctly sorted
void self_check(int *listp, int n);

// Fill an array l with n random values
void init_lst(int *l, int n);

// Print the firt n elements of array l
void print_lst(int *l, int n);

// Return elapsed time as a structure
struct timeval elapsed_time(struct timeval srt, struct timeval end);



