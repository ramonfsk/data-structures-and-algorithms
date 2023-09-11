//
//  main.cpp
//  RainsProblem
//
//  Created by Ramon Ferreira do Nascimento on 08/09/23.
//

#include <iostream>
#include <vector>

using namespace std;

int trappedWater(vector<int> arr) {
    int n = (int) arr.size();
    if (n <= 2) {
        return 0;
    }
    
    //Left Max, Right Max
    vector<int> left(n, 0), right(n, 0);
    left[0] = arr[0];
    right[n-1] = arr[n-1];
    
    for (int i = 1; i < n; i++) {
        left[i] = max(left[i-1], arr[i]);
        right[n-i-1] = max(right[n-i], arr[n-i-1]);
    }
    
    //Water
    int water = 0;
    for (int i = 0; i < n; i++) {
        water += min(left[i], right[i]) - arr[i];
    }
    
    return water;
}

int main(int argc, const char * argv[]) {
    vector<int> arr {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    
    cout << trappedWater(arr) << endl;
    
    return 0;
}
