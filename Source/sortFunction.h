#pragma once
#include<iostream>
#include<cmath>
#include<string>
#include<string.h>
#include<stdlib.h>


void shellSort(int *array, int arraySize);
long long shellSortWithCounting(int *array, int arraySize);

void heapSort(int *array, int arraySize);
void heapify(int *array, int arraySize, int currentIndex);
void heapifyWithCounting(int *array, int arraySize, int currentIndex, long long &countCompare);
long long heapSortWithCounting(int *array, int arraySize);


void mergeTwoSubArrays(int *array, int left, int middleIndex, int right);
void mergeSort(int *array, int arraySize);
void doMergeSort(int *array, int leftIndex, int rightIndex);
void mergeTwoSubArraysWithCounting(int *array, int left, int middleIndex, int right, long long &countCompare);
long long mergeSortWithCounting(int *array, int leftIndex, int rightIndex, long long &countCompare);


void countingSort (int* array, int arraySize);
long long countingSortWithCounting(int* array, int arraySize);

void countingSortForRadix(int* array, int arraySize, int place);
void radixSort(int* array, int arraySize);
void countingSortForRadixWithCounting(int* array, int arraySize, int place, long long &countCompare);
long long radixSortWithCounting(int* array, int arraySize);

void flashSort(int* array, int arraySize);
long long flashSortWithCounting(int* array, int arraySize);

int partition(int *array, int low, int high);
void quickSort(int *array, int arraySize);
void doQuickSort(int *array, int low, int high);
int partition(int *array, int low, int high, long long &comparisons);

long long quickSortWithCounting(int *array, int low, int high);

void bubbleSort(int* array, int size);
long long bubbleSortWithCounting(int* array, int size);

void selectionSort(int* array, int size);
long long selectionSortCounting(int* arr, int size);

void insertionSort(int* array, int arraySize);
long long insertionSortWithCounting(int* array, int arraySize);

void shakerSort(int* array, int arraySize);
long long shakerSortWithCounting(int* array, int arraySize);

