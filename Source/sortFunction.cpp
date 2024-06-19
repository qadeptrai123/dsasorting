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
// Shell Sort with Counting 
void shellSortWithCounting(int *array, int number_of_elements, int &count_assign , int &count_compare) {
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

// Heap Sort with Counting
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
void mergeTwoSubArrays(int *array, int left, int middleIndex, int right)
{
    int sizeOfsubArrayOne = middleIndex - left + 1;
    int sizeOfsubArrayTwo = right - middleIndex;

    int *leftArray = new int[sizeOfsubArrayOne];
    int *rightArray = new int[sizeOfsubArrayTwo];

    for (auto i = 0; i < sizeOfsubArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < sizeOfsubArrayTwo; j++)
        rightArray[j] = array[middleIndex + j + 1];

    int indexOfSubArrayOne = 0;
    int indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < sizeOfsubArrayOne && indexOfSubArrayTwo < sizeOfsubArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < sizeOfsubArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < sizeOfsubArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
void mergeSort(int array[], int leftIndex, int rightIndex)
{
    if (leftIndex >= rightIndex)
        return;
    int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
    mergeSort(array, leftIndex, middleIndex);
    mergeSort(array, middleIndex + 1, rightIndex);
    mergeTwoSubArrays(array, leftIndex, middleIndex, rightIndex);
}

//merge sort with counting 

void mergeTwoSubArraysWithCounting(int *array, int left, int middleIndex, int right, int &count_assign , int &count_compare)
{
    int i;
    int sizeOfsubArrayOne = middleIndex - left + 1; ++count_assign;
    int sizeOfsubArrayTwo = right - middleIndex; ++count_assign;

    int *leftArray = new int[sizeOfsubArrayOne]; ++count_assign;
    int *rightArray = new int[sizeOfsubArrayTwo]; ++count_assign;

    for (++count_assign, i = 0; ++count_compare && (i < sizeOfsubArrayOne); i++, ++count_assign)
        leftArray[i] = array[left + i]; ++count_assign;
    for (++count_assign, i = 0; ++count_compare && (i < sizeOfsubArrayTwo); i++, ++count_assign)
        rightArray[i] = array[middleIndex + i + 1]; ++count_assign;

    int indexOfSubArrayOne = 0; ++count_assign;
    int indexOfSubArrayTwo = 0; ++count_assign;
    int indexOfMergedArray = left; ++count_assign;

    while ( (count_compare += 3) && (indexOfSubArrayOne < sizeOfsubArrayOne && indexOfSubArrayTwo < sizeOfsubArrayTwo)) {
        if ( (++count_compare) && (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne]; ++count_assign;
            indexOfSubArrayOne++; ++count_assign;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo]; ++count_assign;
            indexOfSubArrayTwo++; ++count_assign;
        }
        indexOfMergedArray++; ++count_assign;
    }

    while ((++count_compare) && (indexOfSubArrayOne < sizeOfsubArrayOne)) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne]; ++count_assign;
        indexOfSubArrayOne++; ++count_assign;
        indexOfMergedArray++; ++count_assign;
    }
    while ( (++count_compare) && (indexOfSubArrayTwo < sizeOfsubArrayTwo)) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo]; ++count_assign;
        indexOfSubArrayTwo++; ++count_assign;
        indexOfMergedArray++; ++count_assign;
    }
    delete[] leftArray;
    delete[] rightArray;
}
void mergeSortWithCounting(int array[], int leftIndex, int rightIndex, int &count_assign , int &count_compare)
{
    if ( ++count_compare && (leftIndex >= rightIndex))
        return;
    int middleIndex = leftIndex + (rightIndex - leftIndex) / 2; ++count_assign;
    mergeSortWithCounting(array, leftIndex, middleIndex, count_assign,count_compare);
    mergeSortWithCounting(array, middleIndex + 1, rightIndex, count_assign, count_compare);
    mergeTwoSubArraysWithCounting(array, leftIndex, middleIndex, rightIndex, count_assign, count_compare);
}