//
//  main.cpp
//  Bitwise
//
//  Created by Ramon Ferreira on 02/07/24.
//

#include <iostream>

using namespace std;

int getIthBit(int n, int i) {
    int mask = (1 << i);
    
    return (n & mask) > 0 ? 1 : 0;
}

void setIthBit(int &n, int i) {
    int mask = (1 << i);
    
    n = (n | mask);
}

void clearIthBit(int &n, int i) {
    int mask = ~(1 << i);
    
    n = (n & mask);
}

void updateIthBit(int &n, int i, int v) {
    clearIthBit(n, i);
    
    int mask = (v << i);
    
    n = (n | mask);
}

void clearLastIthBit(int &n, int i) {
    int mask = (-1 << i);
    
    n = n & mask;
}

int main() {
    int n = 15;
    int i = 2;
    
//    cout << getIthBit(n, i) << endl;
//    setIthBit(n, i);
//    clearIthBit(n, i);
//    updateIthBit(n, i, 0);
    clearLastIthBit(n, i);
    
    cout << n << endl;
    
    return 0;
}
