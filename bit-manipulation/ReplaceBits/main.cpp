//
//  main.cpp
//  ReplaceBits
//
//  Created by Ramon Ferreira on 02/07/24.
//

/*
 Replace Bits in N by M
 
 Your are given two 32-bits numbers, N and M, and two bit positions i and j.
 Write a method to set all bits between i and j in N equal to M.
 M (becomes a substring of N locationed at and starting at j)
 
 Input:
    N = 10000000000
    M = 10101
    i = 2
    j = 6
 Output:
    1001010100
 */

#include <iostream>

using namespace std;

void clearBitsInRange(int &n, int i, int j) {
    int a = (~0) << (j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;
    
    n = n & mask;
}

void replaceBits(int &n, int m, int i, int j) {
    clearBitsInRange(n, i, j);
    int mask = (m << i);
    
    n = n | mask;
}

int main() {
    int n = 15;
    int m = 2;
    int i = 1;
    int j = 6;
    
    replaceBits(n, m, i, j);
    
    cout << n << endl;
    
    return 0;
}
