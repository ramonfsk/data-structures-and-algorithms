//
//  main.cpp
//  RunLengthEncoding
//
//  Created by Ramon Ferreira on 02/07/24.
//

/*
 Run Length Encoding Exercise

 Write a function to perform basic string compression using the counts of repeated characters, also known as Run Length Encoding. Let see one example, the input string "aaaabcccccaaa" would become "a4b1c5a3". If the "compressed" string would not become smaller than the original string, your function should return the input string. You can assume the string has only uppercase and lowercase letters. You may use the to_string(int) method to convert an integer into string.

 Sample Inputs:
     bbbaaaadexxxxxx
     abc
 Sample Outputs:
     b3a4d1e1x6
     abc
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

string compressString(const string &str){
    map<char, int> charFrequencies;
        
    for (char ch: str) {
        charFrequencies[ch]++;
    }
    
    if (charFrequencies.size() == str.size()) {
        return str;
    }
    
    string compressedStr;
    
    for (auto pair : charFrequencies) {
        compressedStr += pair.first + to_string(pair.second);
    }
    
    return compressedStr;
}

string compressString_v2(const string &str){
    string sortedStr = str;
    sort(sortedStr.begin(), sortedStr.end());
    string compressedStr;
    
    int count = 1;
    for (int i = 1; i <= sortedStr.size(); ++i) {
        if (i == sortedStr.size() || sortedStr[i] != sortedStr[i - 1]) {
            compressedStr += sortedStr[i - 1];
            compressedStr += to_string(count);
            count = 1;
        } else {
            ++count;
        }
    }
    
    return compressedStr.size() < str.size() ? compressedStr : str;
}


int main() {
    cout << compressString_v2("bbbaaaadexxxxxx") << endl;
    return 0;
}
