#include "sortFunction.h"
#include "DataGenerator.h"
#include<fstream>
#include<string>
#include<string.h>
#include<chrono>

using namespace std;

using namespace std::chrono;

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

int order(string inputOrder) {
    if(inputOrder == "-rand") return 0;
    if(inputOrder == "-nsorted") return 3;
    if(inputOrder == "-sorted") return 1;
    if(inputOrder == "-rev") return 2;
    return -1;
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

long long benchmark(int *a, int n, string algorithm) {
    void (*sortAlgorithm)(int*, int) = getSort(algorithm);
    auto start = steady_clock::now();
    sortAlgorithm(a, n);
    auto end = steady_clock::now();
    long long time = duration_cast<nanoseconds>(end - start).count();
    return time;
}

int toInt(string s) {
    int res = 0;
    int n = s.length();
    for(int i = 0; i < n; ++i) res = res*10 + s[i] - '0';
    return res;
}

int* readArrayFromFile(string fileName, int &n) {
    ifstream fin;
    fin.open(fileName);
    if(!fin.is_open()) {
        cout << "Cannot open file\n";
        exit(0);
    }
    fin >> n;
    int *res = new int[n];
    for(int i = 0; i < n; ++i) {
        fin >> res[i];
    }
    fin.close();
    return res;
}

void writeArrayToFile(int *a, int n, string fileName) {
    ofstream fout;
    fout.open(fileName);
    fout << n << "\n";
    for(int i = 0; i < n; ++i) {
        fout << a[i] << " ";
    }
    fout.close();
}

int checkSorted(int *a, int n) {
    for(int i = 0; i < n-1; ++i) {
        if(a[i] > a[i+1]) return 0;
    }
    return 1;
}

void doSortAlgorithm(string algorithm, int *array, int arraySize, string parameter) {
    if(parameter == "-both") {
        int *dupArray = new int[arraySize];
        for(int i = 0; i < arraySize; ++i) dupArray[i] = array[i];
        cout << "Running time: " << benchmark(array, arraySize, algorithm) << "\n";
        cout << "Comparisons: " << getSortCounting(algorithm)(dupArray, arraySize) << "\n";
        delete[] dupArray;
    }
    else if(parameter == "-time") {
        cout << "Running time: " << benchmark(array, arraySize, algorithm) << "\n";
    }
    else if(parameter == "-comp") {
        cout << "Comparisons: " << getSortCounting(algorithm)(array, arraySize) << "\n";
    }
}

void doCompareSortAlgorithm(string algorithm1, string algorithm2, int *array, int arraySize) {
    long long time1 = benchmark(array, arraySize, algorithm1);
    long long time2 = benchmark(array, arraySize, algorithm2);
    cout << "Running time: " << time1 << " | " << time2 << "\n";
    long long comp1 = getSortCounting(algorithm1)(array, arraySize);
    long long comp2 = getSortCounting(algorithm2)(array, arraySize);
    cout << "Comparisons: " << comp1 << " | " << comp2 << "\n";
}

void doCmd1(string algorithm, string inputFile, string parameter) {
    cout << "CMD1\n";
    cout << "Algorithm: " << getAlgorithmName(algorithm) << "\n";
    cout << "Input file: " << inputFile << "\n";
 
    int n;
    int *a = readArrayFromFile(inputFile, n);
   
    cout << "Input size: " << n << "\n";
    cout << "-----------------\n";
    
    doSortAlgorithm(algorithm, a, n, parameter);
    
    writeArrayToFile(a, n, "output.txt");

    delete[] a;
}

void doCmd2(string algorithm, int n, string inputOrder, string parameter) {
    cout << "CMD2\n";
    cout << "Algorithm: " << getAlgorithmName(algorithm) << "\n";
    cout << "Input size: " << n << "\n";
    cout << "Input order: " << getNameOrder(inputOrder) << "\n";
    cout << "-----------------\n";
    int *a = new int[n];
    GenerateData(a, n, order(inputOrder));
    
    writeArrayToFile(a, n, "input.txt");
    
    doSortAlgorithm(algorithm, a, n, parameter);
    
    writeArrayToFile(a, n, "output.txt");

    delete[] a;
}

void doCmd3(string algorithm, int n, string parameter) {
    cout << "CMD3\n";
    cout << "Algorithm: " << getAlgorithmName(algorithm) << "\n";
    cout << "Input size: " << n << "\n";
    cout << "\n";
    int *a = new int[n];
    GenerateData(a, n, 0);
    cout << "Input order: " << getNameOrder("-rand") << "\n";
    cout << "-----------------\n";
    writeArrayToFile(a, n, "input_1.txt");
    doSortAlgorithm(algorithm, a, n, parameter);
    cout << "\n";

    GenerateData(a, n, 3);
    cout << "Input order: " << getNameOrder("-nsorted") << "\n";
    cout << "-----------------\n";
    writeArrayToFile(a, n, "input_2.txt");
    doSortAlgorithm(algorithm, a, n, parameter);
    cout << "\n";

    GenerateData(a, n, 1);
    cout << "Input order: " << getNameOrder("-sorted") << "\n";
    cout << "-----------------\n";
    writeArrayToFile(a, n, "input_3.txt");
    doSortAlgorithm(algorithm, a, n, parameter);
    cout << "\n";

    GenerateData(a, n, 2);
    cout << "Input order: " << getNameOrder("-rev") << "\n";
    cout << "-----------------\n";
    writeArrayToFile(a, n, "input_4.txt");
    doSortAlgorithm(algorithm, a, n, parameter);
    cout << "\n";

    delete[] a;
}

void doCmd4(string algorithm1, string algorithm2, string inputFile) {
    cout << "CMD4\n";
    cout << "Algorithm: " << getAlgorithmName(algorithm1) << " | " << getAlgorithmName(algorithm2) << "\n";
    cout << "Input file: " << inputFile << "\n";
    int n;
    int *a = readArrayFromFile(inputFile, n);
    cout << "Input size: " << n << "\n";
    cout << "-----------------\n";
    doCompareSortAlgorithm(algorithm1, algorithm2, a, n);
    delete[] a;
}

void doCmd5(string algorithm1, string algorithm2, int inputSize, string inputOrder) {
    cout << "CMD5\n";
}

int main(int argc, char *argv[]) {
    //cmd1: [Execution file] -a [Algorithm] [Given input] [Output parameter(s)]
    //cmd2: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]
    //cmd3: [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]
    //cmd4: [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]
    //cmd5: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]

    if(strcmp(argv[1], "-check") == 0) {
        int n = toInt(argv[2]);
        int t = toInt(argv[3]);
        string inputOrder = argv[4];
        string algorithm = argv[5];
        while(t--) {
            int *a = new int[n];
            GenerateData(a, n, order(inputOrder));
            getSort(algorithm)(a, n);
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
    int type = strcmp(argv[1], "-a") == 0 ? 1 : 0;
    //cout << type << "\n";
    //cout << argc << "\n";
    switch (type) {
        case 1:
            cout << "ALGORITHM MODE\n";
            if(argc == 5) {
                string algorithm = argv[2];
                string input = argv[3];
                string parameter = argv[4];
                if(isFileTxt(input)) {
                    doCmd1(algorithm, input, parameter);
                }
                else {
                    doCmd3(algorithm, toInt(input), parameter);
                }
            }
            else {
                string algorithm = argv[2];
                int size = atoi(argv[3]);
                string order = argv[4];
                string parameter = argv[5];
                doCmd2(algorithm, size, order, parameter);
            }
            break;
        case 0:
            cout << "COMPARISON MODE\n";
            if(argc == 5) {
                string algorithm1 = argv[2];
                string algorithm2 = argv[3];
                string inputFile = argv[4];
                doCmd4(algorithm1, algorithm2, inputFile);
            }
            else {
                string algorithm1 = argv[2];
                string algorithm2 = argv[3];
                int inputSize = atoi(argv[4]);
                string inputOrder = argv[5];
                doCmd5(algorithm1, algorithm2, inputSize, inputOrder);
            }
            break;
        default:
            cout << "Invalid argument" << endl;
            break;
    }

    return 0;
}