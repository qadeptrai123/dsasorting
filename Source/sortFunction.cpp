#include "sortFunction.h"
#include <algorithm>
using namespace std;
typedef unsigned long long ull;

//Shell Sort
//https://www.scholarhat.com/tutorial/datastructures/shell-sort-in-data-structures
void shellSort(int *array, int arraySize) {
    int j, store;
    int interval = arraySize / 2;
    while (interval > 0) {
        for (int i = interval; i < arraySize; i++) {
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
ull shellSortWithCounting(int *array, int arraySize) {
    ull countCompare = 0;
    int i, j, store;
    int interval = arraySize / 2; 
    while (++countCompare && interval > 0) {
        for (i = interval; ++countCompare && (i < arraySize); i++) {
            store = array[i]; 
            j = i; 
            while ((countCompare += 3) && (j >= interval && array[j - interval] > store)) {
                array[j] = array[j - interval]; 
                j -= interval; 
            }
            array[j] = store; 
        }
        interval /= 2; 
    }
    return countCompare;
}
//Heap Sort
//https://www.programiz.com/dsa/heap-sort
void swapElement(int *num1, int *num2) {
    *num1 = *num1 + *num2;
    *num2 = *num1 - *num2; //this function requires 3 assignments
    *num1 = *num1 - *num2;
}
void heapify(int *array, int arraySize, int currentIndex) {
    int indexOfLargestElement = currentIndex;
    int left = 2 * currentIndex + 1;
    int right = 2 * currentIndex + 2;
  
    if (left < arraySize && array[left] > array[indexOfLargestElement])
        indexOfLargestElement = left;
    if (right < arraySize && array[right] > array[indexOfLargestElement])
        indexOfLargestElement = right;
    if (indexOfLargestElement != currentIndex) {
        swapElement(&array[currentIndex], &array[indexOfLargestElement]);
        heapify(array, arraySize, indexOfLargestElement);
    }
}
  void heapSort(int *array, int arraySize) {
    int i;
    for (i = arraySize / 2 - 1; i >= 0; i--)
        heapify(array, arraySize, i);
  
    for (i = arraySize - 1; i >= 0; i--) {
        swapElement(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}

// Heap Sort with Counting
void heapifyWithCounting(int *array, int arraySize, int currentIndex, ull &countCompare) {
    int indexOfLargestElement = currentIndex; 
    int left = 2 * currentIndex + 1; 
    int right = 2 * currentIndex + 2; 
  
    if ((countCompare += 3) && (left < arraySize && array[left] > array[indexOfLargestElement]))
        indexOfLargestElement = left; 
    if ((countCompare += 3) && (right < arraySize && array[right] > array[indexOfLargestElement]))
        indexOfLargestElement = right; 
    if ((++countCompare) && (indexOfLargestElement != currentIndex)) {
        swapElement(&array[currentIndex], &array[indexOfLargestElement]);
        heapifyWithCounting(array, arraySize, indexOfLargestElement, countCompare); 
    }
}
ull heapSortWithCounting(int *array, int arraySize) {
    int i;
    ull countCompare = 0;
    for (i = arraySize / 2 - 1; (++countCompare) && (i >= 0); i--)
        heapifyWithCounting(array, arraySize, i, countCompare); 
  
    for (i = arraySize - 1; (++countCompare) && (i >= 0); i--) {
        swapElement(&array[0], &array[i]);
        heapifyWithCounting(array, i, 0, countCompare); 
    }
    return countCompare;
}

//Merge Sort
void mergeTwoSubArrays(int *array, int left, int middleIndex, int right) {
    int subArrayOneSize = middleIndex - left + 1;
    int subArrayTwoSize = right - middleIndex;

    int *leftArray = new int[subArrayOneSize];
    int *rightArray = new int[subArrayTwoSize];

    for (auto i = 0; i < subArrayOneSize; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwoSize; j++)
        rightArray[j] = array[middleIndex + j + 1];

    int indexOfSubArrayOne = 0;
    int indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOneSize && indexOfSubArrayTwo < subArrayTwoSize) {
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

    while (indexOfSubArrayOne < subArrayOneSize) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwoSize) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
void mergeSort(int *array, int leftIndex, int rightIndex) {
    if (leftIndex >= rightIndex)
        return;
    int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
    mergeSort(array, leftIndex, middleIndex);
    mergeSort(array, middleIndex + 1, rightIndex);
    mergeTwoSubArrays(array, leftIndex, middleIndex, rightIndex);
}

//merge sort with counting 
void mergeTwoSubArraysWithCounting(int *array, int left, int middleIndex, int right, ull &countCompare) {
    int i;
    int subArrayOneSize = middleIndex - left + 1; 
    int subArrayTwoSize = right - middleIndex; 

    int *leftArray = new int[subArrayOneSize]; 
    int *rightArray = new int[subArrayTwoSize];

    for (i = 0; ++countCompare && (i < subArrayOneSize); i++)
        leftArray[i] = array[left + i]; 
    for (i = 0; ++countCompare && (i < subArrayTwoSize); i++)
        rightArray[i] = array[middleIndex + i + 1];

    int indexOfSubArrayOne = 0; 
    int indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while ( (countCompare += 3) && (indexOfSubArrayOne < subArrayOneSize && indexOfSubArrayTwo < subArrayTwoSize)) {
        if ( (++countCompare) && (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++; 
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++; 
        }
        indexOfMergedArray++;
    }

    while ((++countCompare) && (indexOfSubArrayOne < subArrayOneSize)) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++; 
        indexOfMergedArray++; 
    }
    while ( (++countCompare) && (indexOfSubArrayTwo < subArrayTwoSize)) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo]; 
        indexOfSubArrayTwo++; 
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
ull mergeSortWithCounting(int *array, int leftIndex, int rightIndex, ull &countCompare) {
    if ( ++countCompare && (leftIndex >= rightIndex))
        return countCompare;
    int middleIndex = leftIndex + (rightIndex - leftIndex) / 2; 
    mergeSortWithCounting(array, leftIndex, middleIndex, countCompare);
    mergeSortWithCounting(array, middleIndex + 1, rightIndex, countCompare);
    mergeTwoSubArraysWithCounting(array, leftIndex, middleIndex, rightIndex, countCompare);
    return countCompare;
}

//Counting Sort
//https://www.programiz.com/dsa/counting-sort
//https://www.youtube.com/watch?v=7zuGmKfUt7s

void countingSort(int* array, int arraySize){
    //Find the largest number of the array
    int maxValue = array[0];
    for (int i = 1; i < arraySize; i++){
        maxValue = (array[i] > maxValue) ? array[i] : maxValue;
    }

    //Initialize count array and store the count of each element
    int* count = new int[maxValue + 1](); //initialize with 0
    for (int i = 0; i < arraySize; i++){
        count[array[i]]++;
    }

    // Calculate cumulative count
    for (int i = 1; i <= maxValue; i++){
        count[i] += count[i - 1];
    }

    // Place the elements in sorted order
    int* outputArray = new int[arraySize];
    for (int i = arraySize - 1; i >= 0; i--){
        outputArray[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    //Copy output array to array
    for (int i = 0; i < arraySize; i++){
        array[i] = outputArray[i];
    }
    delete[]count;
    delete[]outputArray;
}

long long countingSortWithCounting(int* array, int arraySize){
    long long countCompare = 0;

    int maxValue = array[0];
    for (int i = 0; ++countCompare && i < arraySize; i++){
        maxValue = (array[i] > maxValue) ? array[i] : maxValue;
        ++countCompare;
    }

    int* count = new int[maxValue + 1]();
    for (int i = 0; ++countCompare && i < arraySize; i++){
        count[array[i]]++;
    }

    for (int i = 1; ++countCompare && i <= maxValue; i++){
        count[i] += count[i - 1];
    }

    int* outputArray = new int[arraySize];
    for (int i = arraySize - 1; ++countCompare && i >= 0; i--){
        outputArray[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; ++countCompare && i < arraySize; i++){
        array[i] = outputArray[i];
    }
    delete[] count;
    delete[] outputArray;
    return countCompare;
}

//Radix Sort
//https://www.programiz.com/dsa/radix-sort
//https://www.youtube.com/watch?v=nu4gDuFabIM

void countingSortForRadix(int* array, int arraySize, int place){
    int* output = new int[arraySize];
    int count[10] = {0}; //Initialzie count array of digit (0 to 9) with all zero

    // Calculate and store the count of each element
    for (int i = 0; i < arraySize; i++){
        count[(array[i] / place) % 10]++;
    }

    // Calculate cumulative count
    for (int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }
    // Place the elements in sorted order
    for (int i = arraySize - 1; i >= 0; i--){
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    //Copy output array to array
    for (int i = 0; i < arraySize; i++){
        array[i] = output[i];
    }

    delete[] output;
}

void radixSort(int* array, int arraySize){
    //Find the largest number of the array
    int maxValue = array[0];
    for (int i = 1; i < arraySize; i++){
        maxValue = (array[i] > maxValue) ? array[i] : maxValue;
    }

    // Use counting sort to sort elements based on place value.
    for (int place = 1; maxValue / place > 0; place *= 10){
        countingSortForRadix(array, arraySize, place);
    }
}

void countingSortForRadixWithCounting(int* array, int arraySize, int place, long long& countCompare){
    int* output = new int[arraySize];
    int count[10] = {0};

    for (int i = 0; ++countCompare && i < arraySize; i++){
        count[(array[i] / place) % 10]++;
    }

    for (int i = 1; ++countCompare && i < 10; i++){
        count[i] += count[i - 1];
    }

    for (int i = arraySize - 1; ++countCompare && i >= 0; i--){
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; ++countCompare && i < arraySize; i++){
        array[i] = output[i];
    }

    delete[] output;
}

long long radixSortWithCounting(int* array, int arraySize){
    long long countCompare = 0;
    int largestElement = array[0];
    for (int i = 1; ++countCompare && i < arraySize; i++){
        largestElement = (array[i] > largestElement) ? array[i] : largestElement;
    }

    for (int place = 1; ++countCompare && largestElement / place > 0; place *= 10){
        countingSortForRadixWithCounting(array, arraySize, place, countCompare);
    }
    return countCompare;
}

//Flash Sort
//https://www.w3resource.com/javascript-exercises/searching-and-sorting-algorithm/searching-and-sorting-algorithm-exercise-12.php#google_vignette

void flashSort(int* array, int arraySize){
    
    int numberClasses = 0.45 * arraySize;
    int* classCounts = new int[numberClasses]();
    
    //Find largest and smallest element
    int minValue = array[0];
    int maxIndex = 0;
    for (int i = 1; i < arraySize; i++){
        minValue = (minValue > array[i]) ? array[i] : minValue;
        maxIndex = (array[maxIndex] < array[i]) ? i : maxIndex;
    }
    int maxValue = array[maxIndex];

    if (maxValue == minValue){
        // cout << "oday\n";
        return;
    }

    //Count number elements of each class 
    for (int i = 0; i < arraySize; i++){
        int index = (numberClasses - 1) * (array[i] - minValue) / (maxValue - minValue);
        classCounts[index]++;
    }

    //Find starting position of each class
    for (int i = 1; i < numberClasses; i++){
        classCounts[i] += classCounts[i - 1];
    }

    //Permute elements to their class
    int hold = array[maxIndex];
    array[maxIndex] = array[0];
    array[0] = hold;

    int move = 0;
    int flash = 0;
    int i = 0;
    int j = 0;
    int k = numberClasses - 1;
// cout << "hj";
    while (move < (arraySize - 1)){
        // cout << "hj";
        while (j > (classCounts[i] - 1)){
            j++;
            k = (numberClasses - 1) * (array[i] - minValue) / (maxValue - minValue);
        }
        if (k < 0) break;
        flash = array[j];
        while (j != classCounts[k]){
            k = (numberClasses - 1) * (array[i] - minValue) / (maxValue - minValue);
            i = --classCounts[k];
            hold = array[i];
            array[i] = flash;
            flash = hold;
            ++move;
        }
    }

    //Sort by insertion sort
    for (j = 1; j < arraySize; j++){
        hold = array[j];
        int index = j - 1;
        while (index >= 0 && array[index] > hold){
            array[index + 1] = array[index--];
        }
        array[index + 1] = hold;
    }
    delete[] classCounts;
}

long long flashSortWithCounting(int* array, int arraySize){
    long long countCompare = 0;
    int numberClasses = 0.45 * arraySize;
    int* classCounts = new int[numberClasses]();

    int minValue = array[0];
    int maxIndex = 0;
    for (int i = 1; ++countCompare && i < arraySize; i++){
        minValue = (++countCompare && minValue > array[i]) ? array[i] : minValue;
        maxIndex = (++countCompare && array[maxIndex] < array[i]) ? i : maxIndex;
    }
    int maxValue = array[maxIndex];

    if (++countCompare && maxValue == minValue){
        return countCompare;
    }

    for (int i = 0; ++countCompare && i < arraySize; i++){
        int index = (numberClasses - 1) * (array[i] - minValue) / (maxValue - minValue);
        classCounts[index]++;
    }

    for (int i = 1; ++countCompare && i < numberClasses; i++){
        classCounts[i] += classCounts[i - 1];
    }

    int hold = array[maxIndex];
    array[maxIndex] = array[0];
    array[0] = hold;

    int move = 0;
    int flash = 0;
    int i = 0;
    int j = 0;
    int k = numberClasses - 1;

    while (++countCompare && move < (arraySize - 1)){
        while (++countCompare && j > (classCounts[i] - 1)){
            j++;
            k = (numberClasses - 1) * (array[i] - minValue) / (maxValue - minValue);
        }
        if (++countCompare && k < 0) break;
        flash = array[j];
        while (++countCompare && j != classCounts[k]){
            k = (numberClasses - 1) * (array[i] - minValue) / (maxValue - minValue);
            i = --classCounts[k];
            hold = array[i];
            array[i] = flash;
            flash = hold;
            ++move;
        }
    }

    for (j = 1; ++countCompare && j < arraySize; j++){
        hold = array[j];
        int index = j - 1;
        while (++countCompare && index >= 0 && ++countCompare && array[index] > hold){
            array[index + 1] = array[index--];
        }
        array[index + 1] = hold;
    }

    delete[] classCounts;
    return countCompare;
}

//QA (ShakerSort, InsertionSort)
void shakerSort(int *array, int arraySize) {
    int left = 0;
    int right = arraySize-1;
    int k = 0;
    while(left < right) {
        for(int i = left; i < right; ++i) {
            if(array[i] > array[i+1]) {
                swap(array[i], array[i+1]);
                k = i;
            }
        }
        right = k;
        for(int i = right; i > left; --i) {
            if(array[i] < array[i-1]) {
                swap(array[i], array[i-1]);
                k = i;
            }
        }
        left = k;
    }
}
//https://www.iostream.co/article/bubble-sort-va-shaker-sort-01Si3U

long long shakerSortWithCounting(int *array, int arraySize) {
    int left = 0;
    int right = arraySize-1;
    int k = 0;
    long long countCompare = 0;
    while(++countCompare && left < right) {
        for(int i = left; ++countCompare && i < right; ++i) {
            if(++countCompare && array[i] > array[i+1]) {
                swap(array[i], array[i+1]);
                k = i;
            }
        }
        right = k;
        for(int i = right; ++countCompare && i > left; --i) {
            if(++countCompare && array[i] < array[i-1]) {
                swap(array[i], array[i-1]);
                k = i;
            }
        }
        left = k;
    }
    return countCompare;
}

void insertionSort(int *array, int arraySize) {
    for(int i = 1; i < arraySize; ++i) {
        int key = array[i];
        int j = i;
        while(j > 0 && array[j-1] > key) {
            array[j] = array[j-1];
            --j;
        }
        array[j] = key;
    }
}

long long insertionSortWithCounting(int *array, int arraySize) {
    long long countCompare = 0;
    for(int i = 1; ++countCompare && i < arraySize; ++i) {
        int key = array[i];
        int j = i - 1;
        while(++countCompare && j >= 0 && ++countCompare && array[j] > key) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
    return countCompare;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *array, int low, int high) {
    // select the rightmost element as pivot
    int pivot = array[high];
    
    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;
            // swap element at i with element at j
            swap(&array[i], &array[j]);
        }
    }
    
    // swap pivot with the greater element at i
    swap(&array[i + 1], &array[high]);
    
    // return the partition point
    return (i + 1);
}

void quickSort(int *array, int low, int high) {
    if (low < high) {
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(array, low, high);
        
        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);
        
        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}

int partition(int *array, int low, int high, long long &comparisons) {
    // select the rightmost element as pivot
    int pivot = array[high];
    
    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++) {
        comparisons++; // Increase comparison count
        if (array[j] <= pivot) {
            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;
            // swap element at i with element at j
            swap(&array[i], &array[j]);
        }
    }
    
    // swap pivot with the greater element at i
    swap(&array[i + 1], &array[high]);
    
    // return the partition point
    return (i + 1);
}

long long quickSortCounting(int *array, int low, int high) {
    long long comparisons = 0;
    if (low < high) {
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(array, low, high, comparisons);
        
        // recursive call on the left of pivot
        comparisons += quickSortCounting(array, low, pi - 1);
        
        // recursive call on the right of pivot
        comparisons += quickSortCounting(array, pi + 1, high);
    }
    return comparisons;
}

void bubbleSort(int* array, int size) {
    for (int step = 0; step < size; ++step) {
        for (int i = 0; i < size - step - 1; ++i) {
            if (array[i] > array[i + 1]) {
                swap(&array[i], &array[i + 1]);
            }
        }
    }
}

long long bubbleSortCounting(int* array, int size) {
    long long comparisons = 0;

    for (int step = 0; step < size; ++step) {
        for (int i = 0; i < size - step - 1; ++i) {
            comparisons++; // Increase comparison count
            if (array[i] > array[i + 1]) {
                swap(&array[i], &array[i + 1]);
            }
        }
    }

    return comparisons;
}

void selectionSort(int* array, int size) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
            if (array[i] < array[min_idx])
                min_idx = i;
        }
        swap(&array[min_idx], &array[step]);
    }
}

long long selectionSortCounting(int* arr, int size) {
    long long comparisons = 0;
    
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
            comparisons++; // Increase comparison count
            if (arr[i] < arr[min_idx])
                min_idx = i;
        }
        swap(&arr[min_idx], &arr[step]); // Use the swap function
    }
    
    return comparisons;
}