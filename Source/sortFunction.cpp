#include "sortFunction.h"




//Shell Sort
//https://www.scholarhat.com/tutorial/datastructures/shell-sort-in-data-structures
void shellSort(int *array, int number_of_elements) {
    int j, store;
    int interval = number_of_elements / 2;
    while (interval > 0) {
        for (int i = interval; i < number_of_elements; i++) {
            store = array[i];
            j = i;
            while (j >= interval && array[j - interval] > store) {
                array[j] = array[j - interval];
                j -= interval;
            }
            array[j] = store;
        }
        interval /= 2;
    }
}
// Shell Sort with counting 
void  shellSortWithCounting(int *array, int number_of_elements, int &count_assign , int &count_compare) {
    count_assign = 0;
    count_compare = 0;
    int i, j, store;
    int interval = number_of_elements / 2; ++count_assign;
    while (++count_compare && interval > 0) {
        for (i = interval, ++count_assign; ++count_compare && (i < number_of_elements); i++, ++count_assign) {
            store = array[i]; ++count_assign;
            j = i; ++count_assign;
            while ((count_compare += 3) && (j >= interval && array[j - interval] > store)) {
                array[j] = array[j - interval]; ++count_assign;
                j -= interval; ++count_assign;
            }
            array[j] = store; ++count_assign;
        }
        interval /= 2; ++count_assign;
    }
}
//Heap Sort


//Merge Sort