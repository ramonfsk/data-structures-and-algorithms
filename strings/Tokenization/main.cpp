//
//  main.cpp
//  Tokenization
//
//  Created by Ramon Ferreira on 02/07/24.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

void usingSStream() {
    string input;
    getline(cin, input);
    
    stringstream ss(input);
    
    string token;
    vector<string> tokens;
    
    while (getline(ss, token, ' ')) {
        tokens.push_back(token);
    }
    
    for (auto token: tokens) {
        cout << token << ", ";
    }
}

void usingStrTok() {
    char input[1000];
    cin.getline(input, 1000);
    
    // internally maintains the state of the string you passed in the last fn called
    char *token = strtok(input, " ");
    
    while (token != NULL) {
        cout << token << endl;
        token = strtok(NULL, " ");
    }
}

char *myStrTok(char *str, char delim) {
    static char *input = NULL;
    
    if (str != NULL) {
        input = str;
    }
    
    if (input == NULL) {
        return NULL;
    }
    
    static char *token = new char[strlen(input)+1];
    int index = 0;
    
    for (; input[index] != '\0'; index++) {
        if (input[index] != delim) {
            token[index] = input[index];
        } else {
            token[index] = '\0';
            input = input + index + 1;
            return token;
        }
    }
    
    token[index] = '\0';
    input = NULL;
    return token;
}

int main() {
//    usingSStream();
//    usingStrTok();
    
    char s[1000];
    cin.getline(s, 1000);
    
    char *token = myStrTok(s, ' ');
    
    while (token != NULL) {
        cout << token << endl;
        token = myStrTok(NULL, ' ');
    }
    
    return 0;
}
