//
//  main.cpp
//  CountingSetBits
//
//  Created by Ramon Ferreira on 02/07/24.
//

#include <iostream>

using namespace std;

int countBits(int n) {
    int count = 0;
    
    while (n > 0) {
        int lastBit = (n & 1);
        count += lastBit;
        
        n = n >> 1;
    }
    
    return count;
}

int countBitsHack(int n) {
    int ans = 0;
    
    while (n > 0) {
        // remove the last bits from the current number
        n = n & (n - 1);
        ans++;
    }
    
    return ans;
}

int main() {
    int n;
    cin >> n;

    cout << countBitsHack(n) << endl;
    
    return 0;
}
