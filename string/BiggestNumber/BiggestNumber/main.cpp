//
//  main.cpp
//  BiggestNumber
//
//  Created by Ramon Ferreira on 13/06/24.
//

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
