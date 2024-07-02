//
//  main.cpp
//  DecimalToBinary
//
//  Created by Ramon Ferreira on 02/07/24.
//

/*
 Decimal To Binary Exercise
 
 Convert a number from decimal format to binary format.
 
 Input:
    n = 10
 Output:
    1010
 */

#include <iostream>
#include <string>

using namespace std;

string convertToBinary(int num) {
    if (num == 0) {
        return "0";
    }
    
    string binary = "";
    
    while (num > 0) {
        binary = to_string(num % 2) + binary;
        num = num / 2;
    }
    
    return binary;
}

int main() {
    int num;
    cout << "Enter a decimal number: ";
    cin >> num;
    
    cout << "Binary representation: " << convertToBinary(num) << endl;
    
    return 0;
}
