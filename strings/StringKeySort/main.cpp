//
//  main.cpp
//  StringKeySort
//
//  Created by Ramon Ferreira on 02/07/24.
//

/*
 Sample Input
 ------------
 3
 92 022
 82 12
 77 13
 2 false numeric
 
 Sample Output
 ------------
 82 12
 77 13
 92 022
 */

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

string extractStringAtKey(string str, int key) {
    // string tokeniser
    // hello how are you?
    
    char *s = strtok((char *) str.c_str(), " ");
    while (key > 1) {
        s = strtok(NULL, " ");
        key--;
    }
    
    return (string) s;
}

int convertToInt(string str) {
    int ans = 0;
    int p = 1;
    
    for (int index = str.length()-1; index >= 0; index--) {
        ans += ((str[index] - '0') *p);
        p = p * 10;
    }
    
    return ans;
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2) {
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;
    
    return convertToInt(key1) < convertToInt(key2);
}

bool lexicoCompare(pair<string, string> s1, pair<string, string> s2) {
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;
    
    return key1 < key2;
}

int main() {
    int n;
    cin >> n;
    
    cin.get(); // consume the extra \n
    
    string temp;
    vector<string> v;
    
    for (int index = 0; index < n; index++) {
        getline(cin, temp); // includes white spaces
        v.push_back(temp);
    }
    
    int key;
    string reversal, ordering;
    cin >> key >> reversal >> ordering;
    
    // 1. To extract keys for comparsion & store them
    vector<pair<string, string>> vp;
    
    for (int index = 0; index < n; index++) {
        vp.push_back({v[index], extractStringAtKey(v[index], key)});
    }
    
    // 2.Sorting
    if (ordering == "numeric") {
        sort(vp.begin(), vp.end(), numericCompare);
    } else {
        sort(vp.begin(), vp.end(), lexicoCompare);
    }
    
    // 3. Reversal
    if (reversal == "true") {
        reverse(vp.begin(), vp.end());
    }
    
    for (int index = 0; index < n; index++) {
        cout << vp[index].first << endl;
    }
    
    return 0;
}
