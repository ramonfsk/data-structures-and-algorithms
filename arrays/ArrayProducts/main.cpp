//
//  main.cpp
//  ArrayProducts
//
//  Created by Ramon Ferreira on 01/07/24.
//

/*
 Array Products Exercise

 Implement a function that takes in a vector of integers, and returns a vector of the same length, where each element in the output array is equal to the product of every other number in the input array. Solve this problem without using division.
 In other words, the value at output[i] is equal to the product of every number in the input array other than input[i]. You can assume that answer can be stored inside int datatype and no-overflow will occur due to products.

 Sample Input:
     {1, 2, 3, 4, 5}
 Output:
     {120, 60, 40, 30, 24}
 */

#include <iostream>
#include <vector>

using namespace std;

//Expected Complexity O(N)
vector<int> productArray(vector<int> arr) {
    int sizeOfArray = arr.size();
    vector<int> output(sizeOfArray, 1);
    
    int i, swap = 1;
    
    for (i = 0; i < sizeOfArray; i++) {
        output[i] = swap;
        swap *= arr[i];
    }
    
    swap = 1;
    
    for (i = sizeOfArray-1; i >= 0; i--) {
        output[i] *= swap;
        swap *= arr[i];
    }
    
    return output;
}

int main() {
    vector<int> arr {1, 2, 3, 4, 5};
    
    vector<int> result = productArray(arr);
    
    cout << "{ ";
    for (auto n: result) {
        cout << n << ", ";
    }
    cout << "}" << endl;
    
    return 0;
}
