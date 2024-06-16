//
//  main.cpp
//  PalindromeBreak
//
//  Created by Ramon Ferreira on 13/06/24.
//

#include <iostream>
#include <string>

using namespace std;

string breakPalindrome(string palindrome) {
    if (palindrome.size() <= 1) {
        return "";
    }
    
    int n = palindrome.size();

    for (int i = 0; i < n / 2; ++i) {
        if (palindrome[i] != palindrome[0]) {
            palindrome[i] = palindrome[0];
            return palindrome;
        }
    }
    
    palindrome[n - 1] = 'b';
    return palindrome;
}

int main() {
    cout << breakPalindrome("aba") << endl;
    
    return 0;
}
