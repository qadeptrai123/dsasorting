#include "sortFunction.h"
#include <algorithm>
#include<fstream>
using namespace std;




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
long long shellSortWithCounting(int *array, int arraySize) {
    long long countCompare = 0;
    int i, j, store;
    int interval = arraySize / 2; 
    while (++countCompare && interval > 0) {
        for (i = interval; ++countCompare && (i < arraySize); i++) {
            store = array[i]; 
            j = i; 
            while ((countCompare += 2) && (j >= interval && array[j - interval] > store)) {
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
// void swapElement(int *num1, int *num2) {
//     *num1 = *num1 + *num2;
//     *num2 = *num1 - *num2; //this function requires 3 assignments
//     *num1 = *num1 - *num2;
// }
void heapify(int *array, int arraySize, int currentIndex) {
    int indexOfLargestElement = currentIndex;
    int left = 2 * currentIndex + 1;
    int right = 2 * currentIndex + 2;
  
    if (left < arraySize && array[left] > array[indexOfLargestElement])
        indexOfLargestElement = left;
    if (right < arraySize && array[right] > array[indexOfLargestElement])
        indexOfLargestElement = right;
    if (indexOfLargestElement != currentIndex) {
        swap(array[currentIndex], array[indexOfLargestElement]);
        heapify(array, arraySize, indexOfLargestElement);
    }
}
  void heapSort(int *array, int arraySize) {
    int i;
    for (i = arraySize / 2 - 1; i >= 0; i--)
        heapify(array, arraySize, i);
  
    for (i = arraySize - 1; i >= 0; i--) {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

// Heap Sort with Counting
void heapifyWithCounting(int *array, int arraySize, int currentIndex, long long &countCompare) {
    int indexOfLargestElement = currentIndex; 
    int left = 2 * currentIndex + 1; 
    int right = 2 * currentIndex + 2; 
  
    if ((++countCompare) && (left < arraySize ) && (++ countCompare && array[left] > array[indexOfLargestElement]))
        indexOfLargestElement = left; 
    if ((++countCompare ) && (right < arraySize) && (++countCompare && array[right] > array[indexOfLargestElement]))
        indexOfLargestElement = right; 
    if ((++countCompare) && (indexOfLargestElement != currentIndex)) {
        swap(array[currentIndex], array[indexOfLargestElement]);
        heapifyWithCounting(array, arraySize, indexOfLargestElement, countCompare); 
    }
}
long long heapSortWithCounting(int *array, int arraySize) {
    int i;
    long long countCompare = 0;
    for (i = arraySize / 2 - 1; (++countCompare) && (i >= 0); i--)
        heapifyWithCounting(array, arraySize, i, countCompare); 
  
    for (i = arraySize - 1; (++countCompare) && (i >= 0); i--) {
        swap(array[0], array[i]);
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

void mergeSort(int *array, int arraySize) {
    doMergeSort(array, 0, arraySize - 1);
}

void doMergeSort(int *array, int leftIndex, int rightIndex) {
    if (leftIndex >= rightIndex)
        return;
    int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
    doMergeSort(array, leftIndex, middleIndex);
    doMergeSort(array, middleIndex + 1, rightIndex);
    mergeTwoSubArrays(array, leftIndex, middleIndex, rightIndex);
}

//merge sort with counting 
long long mergeTwoSubArraysWithCounting(int *array, int left, int middleIndex, int right) {
    int i;
    long long countCompare = 0;
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

    while ( (++countCompare && indexOfSubArrayOne < subArrayOneSize && ++countCompare && indexOfSubArrayTwo < subArrayTwoSize)) {
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
    return countCompare;
}

long long doMergeSortWithCounting(int *array, int leftIndex, int rightIndex) {
    long long countCompare = 0;
    if ( ++countCompare && (leftIndex >= rightIndex))
        return countCompare;
    int middleIndex = leftIndex + (rightIndex - leftIndex) / 2; 
    countCompare += doMergeSortWithCounting(array, leftIndex, middleIndex);
    countCompare += doMergeSortWithCounting(array, middleIndex + 1, rightIndex);
    countCompare += mergeTwoSubArraysWithCounting(array, leftIndex, middleIndex, rightIndex);
    return countCompare;
}

long long mergeSortWithCounting(int *array, int arraySize) {
    return doMergeSortWithCounting(array, 0, arraySize - 1);
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
        maxValue = (++countCompare && array[i] > maxValue) ? array[i] : maxValue;
        
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
        largestElement = (++countCompare && array[i] > largestElement) ? array[i] : largestElement;
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
        return;
    }

    //Count number elements of each class 
    double c = (double)(numberClasses - 1) / (maxValue - minValue);
    for (int i = 0; i < arraySize; i++){
        int index = (int)(c * (array[i] - minValue));
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
    int flash, i;
    int j = 0;
    int k = numberClasses - 1;
    
    while (move < (arraySize - 1)){
        while (j > (classCounts[k] - 1)){
            j++;
            k = c * (array[j] - minValue);
        }
        if (k < 0) break;
        flash = array[j];
        while (j != classCounts[k]){
            k = c * (flash - minValue);
            i = --classCounts[k];
            hold = array[i];
            array[i] = flash;
            flash = hold;
            ++move;
        }
    }
    // ofstream fout;
    // fout.open("check.txt");
    // for(int i = 0; i < arraySize; ++i) fout << array[i] << " ";
    // fout.close();
    //Sort by insertion sort
    insertionSort(array, arraySize);
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

    double c = (double)(numberClasses - 1) / (maxValue - minValue);
    for (int i = 0; ++countCompare && i < arraySize; i++){
        int index = c * (array[i] - minValue);
        classCounts[index]++;
    }

    for (int i = 1; ++countCompare && i < numberClasses; i++){
        classCounts[i] += classCounts[i - 1];
    }

    int hold = array[maxIndex];
    array[maxIndex] = array[0];
    array[0] = hold;

    int move = 0;
    int flash, i;
    int j = 0;
    int k = numberClasses - 1;

    while (++countCompare && move < (arraySize - 1)){
        while (++countCompare && j > (classCounts[k] - 1)){
            j++;
            k = c * (array[j] - minValue);
        }
        if (++countCompare && k < 0) break;
        flash = array[j];
        while (++countCompare && j != classCounts[k]){
            k = c * (flash - minValue);
            i = --classCounts[k];
            hold = array[i];
            array[i] = flash;
            flash = hold;
            ++move;
        }
    }

    countCompare += insertionSortWithCounting(array, arraySize);

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
        int j = i;
        while(++countCompare && j > 0 && ++countCompare && array[j-1] > key) {

            array[j] = array[j-1];
            --j;
        }
        array[j] = key;
    }
    return countCompare;
}

// void swap(int *a, int *b) {
//     int t = *a;
//     *a = *b;
//     *b = t;
// }

int partition(int *array, int low, int high) {
    // Choosing pivot using median-of-three strategy
    int mid = low + (high - low) / 2;
    int pivotIndex = (array[low] < array[mid]) ?
                     ((array[mid] < array[high]) ? mid : ((array[low] < array[high]) ? high : low)) :
                     ((array[low] < array[high]) ? low : ((array[mid] < array[high]) ? high : mid));
    int pivot = array[pivotIndex];
    
    swap(array[pivotIndex], array[high]); // Move pivot to end
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    
    swap(array[i + 1], array[high]);
    return (i + 1);
}

void quickSort(int *array, int arraySize) {
    doQuickSort(array, 0, arraySize - 1);
}

void doQuickSort(int *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        
        doQuickSort(array, low, pi - 1);
        doQuickSort(array, pi + 1, high);
    }
}
int partitionCounting(int *array, int low, int high, long long &comparisons) {
    // Choosing pivot using median-of-three strategy
    int mid = low + (high - low) / 2;
    int pivotIndex = (++comparisons && array[low] < array[mid]) ?
                     ((++comparisons && array[mid] < array[high]) ? mid : ((++comparisons && array[low] < array[high]) ? high : low)) :
                     ((++comparisons && array[low] < array[high]) ? low : ((++comparisons && array[mid] < array[high]) ? high : mid));
    int pivot = array[pivotIndex];
    
    swap(array[pivotIndex], array[high]); // Move pivot to end
    int i = low - 1;
    
    for (int j = low; ++comparisons &&  j < high; j++) {
        if ( ++comparisons && array[j] <= pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    
    swap(array[i + 1], array[high]);
    return (i + 1);
}

long long doQuickSortWithCounting(int *array, int low, int high) {
    long long comparisons = 0;
    if (++comparisons && low < high) {
        int pi = partitionCounting(array, low, high, comparisons);
        
        comparisons += doQuickSortWithCounting(array, low, pi - 1);
        comparisons += doQuickSortWithCounting(array, pi + 1, high);
    }
    return comparisons;
}

long long quickSortWithCounting(int *array, int arraySize) {
    return doQuickSortWithCounting(array, 0, arraySize - 1);
}

void bubbleSort(int* array, int size) {
    for (int step = 0; step < size; ++step) {
        for (int i = 0; i < size - step - 1; ++i) {
            if (array[i] > array[i + 1]) {
                swap(array[i], array[i + 1]);
            }
        }
    }
}

long long bubbleSortWithCounting(int* array, int size) {
    long long comparisons = 0;

    for (int step = 0; ++comparisons && step < size; ++step) {
        for (int i = 0; ++comparisons &&  i < size - step - 1; ++i) {
            if ( ++comparisons && array[i] > array[i + 1]) {
                swap(array[i], array[i + 1]);
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
        swap(array[min_idx], array[step]);
    }
}

long long selectionSortWithCounting(int* arr, int size) {
    long long comparisons = 0;
    
    for (int step = 0; ++comparisons &&  step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; ++comparisons &&  i < size; i++) {
            if ( ++comparisons && arr[i] < arr[min_idx])
                min_idx = i;
        }
        swap(arr[min_idx], arr[step]); // Use the swap function
    }
    
    return comparisons;
}


