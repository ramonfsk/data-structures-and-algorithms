//
//  main.cpp
//  BiggestNumberString
//
//  Created by Ramon Ferreira on 02/07/24.
//

/*
 Biggest Number String Exercise

 You are given a vector of numbers. You want to concatenate these numbers together to form the lexicographically largest number. Print that largest number number. You can't rearrange the digits of any number, however you can place the numbers next to each other in any order.
 
 Input:
     10, 11, 20, 30, 3
 Output:
     330201110
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    string strA = to_string(a);
    string strB = to_string(b);
    return strA + strB > strB + strA;
}

string concatenate(vector<int> numbers){
    sort(numbers.begin(), numbers.end(), compare);
    
    if (numbers[0] == 0) {
        return "0";
    }
    
    string result;
    for (int number : numbers) {
        result += to_string(number);
    }
    
    return result;
}

int main() {
    vector<int> numbers = {10,11,20,30,3};
    cout << concatenate(numbers) << endl;
    return 0;
}
