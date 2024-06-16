//
//  main.cpp
//  LengthEncoding
//
//  Created by Ramon Ferreira on 13/06/24.
//

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
