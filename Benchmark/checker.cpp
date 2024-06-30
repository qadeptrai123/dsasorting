#include<iostream>
#include<fstream>
#include"DataGenerator.h"
#include"sortFunction.h"

using namespace std;

int checkSorted(int *a, int n) {
    for(int i = 0; i < n-1; ++i) {
        if(a[i] > a[i+1]) return 0;
    }
    return 1;
}

int main() {
    int n = 10000;
    int t = 100;
    while(t--) {
        int *a = new int[n];
        GenerateData(a, n, 0);
        // for(int i = 0; i < n; ++i) cout << a[i] << " ";
        // cout << "\n";
        quickSort(a, 0, n-1);
        // for(int i = 0; i < n; ++i) cout << a[i] << " ";
        int ok = checkSorted(a, n);
        if(ok == 0) {
            cout << "Bug\n";
            return 0;
        }
        delete[] a;
    }
    cout << "Passed\n";


    return 0;
}