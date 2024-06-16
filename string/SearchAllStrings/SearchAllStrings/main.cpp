//
//  main.cpp
//  SearchAllStrings
//
//  Created by Ramon Ferreira on 07/06/24.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> stringSearch(string paragraph, string word){
    //store the occurrences in the result vector
    vector<int> result = {};
    
    size_t index = paragraph.find(word);
    
    while (index != -1) {
        result.push_back(index);
        index = paragraph.find(word, index+1);
    }
    
    return result;
}

int main() {
    vector<int> result = stringSearch("I liked the movie, acting in movie was great!", "movie");

    for (auto v: result) {
        cout << v << ", ";
    }
    
    return 0;
}
