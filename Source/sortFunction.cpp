#include "sortFunction.h"


//Shell Sort
//https://www.scholarhat.com/tutorial/datastructures/shell-sort-in-data-structures
void shellSort(int *array, int numberOfElements) {
    int j, store;
    int interval = numberOfElements / 2;
    while (interval > 0) {
        for (int i = interval; i < numberOfElements; i++) {
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
void shellSortWithCounting(int *array, int numberOfElements, int &countAssign , int &countCompare) {
    countAssign = 0;
    countCompare = 0;
    int i, j, store;
    int interval = numberOfElements / 2; ++countAssign;
    while (++countCompare && interval > 0) {
        for (i = interval, ++countAssign; ++countCompare && (i < numberOfElements); i++, ++countAssign) {
            store = array[i]; ++countAssign;
            j = i; ++countAssign;
            while ((countCompare += 3) && (j >= interval && array[j - interval] > store)) {
                array[j] = array[j - interval]; ++countAssign;
                j -= interval; ++countAssign;
            }
            array[j] = store; ++countAssign;
        }
        interval /= 2; ++countAssign;
    }
}
//Heap Sort
//https://www.programiz.com/dsa/heap-sort
void swapElement(int *num1, int *num2) {
    *num1 = *num1 + *num2;
    *num2 = *num1 - *num2; //this function requires 3 assignments
    *num1 = *num1 - *num2;
}
void heapify(int *array, int numberOfElements, int currentIndex) {
    int indexOfLargestElement = currentIndex;
    int left = 2 * currentIndex + 1;
    int right = 2 * currentIndex + 2;
  
    if (left < numberOfElements && array[left] > array[indexOfLargestElement])
        indexOfLargestElement = left;
    if (right < numberOfElements && array[right] > array[indexOfLargestElement])
        indexOfLargestElement = right;
    if (indexOfLargestElement != currentIndex) {
        swapElement(&array[currentIndex], &array[indexOfLargestElement]);
        heapify(array, numberOfElements, indexOfLargestElement);
    }
}
  void heapSort(int *array, int numberOfElements) {
    int i;
    for (i = numberOfElements / 2 - 1; i >= 0; i--)
        heapify(array, numberOfElements, i);
  
    for (i = numberOfElements - 1; i >= 0; i--) {
        swapElement(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}

// Heap Sort with Counting
void heapifyWithCounting(int *array, int numberOfElements, int currentIndex, int &countAssign , int &countCompare) {
    int indexOfLargestElement = currentIndex; ++countAssign;
    int left = 2 * currentIndex + 1; ++countAssign;
    int right = 2 * currentIndex + 2; ++countAssign;
  
    if ((countCompare += 3) && (left < numberOfElements && array[left] > array[indexOfLargestElement]))
        indexOfLargestElement = left; ++countAssign;
    if ((countCompare += 3) && (right < numberOfElements && array[right] > array[indexOfLargestElement]))
        indexOfLargestElement = right; ++countAssign;
    if ((++countCompare) && (indexOfLargestElement != currentIndex)) {
        swapElement(&array[currentIndex], &array[indexOfLargestElement]); countAssign += 3;
        heapifyWithCounting(array, numberOfElements, indexOfLargestElement, countAssign, countCompare); ++countAssign;
    }
}
  void heapSortWithCounting(int *array, int numberOfElements, int &countAssign , int &countCompare) {
    int i;
    countAssign = 0;
    countCompare = 0;
    for (++countAssign, i = numberOfElements / 2 - 1; (++countCompare) && (i >= 0); i--, ++countAssign)
        heapifyWithCounting(array, numberOfElements, i, countAssign, countCompare); ++countAssign;
  
    for (++countAssign, i = numberOfElements - 1; (++countCompare) && (i >= 0); ++countAssign, i--) {
        swapElement(&array[0], &array[i]); countAssign += 3;
        heapifyWithCounting(array, i, 0, countAssign, countCompare); ++countAssign;
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
void mergeSort(int *array, int leftIndex, int rightIndex)
{
    if (leftIndex >= rightIndex)
        return;
    int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
    mergeSort(array, leftIndex, middleIndex);
    mergeSort(array, middleIndex + 1, rightIndex);
    mergeTwoSubArrays(array, leftIndex, middleIndex, rightIndex);
}

//merge sort with counting 
void mergeTwoSubArraysWithCounting(int *array, int left, int middleIndex, int right, int &countAssign , int &countCompare)
{
    int i;
    int sizeOfsubArrayOne = middleIndex - left + 1; ++countAssign;
    int sizeOfsubArrayTwo = right - middleIndex; ++countAssign;

    int *leftArray = new int[sizeOfsubArrayOne]; ++countAssign;
    int *rightArray = new int[sizeOfsubArrayTwo]; ++countAssign;

    for (++countAssign, i = 0; ++countCompare && (i < sizeOfsubArrayOne); i++, ++countAssign)
        leftArray[i] = array[left + i]; ++countAssign;
    for (++countAssign, i = 0; ++countCompare && (i < sizeOfsubArrayTwo); i++, ++countAssign)
        rightArray[i] = array[middleIndex + i + 1]; ++countAssign;

    int indexOfSubArrayOne = 0; ++countAssign;
    int indexOfSubArrayTwo = 0; ++countAssign;
    int indexOfMergedArray = left; ++countAssign;

    while ( (countCompare += 3) && (indexOfSubArrayOne < sizeOfsubArrayOne && indexOfSubArrayTwo < sizeOfsubArrayTwo)) {
        if ( (++countCompare) && (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne]; ++countAssign;
            indexOfSubArrayOne++; ++countAssign;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo]; ++countAssign;
            indexOfSubArrayTwo++; ++countAssign;
        }
        indexOfMergedArray++; ++countAssign;
    }

    while ((++countCompare) && (indexOfSubArrayOne < sizeOfsubArrayOne)) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne]; ++countAssign;
        indexOfSubArrayOne++; ++countAssign;
        indexOfMergedArray++; ++countAssign;
    }
    while ( (++countCompare) && (indexOfSubArrayTwo < sizeOfsubArrayTwo)) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo]; ++countAssign;
        indexOfSubArrayTwo++; ++countAssign;
        indexOfMergedArray++; ++countAssign;
    }
    delete[] leftArray;
    delete[] rightArray;
}
void mergeSortWithCounting(int *array, int leftIndex, int rightIndex, int &countAssign , int &countCompare)
{
    if ( ++countCompare && (leftIndex >= rightIndex))
        return;
    int middleIndex = leftIndex + (rightIndex - leftIndex) / 2; ++countAssign;
    mergeSortWithCounting(array, leftIndex, middleIndex, countAssign,countCompare);
    mergeSortWithCounting(array, middleIndex + 1, rightIndex, countAssign, countCompare);
    mergeTwoSubArraysWithCounting(array, leftIndex, middleIndex, rightIndex, countAssign, countCompare);
}