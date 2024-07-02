//
//  main.cpp
//  ReplaceBlankSpaces
//
//  Created by Ramon Ferreira on 01/07/24.
//

#include <iostream>
#include <cstring>

using namespace std;

void replace_space(char *str) {
    int spaces = 0;
    
    for (int index = 0; str[index] != '\0'; index++) {
        if (str[index] == ' ') {
            spaces += 1;
        }
    }
    
    int strIndex = strlen(str) + (2 * spaces);
    str[strIndex] = '\0';
    
    for (int index = (strlen(str) -1); index >= 0; index--) {
        if (str[index] == ' ') {
            str[strIndex-1] = '0';
            str[strIndex-2] = '2';
            str[strIndex-3] = '%';
            strIndex = strIndex - 3;
        } else {
            str[strIndex-1] = str[index];
            strIndex--;
        }
    }
}

int main() {
    char input[10000];
    cin.getline(input, 1000);
    
    replace_space(input);
    
    cout << input << endl;
    
    return 0;
}
