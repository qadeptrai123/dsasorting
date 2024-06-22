#pragma once
#include<iostream>
#include<cmath>
#include<stdlib.h>



void shellSort(int *array, int numberOfElements);
void shellSortWithCounting(int *array, int numberOfElements, int &countAssign , int &countCompare);
void swapElement(int *num1, int *num2);
void heapSort(int *array, int numberOfElements);
void heapify(int *array, int numberOfElements, int currentIndex);
void heapifyWithCounting(int *array, int numberOfElements, int currentIndex, int &countAssign , int &countCompare);
void heapSortWithCounting(int *array, int numberOfElements, int &countAssign , int &countCompare);
void mergeTwoSubArrays(int *array, int left, int middleIndex, int right);
void mergeSort(int *array, int leftIndex, int rightIndex);
void mergeTwoSubArraysWithCounting(int *array, int left, int middleIndex, int right, int &countAssign , int &countCompare);
void mergeSortWithCounting(int *array, int leftIndex, int rightIndex, int &countAssign , int &countCompare);
void countingSort (int* array, int arraySize);
long long countingSortWithCounting(int* array, int arraySize);
void countingSortForRadix(int* array, int arraySize, int place);
void radixSort(int* array, int arraySize);
void countingSortForRadixWithCounting(int* array, int arraySize, int place, long long &countCompare);
long long radixSortWithCounting(int* array, int arraySize);
void flashSort(int* array, int arraySize);
long long flashSortWithCounting(int* array, int arraySize);
void swap(int *a, int *b);
int partition(int *array, int low, int high);
void quickSort(int *array, int low, int high);
int partition(int *array, int low, int high, long long &comparisons);
long long quickSortCounting(int *array, int low, int high);
void bubbleSort(int* array, int size);
long long bubbleSortCounting(int* array, int size);
void selectionSort(int* array, int size);
long long selectionSortCounting(int* arr, int size);