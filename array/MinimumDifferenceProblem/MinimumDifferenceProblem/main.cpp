//
//  main.cpp
//  MinimumDifferenceProblem
//
//  Created by Ramon Ferreira do Nascimento on 11/09/23.
//

#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_set>

using namespace std;

pair<int, int> minimumDifference(vector<int> a, vector<int> b) {
    // sort arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    pair<int, int> result;
    
    int minDifference = INT_MAX;
    
    for (int firstIndex = 0; firstIndex < a.size(); firstIndex++) {
        for (int secondIndex = 0; secondIndex < b.size(); secondIndex++) {
            int currentMinDifference = abs(a[firstIndex] - b[secondIndex]);
            
            if (minDifference > currentMinDifference) {
                minDifference = currentMinDifference;
                result.first = a[firstIndex];
                result.second = b[secondIndex];
            }
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> firstArr {23, 5, 10, 17, 30};
    vector<int> secondArr {26, 134, 135, 14, 19};
    
    pair<int, int> result = minimumDifference(firstArr, secondArr);
    
    cout
    << "["
    << result.first
    << ","
    << result.second
    << "]"
    << endl;
    
    return 0;
}
