#include "sortFunction.h"
using namespace std;


int main() {
    int arr[100] ={0};
    for (int i = 0; i < 100; ++i)
        arr[i] = rand() % 100;
    for (int i = 0; i < 100; i++)
        cout << arr[i] << " ";
    cout << endl;
    int assign, compare;
    // shellSortWithCounting(arr, 100, assign, compare);
    // heapSortWithCounting(arr, 100, assign, compare);
    for(int i = 0; i < 100; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "---------" << endl;
    cout << "Assignments: " << assign << endl;
    cout << "Comparisons: " << compare << endl;
    return 0;
}