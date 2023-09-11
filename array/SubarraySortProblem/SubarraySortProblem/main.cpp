//
//  main.cpp
//  SubarraySortProblem
//
//  Created by Ramon Ferreira do Nascimento on 08/09/23.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool outOfOrder(vector<int> arr, int index) {
    int x = arr[index];
    
    if (index == 0) {
        return x > arr[1];
    }
    
    if (index == arr.size()-1) {
        return x < arr[index-1];
    }
    
    return x > arr[index+1] or x < arr[index-1];
}

pair<int, int> subarraySort(vector<int> arr) {
    int smallest = INT_MAX;
    int largest = INT_MIN;
    
    for (int i = 0; i < arr.size(); i++)  {
        int x = arr[i];
        
        if (outOfOrder(arr, i)) {
            smallest = min(smallest, x);
            largest = max(largest, x);
        }
    }
    
    //next step, find the right index where smallest and largest lie (subarray) for out solution
    if (smallest==INT_MAX) {
        return {-1, -1};
    }
    
    int left = 0;
    while (smallest >= arr[left]) {
        left++;
    }
    
    int right = (int) arr.size()-1;
    while (largest <= arr[right]) {
        right--;
    }
    
    return {left, right};
}

int main(int argc, const char * argv[]) {
    vector<int> arr {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    
    auto subArray = subarraySort(arr);
    
    cout << subArray.first << " and " << subArray.second << endl;
    
    return 0;
}
