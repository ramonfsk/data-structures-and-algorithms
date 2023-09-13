//
//  main.cpp
//  ArrayProductsProblem
//
//  Created by Ramon Ferreira do Nascimento on 13/09/23.
//

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
ostream &printArray(ostream &os, vector<T> const &arr) {
    ranges::copy(arr, ostream_iterator<T>(os, ", "));
    return os;
}

vector<int> productArray(vector<int> arr) {
    int sizeOfArray = (int) arr.size();
    
    vector<int> output(sizeOfArray, 1);
    
    int index, swap = 1;
    
    for (index = 0; index < sizeOfArray; index++) {
        output[index] = swap;
        swap *= arr[index];
    }
    
    swap = 1;
    
    for (index = sizeOfArray-1; index >= 0; index--) {
        output[index] *= swap;
        swap *= arr[index];
    }
    
    return output;
}

int main(int argc, const char * argv[]) {
    vector<int> arr {1, 2, 3, 4, 5};
    
    printArray(cout, productArray(arr)) << endl;
    
    return 0;
}
