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
int countingSortWithCounting(int* array, int arraySize);
void countingSortForRadix(int* array, int arraySize, int place);
void radixSort(int* array, int arraySize);
void countingSortForRadixWithCounting(int* array, int arraySize, int place, int &countCompare);
int radixSortWithCounting(int* array, int arraySize);
void flashSort(int* array, int arraySize);
int flashSortWithCounting(int* array, int arraySize);