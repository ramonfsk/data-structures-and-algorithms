//
//  main.cpp
//  Mountain
//
//  Created by Ramon Ferreira on 01/07/24.
//

#include <iostream>
#include <vector>

using namespace std;

int highestMountain(vector<int> arr) {
    int n = (int) arr.size();
    int largest = 0;
    
    for (int i = 1; i <= n-2;) {
        //check a[i] is peak or not
        if (arr[i] > arr[i-1] and arr[i] > arr[i+1]) {
            int cnt = 1;
            int j = i;
            //cnt backwards (left)
            while (j >= 1 and arr[j] > arr[j-1]) {
                j--;
                cnt++;
            }
            //cnt forwards (right)
            while (i <= n-2 and arr[i] > arr[i+1]) {
                i++;
                cnt++;
            }
            
            largest = max(largest, cnt);
        } else {
            i++;
        }
    }
    
    return largest;
}

int main() {
    vector<int> arr {5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
    
    cout << highestMountain(arr) << endl;
    
    return 0;
}
