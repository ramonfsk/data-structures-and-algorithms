//
//  main.cpp
//  MaximumSubarraySum
//
//  Created by Ramon Ferreira on 01/07/24.
//

/*
 Maximum Subarray Sum Exercise
 
 Implement a function that takes an input a vector of integers, and prints the maximum subarray sum that can be formed. A subarray is defined as consecutive segment of the array. If all numbers are negative, then return 0.
 
 Input:
    {-1,2,3,4,-2,6,-8,3}
 Output:
    13
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubarraySum(vector<int> arr) {
    if(*max_element(arr.begin(), arr.end()) < 0) {
        return 0;
    }
    
    int maxSoFar = INT_MIN;
    int maxEndingHere = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        maxEndingHere += arr[i];
        if (maxSoFar < maxEndingHere) {
            maxSoFar = maxEndingHere;
        }
        
        if (maxEndingHere < 0) {
            maxEndingHere = 0;
        }
    }
    
    return maxSoFar;
}

int main() {
    vector<int> arr {-1, 2, 3, 4, -2, 6, -8, 3};
    
    //output expected: 13
    cout << maxSubarraySum(arr) << endl;
    
    return 0;
}
