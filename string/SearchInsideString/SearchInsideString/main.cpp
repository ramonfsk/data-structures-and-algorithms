//
//  main.cpp
//  SearchInsideString
//
//  Created by Ramon Ferreira on 07/06/24.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string paragraph = "We are learning about STL strings. STL string class is quite powerful";
    
    string word;
    getline(cin, word);
    
    size_t index = paragraph.find(word);
    
    if (index != -1) {
        cout << "first occ " << index << endl;
    }
    
    index = paragraph.find(word, index+1);
    
    if (index != -1) {
        cout << "second occ " << index << endl;
    }
    
    if (index == -1) {
        cout << "string not found\n";
    }
    
    return 0;
}
