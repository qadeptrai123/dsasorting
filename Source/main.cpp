#include "sortFunction.h"
#include "DataGenerator.h"
#include<string>
#include<string.h>
using namespace std;


int main(int argc, char *argv[]) {
    int type = strcmp(argv[1], "-a") == 0 ? 1 : 0;
    //cout << type << "\n";
    switch (type) {
        case 1:
            cout << "ALGORITHM MODE\n";
                
            break;
        case 0:
            cout << "COMPARISON MODE\n";
            break;
        default:
            cout << "Invalid argument" << endl;
            break;
    }

    return 0;
}