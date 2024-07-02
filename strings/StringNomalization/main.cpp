//
//  main.cpp
//  StringNomalization
//
//  Created by Ramon Ferreira on 02/07/24.
//

/*
 String Normalisation Exercise

 You are given a sentence with words separated by spaces.
 Your task is to:
     Write a function that returns a copy of this sentence where all the words:
         start with a capital letter
         the rest of the letters are lower case

 Note:
     Your function should not modify the sentence given as argument.

 Sample Input:
     This is SO MUCH FUN!
 Sample Output:
     This Is So Much Fun!
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int skipWhiteSpace(const string &sentence, int idx) {
    while (idx < sentence.length() && sentence[idx] == ' ') {
        idx += 1;
    }
    
    return idx;
}

int normalizeWord(string &sentence, int idx) {
    if (idx < sentence.length() && sentence[idx != ' ']) {
        sentence[idx] = toupper(sentence[idx]);
        idx += 1;
    }
    
    while (idx < sentence.length() && sentence[idx != ' ']) {
        sentence[idx] = tolower(idx);
        idx += 1;
    }
    
    return idx;
}

string normalizeV2(const string &sentence) {
    string copy = sentence;
    int idx = 0;
    
    while (idx < copy.length()) {
        idx = skipWhiteSpace(copy, idx);
        idx = normalizeWord(copy, idx);
    }
    
    return copy;
}

string normalize(const string &sentence) {
    string copy = sentence;
    
    int n = copy.size();
    for (int i = n; i >= 0 ; i--) {
        copy[i] = tolower(copy[i]);
        
        if (copy[i] == ' ') {
            copy[i + 1] = toupper(copy[i + 1]);
        }
    }
    
    copy[0] = toupper(copy[0]);
    
    return copy;
}

int main() {
    cout << normalizeV2("This is SO MUCH FUN!") << endl;
    
    string s = "0x71f";
    cout << stoi(s, nullptr, 16) << endl;
    
    return 0;
}
