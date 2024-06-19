#include "sortFunction.h"
using namespace std;


int main() {
    int arr[10000] ={0};
    for (int i = 0; i < 10000; ++i)
        arr[i] = rand() % 10000;
    int assign = 0, compare = 0;
    // shellSortWithCounting(arr, 10000, assign, compare);
    // heapSortWithCounting(arr, 10000, assign, compare);
    mergeSortWithCounting(arr, 0, 10000 - 1, assign, compare);
    cout << endl;
    cout << "---------" << endl;
    cout << "Assignments: " << assign << endl;
    cout << "Comparisons: " << compare << endl;
    return 0;
}