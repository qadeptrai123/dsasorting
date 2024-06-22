#include "sortFunction.h"
#include "DataGenerator.h"
#include<string>
#include<string.h>
using namespace std;

int isFileTxt(string input) {
    int n = input.length();
    if('0' <= input[n-1] && input[n-1] <= '9') return 0;
    return input[n-1] == 't' && input[n-2] == 'x' && input[n-3] == 't' && input[n-4] == '.';
}

void doSortAlgorithm(string algorithm, int *array, int arraySize, string parameter) {
    if(algorithm == "shell-sort") {
        //shellSort(array, arraySize);
    }
    else if(algorithm == "heap-sort") {
        //heapSort(array, arraySize);
    }
    else if(algorithm == "merge-sort") {
        //mergeSort(array, 0, arraySize-1);
    }
    else if(algorithm == "counting-sort") {
        //countingSort(array, arraySize);
    }
    else if(algorithm == "radix-sort") {
        //radixSort(array, arraySize);
    }
    else if(algorithm == "flash-sort") {
        //flashSort(array, arraySize);
    }
    else if(algorithm == "insertion-sort") {
    }
    else if(algorithm == "selection-sort") {
    }
    else if(algorithm == "bubble-sort") {
    }
    else if(algorithm == "quick-sort") {
    }
    else if(algorithm == "shaker-sort") {
    }
    else {
        cout << "Invalid algorithm\n";
        exit(0);

    }
}



void doCmd1(string algorithm, string inputFile, string parameter) {
    cout << "CMD1\n";
}
void doCmd2(string algorithm, int size, string order, string parameter) {
    cout << "CMD2\n";
    int *a = new int[20];
    int n = 20;
    GenerateData(a, n, 0);
    for(int i = 0; i < n; ++i) cout << a[i] << " ";
    delete[] a;
}
void doCmd3(string algorithm, string input, string parameter) {
    cout << "CMD3\n";
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
                    doCmd3(algorithm, input, parameter);
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