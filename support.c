#include "support.h"

// Selection sort algorithm
void selection_sort(int *list, int n){

    printf("Selection sort:\n");
    int i, j, low_ind;
    // Iterate through entire array
    for (i = 0; i < n; i++) {
        low_ind = i;
        // Iterate through the tail of the array 
        for (j = i; j < n; j++) {
            // Mark the lowest non=sorted value 
            if (list[j] < list[low_ind]) {
                low_ind = j;
            }
        } 
        swap(&list[low_ind], &list[i]);     // swap in the lowest element
    }    
    return;

}

void merge_sort(int *list, long n) {
    
    // Return for the base case
    if (n <= 1) { 
        return;
    }
    // Split list in half 
    long llen = n/2;
    long rlen = n - llen; 
    long i; 
    int left[llen], right[rlen];
    // Assign values to left list 
    for (i = 0; i < llen; i++) {
        left[i] = list[i];
    } 
    merge_sort(left, llen); // merge sort left list 
    // Assign values to right list 
    for (i = llen; i < n; i++) {
        right[i-llen] = list[i];
    }
    merge_sort(right, rlen);    // merge sort right list 
    int sorted[n]; 
    // Merge the two lists
    merge(left, llen, right, rlen, sorted);
    for (i = 0; i < n; i++) {
        list[i] = sorted[i];    // replace original list with sorted
    }
    return;

}

void merge(int *left, long llen, int *right, long rlen, int *sorted) {

    long lind = 0, rind = 0;
    long i, len = rlen+llen;
    // Combine values in least-first order 
    for (i = 0; i < len; i++) {
        // Prevent out-of-bounds access 
        if (lind < llen && rind < rlen) {
            if (left[lind] < right[rind]) {
                sorted[i] = left[lind]; 
                lind++;
                continue;
            }
            sorted[i] = right[rind];
            rind++; 
            continue;
        }    
        // Assign any leftover values 
        if (lind >= llen && rind < rlen) {
            sorted[i] = right[rind];
            rind++; 
        }
        if (rind >= rlen && lind < llen) {
            sorted[i] = left[lind];
            lind++;
        }
    }
    return;

}


//fix the bucket size to 256. run 4 passes where each pass processes 8 bits
//use lst and tmp only. do not use any more memory of size n.
void radix_sort(int *list, long n) {
    printf("Radix sort:\n");

    long i;
    int digits = 0, base = 10, max = list[0];
    // Find the max value in the array 
    for (i = 0; i < n; i++) {
        if (list[i] > max) {
            max = list[i]; 
        }
    }
    printf("foo\n"); 
    // Find the number of digits (rounds) to sort 
    int num = max;
    while (num >= 1) {
        num /= 10;
        digits++;
    }
    printf("going to declare arrayss\n"); 
    
    // Declare an array of pointers, each pointing to a digit's bucket
    int **bucket;
    if ((bucket = malloc(base*sizeof(int*))) == NULL ) {
        printf("error assigning bucket"); 
    }    
    
    printf("foo\n"); 
    int j; 
    for (j = 0; j < base; j++) {
        if ((bucket[j] = malloc(n*sizeof(int))) == NULL) {
            printf("error assigning arrays");
        }
    }
    printf("test: %d\n", bucket[3][0]); 
    printf("foo\n"); 
    int msd, buck_ind;    // most significant digit(s)
    printf("base: %d\n", base); 
    int blen[base]; 
    memset(blen, 0, sizeof(int) * base); 
    for (j = 0; j < digits; j++) {
        // Could implement bit-wisee 
        int place = (int)pow(10, j);
        for (i = 0; i < n; i++) {
            // Isolate correct digit            
            int digit = (list[i]/place)%10;
            printf("digit: %d\n", digit);
            buck_ind = blen[digit];
            printf("digit: %d, buck_ind: %d\n", digit, buck_ind);
            bucket[digit][buck_ind] = list[i];
            blen[digit]++;
        
        }
        int ind = 0; 
        for (i = 0; i < base; i++) {
            int k;
            for (k = 0; k < blen[i]; k++) {
                list[ind] = bucket[i][k];
                ind++;
            }

        }
    }
    return;
}


// Swaps the contents of a and b
void swap(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;
    return; 

}

// Fill an array l with n random values
void init_lst(int *l, int n) {
    
    int i;
    int seed = time(0) % 1000;  // seed for random number 
//    printf ("seed=%d\n", seed);
    srand(seed);    // init random number gen 
    // Assign random numbers to each element 
    for (i = 0; i < n; i++) {
        l[i] = rand() % 1000;
    }

}

// Print the firt n elements of array l
void print_lst(int *l, int n){
  int i;
  for (i=0; i<n; i++) {
    printf("%d ",l[i]);
  }
  printf("\n");
}

// Checks that the array is correctly sorted
void self_check(int *listp, int n) {
    
    int i;
    for (i = 0; i < n-1; i++) {
        if (listp[i] > listp[i+1]) { 
            printf("NOT sorted at %d\n", i+1);
            return; 
        }
    }
    printf("sorted\n");
    return;
}

// Return elapsed time as a structure
struct timeval elapsed_time(struct timeval srt, struct timeval end) {
    
    struct timeval result;
    result.tv_sec = end.tv_sec-srt.tv_sec;
    long int usec = end.tv_usec-srt.tv_usec;
    if ( usec < 0 ) {
        usec = 1000000+usec;
        result.tv_sec--;
    }
    result.tv_usec = usec;
    return result;

}
