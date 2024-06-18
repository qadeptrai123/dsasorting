#include "sortFunction.h"
using namespace std;


int main() {
    int arr[10] ={0};
    for (int i = 0; i < 10; ++i)
        arr[i] = rand() % 100;
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;
    int assign, compare;
    shellSortWithCounting(arr, 10, assign, compare);
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "---------" << endl;
    cout << "assignments: " << assign << endl;
    cout << "comparisions: " << compare << endl;
    return 0;
}