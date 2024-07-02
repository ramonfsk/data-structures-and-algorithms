//
//  main.cpp
//  PalindromeBreak
//
//  Created by Ramon Ferreira on 02/07/24.
//

/*
 Palindrome Break Exercise

 Given a palindromic string of lowercase English letters palindrome, replace exactly one character with any lowercase English letter so that the resulting string is not a palindrome and that it is the lexicographically smallest one possible.

 Return the resulting string. If there is no way to replace a character to make it not a palindrome, return an empty string.

 Example-1
     Input: palindrome = "abccba"
     Output: "aaccba"

 Explanation: There are many ways to make "abccba" not a palindrome, such as "zbccba", "aaccba", and "abacba".

 Of all the ways, "aaccba" is the lexicographically smallest.

 Example-2
     Input: palindrome = "a"
     Output: ""

 Explanation: There is no way to replace a single character to make "a" not a palindrome, so return an empty string.

 Example-3
     Input: palindrome = "aa"
     Output: "ab"

 Example-4
     Input: palindrome = "aba"
     Output: "abb"
 */

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
