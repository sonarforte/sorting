#include "support.h"

int main(int argc, char **argv) {
    long n; 
    struct timeval tstrt, tend;
    
    // Assign number of elements from cmd line arg
    if ( argc > 1 ) {
        n = atol(argv[1]);
    } else {
        n = NELM;   // use predefined number if no args
    } 
    int lst[n];
    
    // Print info about initialized list
    printf("Number of elements: n=%ld\n", n);
    init_lst(lst, n);
    print_lst(lst, n);

    gettimeofday(&tstrt, NULL); 
    
    // Sorting algorithms....uncomment only ONE algorithm to use at a time 
    /*selection_sort(lst,n);*/
    /*merge_sort(lst, n);*/
    radix_sort(lst, n);

    gettimeofday(&tend, NULL); 

    // Print completion time in s and ms
/*    printf("start time: %ld s, %d ms\n", tstrt.tv_sec, 
        (int)(tstrt.tv_usec / 1000));
    printf("end time: %ld s, %d ms\n", tend.tv_sec, 
        (int)(tend.tv_usec / 1000));
*/    struct timeval elap = elapsed_time(tstrt, tend);  
   
    print_lst(lst, n);
    printf("Time to sort: %ld s, %d ms\n", elap.tv_sec, (int)(elap.tv_usec / 1000)); 
    return 0;


}

