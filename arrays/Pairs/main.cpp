//
//  main.cpp
//  Pairs
//
//  Created by Ramon Ferreira on 01/07/24.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> pairSum(vector<int> arr, int S) {
    //Logic
    unordered_set<int> s;
    vector<int> result;
    
    for(int i = 0; i < arr.size(); i++) {
        int x = S - arr[i];
        if(s.find(x) != s.end()) {
            result.push_back(x);
            result.push_back(arr[i]);
            return result;
        }
        //insert the current no insed set
        s.insert(arr[i]);
    }
    
    return {};
}

int main() {
    vector<int> arr {10, 5, 2, 3, -6, 9, 11};
    int S = 4;
    
    auto pairs = pairSum(arr, S);
    if(pairs.size() == 0) {
        cout << "No such pair";
    } else {
        cout << pairs[0] << "," << pairs[1] << endl;
    }
    
    return 0;
}
