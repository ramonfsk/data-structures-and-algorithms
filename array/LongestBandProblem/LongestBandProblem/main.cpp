//
//  main.cpp
//  LongestBandProblem
//
//  Created by Ramon Ferreira do Nascimento on 08/09/23.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int largestBand(vector<int> arr) {
    int n = (int) arr.size();
    unordered_set<int> s;
    int largestBand = 0;
    
    //Data inside a set
    for (int x: arr) {
        s.insert(x);
    }
    
    // Iterate over the arr
    for (auto element: s) {
        int parent = element - 1;
        
        if (s.find(parent) == s.end()) {
            //find entire band / chain starting from element
            int nextNumber = element + 1;
            int cnt = 1;
            
            while (s.find(nextNumber) != s.end()) {
                nextNumber++;
                cnt++;
            }
            
            if (cnt > largestBand) {
                largestBand = cnt;
            }
        }
    }
    
    return largestBand;
}

int main(int argc, const char * argv[]) {
    vector<int> arr {1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
    
    // output expetcted 8
    cout << largestBand(arr) << endl;
    
    return 0;
}
