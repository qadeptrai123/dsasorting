#pragma once
#include<iostream>
#include<cmath>
#include<stdlib.h>



void shellSort(int *array, int number_of_elements);
void shellSortWithCounting(int *array, int number_of_elements, int &count_assign , int &count_compare);
void swapElement(int *num1, int *num2);
void heapSort(int array[], int number_of_elements);
void heapify(int array[], int number_of_elements, int current_index);
void heapifyWithCounting(int array[], int number_of_elements, int current_index, int &count_assign , int &count_compare);
void heapSortWithCounting(int array[], int number_of_elements, int &count_assign , int &count_compare);
