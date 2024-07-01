#include<iostream>
#include<fstream>
#include<chrono>
#include"../Source/sortFunction.h"

using namespace std;
using namespace std::chrono;

int sz[6] = {10000, 30000, 50000, 100000, 300000, 500000};
string szStr[6] = {"10k", "30k", "50k", "100k", "300k", "500k"}; 
string order[4] = {"Random", "Sorted", "Reverse", "NearlySorted"};

long long (*getSortCounting(string algorithm))(int*, int) {
    if (algorithm == "bubble-sort") {
        return &bubbleSortWithCounting;
    } 
    else if (algorithm == "selection-sort") {
        return &selectionSortWithCounting;
    }
    else if (algorithm == "shaker-sort") {
        return &shakerSortWithCounting;
    } 
    else if (algorithm == "heap-sort") {
        return &heapSortWithCounting;
    }
    else if (algorithm == "merge-sort") {
        return &mergeSortWithCounting;
    }
    else if (algorithm == "quick-sort") {
        return &quickSortWithCounting;
    }
    else if (algorithm == "counting-sort") {
        return &countingSortWithCounting;
    }
    else if (algorithm == "radix-sort") {
        return &radixSortWithCounting;
    }
    else if (algorithm == "flash-sort") {
        return &flashSortWithCounting;
    }
    else if (algorithm == "shell-sort") {
        return &shellSortWithCounting;
    }
    else if (algorithm == "insertion-sort") {
        return &insertionSortWithCounting;
    }
    return nullptr;
}

void (*getSort(string algorithm))(int*, int) {
    if (algorithm == "bubble-sort") {
        return &bubbleSort;
    } 
    else if (algorithm == "selection-sort") {
        return &selectionSort;
    }
    else if (algorithm == "shaker-sort") {
        return &shakerSort;
    } 
    else if (algorithm == "heap-sort") {
        return &heapSort;
    }
    else if (algorithm == "merge-sort") {
        return &mergeSort;
    }
    else if (algorithm == "quick-sort") {
        return &quickSort;
    }
    else if (algorithm == "counting-sort") {
        return &countingSort;
    }
    else if (algorithm == "radix-sort") {
        return &radixSort;
    }
    else if (algorithm == "flash-sort") {
        return &flashSort;
    }
    else if (algorithm == "insertion-sort") {
        return &insertionSort;
    }
    else if (algorithm == "shell-sort") {
        return &shellSort;
    }
    else {
        return nullptr;  // Nếu không khớp với thuật toán nào, trả về nullptr
    }
}

string getAlgorithmName(string algorithm) {
    if(algorithm == "shell-sort") {
        return "Shell Sort";
    }
    else if(algorithm == "heap-sort") {
        return "Heap Sort";
    }
    else if(algorithm == "merge-sort") {
        return "Merge Sort";
    }
    else if(algorithm == "counting-sort") {
        return "Counting Sort";
    }
    else if(algorithm == "radix-sort") {
        return "Radix Sort";
    }
    else if(algorithm == "flash-sort") {
        return "Flash Sort";
    }
    else if(algorithm == "insertion-sort") {
        return "Insertion Sort";
    }
    else if(algorithm == "selection-sort") {
        return "Selection Sort";
    }
    else if(algorithm == "bubble-sort") {
        return "Bubble Sort";
    }
    else if(algorithm == "quick-sort") {
        return "Quick Sort";
    }
    else if(algorithm == "shaker-sort") {
        return "Shaker Sort";
    }
    return "";
}

string getNameOrder(string inputOrder) {
    if(inputOrder == "-rand") return "Random";
    if(inputOrder == "-nsorted") return "Nearly Sorted";
    if(inputOrder == "-sorted") return "Sorted";
    if(inputOrder == "-rev") return "Reverse";
    return "";
}

int isFileTxt(string input) {
    int n = input.length();
    if('0' <= input[n-1] && input[n-1] <= '9') return 0;
    return input[n-1] == 't' && input[n-2] == 'x' && input[n-3] == 't' && input[n-4] == '.';
}

int toInt(string s) {
    int res = 0;
    int n = s.length();
    for(int i = 0; i < n; ++i) res = res*10 + s[i] - '0';
    return res;
}

int checkSorted(int *a, int n) {
    for(int i = 0; i < n-1; ++i) {
        if(a[i] > a[i+1]) return 0;
    }
    return 1;
}

long long counting(int *a, int n, string algorithm) {
    void (*sortAlgorithm)(int*, int) = getSort(algorithm);
    auto start = steady_clock::now();
    sortAlgorithm(a, n);
    auto end = steady_clock::now();
    long long time = duration_cast<milliseconds>(end - start).count();
    return time;
}

long long countingComp(int *a, int n, string algorithm) {
    long long (*sortCountingAlgorithm)(int*, int) = getSortCounting(algorithm);
    return sortCountingAlgorithm(a, n);
}


void benchMark(string algorithm, int type, int szType) {
    // cout << algorithm << " " << type << " " << szType << "\n";
    cout << getAlgorithmName(algorithm) << " " << order[type] << " " << szStr[szType] << "\n";
    string f = szStr[szType] + "_" + "type" + "_" + char('0' + szType) + ".txt";
    cout << f << "\n";
    ifstream ifs("../data/" + f);
    int n = sz[szType];
    int *a = new int[n];
    for(int i = 0; i < n; ++i) ifs >> a[i];
    ifs.close();

    int *b = new int[n];
    for(int i = 0; i < n; ++i) b[i] = a[i];

    long long time = counting(a, n, algorithm);
    cout << "Time: " << time << " ms\n";
    long long comp = countingComp(b, n, algorithm);
    cout << "Comp: " << comp << "\n";

    delete[] b;
    delete[] a;
}

int main(int argc, char* argv[]) {
    //argv[2]:
    //  0: Random
    //  1: Sorted
    //  2: Reverse
    //  3: Nearly Sorted

    //argv[3]:
    //  0: 10k
    //  1: 30k
    //  2: 50k
    //  3: 100k
    //  4: 300k
    //  5: 500k

    string algorithm = argv[1];
    int type = toInt(argv[2]);
    int szType = toInt(argv[3]);
    benchMark(algorithm, type, szType);


    return 0;
}