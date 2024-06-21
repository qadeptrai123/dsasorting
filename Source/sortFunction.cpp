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

//Counting Sort
//https://www.programiz.com/dsa/counting-sort
//https://www.youtube.com/watch?v=7zuGmKfUt7s

void countingSort (int* array, int numberOfElements){
    //Find the largest number of the array
    int largestElement = array[0];
    for (int i = 1; i < numberOfElements; i++){
        largestElement = (array[i] > largestElement) ? array[i] : largestElement;
    }

    //Initialize count array and store the count of each element
    int* count = new int [largestElement + 1](); //initialize with 0
    for (int i = 0; i < numberOfElements; i++){
        count[array[i]]++;
    }

    // Calculate cumulative count
    for (int i = 1; i <= largestElement; i++){
        count[i] += count[i - 1];
    }

    // Place the elements in sorted order
    int* outputArray = new int [numberOfElements];
    for (int i = numberOfElements - 1; i >= 0; i--){
        outputArray[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    //Copy output array to array
    for (int i = 0; i < numberOfElements; i++){
        array[i] = outputArray[i];
    }
    delete []count;
    delete []outputArray;
}

void countingSortWithCounting (int* array, int numberOfElements, int &countCompare){
    countCompare = 0;

    int largestElement = array[0];
    for (int i = 0; ++countCompare && i < numberOfElements; i++){
        largestElement = (array[i] > largestElement) ? array[i] : largestElement;
        ++countCompare;
    }

    int* count = new int [largestElement + 1]();
    for (int i = 0; ++countCompare && i < numberOfElements; i++){
        count[array[i]]++;
    }

    for (int i = 1; ++countCompare && i <= largestElement; i++){
        count[i] += count[i - 1];
    }

    int* outputArray = new int [numberOfElements];
    for (int i = numberOfElements - 1; ++countCompare && i >= 0; i--){
        outputArray[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; ++countCompare && i <numberOfElements; i++){
        array[i] = outputArray[i];
    }
    delete[] count;
    delete[] outputArray;
}

//Radix Sort
//https://www.programiz.com/dsa/radix-sort
//https://www.youtube.com/watch?v=nu4gDuFabIM

void countingSortForRadix(int* array, int numberOfElements, int place) {
    int* output = new int[numberOfElements];
    int count[10] = {0}; //Initialzie count array of digit (0 to 9) with all zero
    
    // Calculate and store the count of each element
    for (int i = 0; i < numberOfElements; i++){
        count[(array[i] / place) % 10]++;
    }
    
    // Calculate cumulative count
    for (int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }
    // Place the elements in sorted order
    for (int i = numberOfElements - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    //Copy output array to array
    for (int i = 0; i < numberOfElements; i++){
        array[i] = output[i];
    }

    delete[] output;
}

void radixSort(int* array, int numberOfElements) {
    //Find the largest number of the array
    int largestElement = array[0];
    for (int i = 1; i < numberOfElements; i++){
        largestElement = (array[i] > largestElement) ? array[i] : largestElement;
    }

    // Use ounting sort to sort elements based on place value.
    for (int place = 1; largestElement / place > 0; place *= 10){
        countingSortForRadix(array, numberOfElements, place);
    }
}

void countingSortForRadixWithCounting(int* array, int numberOfElements, int place, int &countCompare) {
    int* output = new int[numberOfElements];
    int count[10] = {0};
    
    for (int i = 0; ++countCompare && i < numberOfElements; i++){
        count[(array[i] / place) % 10]++;
    }
    
    for (int i = 1; ++countCompare && i < 10; i++){
        count[i] += count[i - 1];
    }

    for (int i = numberOfElements - 1; ++countCompare && i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; ++countCompare && i < numberOfElements; i++){
        array[i] = output[i];
    }

    delete[] output;
}

void radixSortWithCounting(int* array, int numberOfElements, int &countCompare) {
    countCompare = 0;
    int largestElement = array[0];
    for (int i = 1; ++countCompare && i < numberOfElements; i++){
        largestElement = (array[i] > largestElement) ? array[i] : largestElement;
    }

    for (int place = 1; ++countCompare && largestElement / place > 0; place *= 10){
        countingSortForRadixWithCounting(array, numberOfElements, place, countCompare);
    }
}

//Flash Sort
//https://www.w3resource.com/javascript-exercises/searching-and-sorting-algorithm/searching-and-sorting-algorithm-exercise-12.php#google_vignette
void flashSort(int* array, int numberOfElements) {
	int numberOfClasses = 0.45 * numberOfElements;
	int* classCounts = new int [numberOfClasses]();
	
	//Find largest and least element
	int minValue = array[0];
	int maxIndex = 0;
	for (int i = 1; i < numberOfElements; i++){
		minValue = (minValue > array[i]) ? array[i] : minValue;
		maxIndex = (array[maxIndex] < array[i]) ? i : maxIndex;
	}
	int maxValue = array[maxIndex];
	
	//Count number elements of each class 
	for (int i = 0; i < numberOfElements; i++){
		int index = (numberOfClasses - 1)*(array[i] - minValue)/(maxValue - minValue);
		classCounts[index]++;
	}
	
	//Find starting position of each class
	for (int i = 1; i < numberOfElements; i++){
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
	int k = numberOfClasses - 1;
	
	while (move < (numberOfElements - 1)){
		while (j > (classCounts[i] - 1)){
			j++;
			k = (numberOfClasses - 1)*(array[i] - minValue)/(maxValue - minValue);
		}
		if (k < 0) break;
		flash = array[j];
		while (j != classCounts[k]){
			k = (numberOfClasses - 1)*(array[i] - minValue)/(maxValue - minValue);
			i = --classCounts[k];
			hold = array[i];
			array[i] = flash;
			flash = hold;
			++move;
		}
	}
	
    //Sort by insertion sort
	for (j = 1; j < numberOfElements; j++){
		hold = array[j];
		int index = j - 1;
		while (index >= 0 && array[index] > hold){
			array[index + 1] = array[index--];
		}
		array[index + 1] = hold;
	}
	delete[] classCounts;
}

void flashSortWithCounting(int* array, int numberOfElements, int& countCompare){
    countCompare = 0;
	int numberOfClasses = 0.45 * numberOfElements;
	int* classCounts = new int [numberOfClasses]();

	int minValue = array[0];
	int maxIndex = 0;
	for (int i = 1; ++countCompare && i < numberOfElements; i++){
		minValue = (++countCompare && minValue > array[i]) ? array[i] : minValue;
		maxIndex = (++countCompare && array[maxIndex] < array[i]) ? i : maxIndex;
	}
	int maxValue = array[maxIndex];

	for (int i = 0;++countCompare &&  i < numberOfElements; i++){
		int index = (numberOfClasses - 1)*(array[i] - minValue)/(maxValue - minValue);
		classCounts[index]++;
	}

	for (int i = 1;++countCompare &&  i < numberOfElements; i++){
		classCounts[i] += classCounts[i - 1];
	}

	int hold = array[maxIndex];
	array[maxIndex] = array[0];
	array[0] = hold;
	
	int move = 0;
	int flash = 0;
	int i = 0;
	int j = 0; 
	int k = numberOfClasses - 1;
	
	while (++countCompare && move < (numberOfElements - 1)){
		while (++countCompare && j > (classCounts[i] - 1)){
			j++;
			k = (numberOfClasses - 1)*(array[i] - minValue)/(maxValue - minValue);
		}
		if (++countCompare && k < 0) break;
		flash = array[j];
		while (++countCompare && j != classCounts[k]){
			k = (numberOfClasses - 1)*(array[i] - minValue)/(maxValue - minValue);
			i = --classCounts[k];
			hold = array[i];
			array[i] = flash;
			flash = hold;
			++move;
		}
	}
	
	for (j = 1;++countCompare &&  j < numberOfElements; j++){
		hold = array[j];
		int index = j - 1;
		while (++countCompare && index >= 0 && ++countCompare &&  array[index] > hold){
			array[index + 1] = array[index--];
		}
		array[index + 1] = hold;
	}
	delete[] classCounts;
}        

//QA (ShakerSort, InsertionSort)
void shakerSort(int *array, int numberOfElements) {

}

int shakerSortWithCounting(int *array, int numberOfElements) {

}