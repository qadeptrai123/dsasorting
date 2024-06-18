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
//https://www.programiz.com/dsa/heap-sort
void swapElement(int *num1, int *num2) {
    *num1 = *num1 + *num2;
    *num2 = *num1 - *num2; //this function requires 3 assignments
    *num1 = *num1 - *num2;
}
void heapify(int array[], int number_of_elements, int current_index) {
    int index_of_largest_element = current_index;
    int left = 2 * current_index + 1;
    int right = 2 * current_index + 2;
  
    if (left < number_of_elements && array[left] > array[index_of_largest_element])
        index_of_largest_element = left;
    if (right < number_of_elements && array[right] > array[index_of_largest_element])
        index_of_largest_element = right;
    if (index_of_largest_element != current_index) {
        swapElement(&array[current_index], &array[index_of_largest_element]);
        heapify(array, number_of_elements, index_of_largest_element);
    }
}
  void heapSort(int array[], int number_of_elements) {
    int i;
    for (i = number_of_elements / 2 - 1; i >= 0; i--)
        heapify(array, number_of_elements, i);
  
    for (i = number_of_elements - 1; i >= 0; i--) {
        swapElement(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}

// Heap Sort with counting
void heapifyWithCounting(int array[], int number_of_elements, int current_index, int &count_assign , int &count_compare) {
    int index_of_largest_element = current_index; ++count_assign;
    int left = 2 * current_index + 1; ++count_assign;
    int right = 2 * current_index + 2; ++count_assign;
  
    if ((count_compare += 3) && (left < number_of_elements && array[left] > array[index_of_largest_element]))
        index_of_largest_element = left; ++count_assign;
    if ((count_compare += 3) && (right < number_of_elements && array[right] > array[index_of_largest_element]))
        index_of_largest_element = right; ++count_assign;
    if ((++count_compare) && (index_of_largest_element != current_index)) {
        swapElement(&array[current_index], &array[index_of_largest_element]); count_assign += 3;
        heapifyWithCounting(array, number_of_elements, index_of_largest_element, count_assign, count_compare); ++count_assign;
    }
}
  void heapSortWithCounting(int array[], int number_of_elements, int &count_assign , int &count_compare) {
    int i;
    count_assign = 0;
    count_compare = 0;
    for (++count_assign, i = number_of_elements / 2 - 1; (++count_compare) && (i >= 0); i--, ++count_assign)
        heapifyWithCounting(array, number_of_elements, i, count_assign, count_compare); ++count_assign;
  
    for (++count_assign, i = number_of_elements - 1; (++count_compare) && (i >= 0); ++count_assign, i--) {
        swapElement(&array[0], &array[i]); count_assign += 3;
        heapifyWithCounting(array, i, 0, count_assign, count_compare); ++count_assign;
    }
}

//Merge Sort