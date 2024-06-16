#include "sortFunction.h"
#include<iostream>

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//this is Khuong work space
void shellSort(int cc)
{

}

void kkkkkkk() {
    return;
}
