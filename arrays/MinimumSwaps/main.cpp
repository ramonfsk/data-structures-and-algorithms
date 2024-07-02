//
//  main.cpp
//  MinimumSwaps
//
//  Created by Ramon Ferreira on 01/07/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countMinSwaps(vector<int> arr) {
    int countOfCycles = 0;
    //know the actual position of elements (sorting) store the current indices
    pair<int, int> numbersAndIndices[arr.size()];
    for (int index = 0; index < arr.size(); index++) {
        numbersAndIndices[index].first = arr[index];
        numbersAndIndices[index].second = index;
    }
    
    //sorting
    sort(numbersAndIndices, numbersAndIndices+arr.size());
    
    //build the main logic
    vector<bool> visited(arr.size(), false);
    
    for (int index = 0; index < arr.size(); index++) {
        // if element is visited or element is in right position
        int oldPosition = numbersAndIndices[index].second;
        if (visited[index] == true or oldPosition == index) {
            continue;
        }
        // visiting the element (index) for first time
        int node = index;
        int cycle = 0;
        
        while (!visited[node]) {
            visited[node] = true;
            int nextNode = numbersAndIndices[node].second;
            node = nextNode;
            cycle += 1;
        }
        
        countOfCycles += (cycle-1);
    }
    
    return countOfCycles;
}

int main() {
    vector<int> arr {5, 3, 1, 4, 2};
    
    cout << countMinSwaps(arr) << endl;
    
    return 0;
}
