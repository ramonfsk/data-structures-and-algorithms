//
//  main.cpp
//  MaximumSubarraySum
//
//  Created by Ramon Ferreira do Nascimento on 11/09/23.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubarraySum(vector<int> arr) {
    if (*max_element(arr.begin(), arr.end()) < 0) {
        return 0;
    }
    
    int maxSoFar = INT_MIN;
    int maxEndingHere = 0;
    
    for (int index = 0; index < arr.size(); index++) {
        maxEndingHere += arr[index];
        if (maxSoFar < maxEndingHere) {
            maxSoFar = maxEndingHere;
        }
        
        if (maxEndingHere < 0) {
            maxEndingHere = 0;
        }
    }
    
    return maxSoFar;
}

int main(int argc, const char * argv[]) {
    vector<int> arr {-1, 2, 3, 4, -2, 6, -8, 3};
    
    //output expected: 13
    cout << maxSubarraySum(arr) << endl;
    
    return 0;
}
