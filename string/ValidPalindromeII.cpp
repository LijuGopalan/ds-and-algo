#include <iostream>
#include <string>
#include <algorithm>

bool isPalindromeRange(const std::string& s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool validPalindrome(const std::string& s) {
    int i = 0;
    int j = s.length() - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return isPalindromeRange(s, i + 1, j) || isPalindromeRange(s, i, j - 1);
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    std::string s1 = "aba";
    std::cout << s1 << " is " << (validPalindrome(s1) ? "a valid palindrome II" : "not a valid palindrome II") << std::endl;

    std::string s2 = "abca";
    std::cout << s2 << " is " << (validPalindrome(s2) ? "a valid palindrome II" : "not a valid palindrome II") << std::endl;

    std::string s3 = "abc";
    std::cout << s3 << " is " << (validPalindrome(s3) ? "a valid palindrome II" : "not a valid palindrome II") << std::endl;

    return 0;
}
