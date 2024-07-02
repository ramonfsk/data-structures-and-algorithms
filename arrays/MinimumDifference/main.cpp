//
//  main.cpp
//  MinimumDifference
//
//  Created by Ramon Ferreira on 01/07/24.
//

/*
 Minumum Difference Exercise
 
 Implement a function that takes in two non-empty arrays of integers, finds the pair of numbers (one from each array) who absolute difference is closest to zero, and returns a pair containing these two numbers, with the first number from array. Only one such pair will exist for the test.
 
 Input:
    arr1 = [23, 5, 10, 17, 30]
    arr2 = [26, 134, 135, 14, 19]
 Output:
    17, 19
 */

#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

pair<int, int> minimumDifference(vector<int> a, vector<int> b) {
    // sort arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    pair<int, int> result;
    int minDiff = INT_MAX;
    
    int i = 0; // pointer for array 'a'
    int j = 0; // pointer for array 'b'
    
    while (i < a.size() && j < b.size()) {
        int currentMinDiff = abs(a[i] - b[j]);
        
        if (minDiff > currentMinDiff) {
            minDiff = currentMinDiff;
            result.first = a[i];
            result.second = b[j];
        }
        
        // Move the pointers based on the comparison
        if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }
    
    return result;
}

int main() {
    vector<int> firstArr {23, 5, 10, 17, 30};
    vector<int> secondArr {26, 134, 135, 14, 19};
    
    pair<int, int> result = minimumDifference(firstArr, secondArr);
    
    cout
    << "["
    << result.first
    << ", "
    << result.second
    << "]"
    << endl;
    
    return 0;
}
