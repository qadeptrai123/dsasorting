#include "sortFunction.h"
#include "DataGenerator.h"
#include<fstream>
#include<string>
#include<string.h>
#include<chrono>

using namespace std;

using namespace std::chrono;

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

void doSortAlgorithm(string algorithm, int *array, int arraySize, string parameter) {
    // if(algorithm == "shell-sort") {
    //     // if(parameter == "-time" || paramer)
    // }
    // else if(algorithm == "heap-sort") {
    //     heapSort(array, arraySize);
    // }
    // else if(algorithm == "merge-sort") {
    //     mergeSort(array, 0, arraySize-1);
    // }
    // else if(algorithm == "counting-sort") {
    //     countingSort(array, arraySize);
    // }
    // else if(algorithm == "radix-sort") {
    //     radixSort(array, arraySize);
    // }
    // else if(algorithm == "flash-sort") {
    //     flashSort(array, arraySize);
    // }
    // else if(algorithm == "insertion-sort") {
    //     insertionSort(array, arraySize);
    // }
    // else if(algorithm == "selection-sort") {
    //     selectionSort(array, arraySize);
    // }
    // else if(algorithm == "bubble-sort") {
    //     cout << "Running time: " << benchmark(array, arraySize, bubbleSort) << "\n";
    // }
    // else if(algorithm == "quick-sort") {
    //     quickSort(array, 0, arraySize-1);
    // }
    // else if(algorithm == "shaker-sort") {
    //     shakerSort(array, arraySize);
    // }
    // else {
    //     cout << "Invalid algorithm\n";
    //     exit(0);
    // }
    if(parameter == "-both" || parameter == "-time") {
        cout << "Running time: " << benchmark(array, arraySize, algorithm) << "\n";
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
    writeArrayToFile(a, n, "input_1.txt");
    doSortAlgorithm(algorithm, a, n, parameter);
    
    GenerateData(a, n, 3);
    writeArrayToFile(a, n, "input_2.txt");
    doSortAlgorithm(algorithm, a, n, parameter);

    GenerateData(a, n, 1);
    writeArrayToFile(a, n, "input_3.txt");
    doSortAlgorithm(algorithm, a, n, parameter);
    
    GenerateData(a, n, 2);
    writeArrayToFile(a, n, "input_4.txt");
    doSortAlgorithm(algorithm, a, n, parameter);

}

void doCmd4(string algorithm1, string algorithm2, string inputFile) {
    cout << "CMD4\n";
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