/*
    Valid Palindrome II

    Problem Statement:
    Given a string `s`, return `true` if the `s` can be a palindrome after
    deleting at most one character from it.

    Example 1:
    Input: s = "aba"
    Output: true

    Example 2:
    Input: s = "abca"
    Output: true
    Explanation: You could delete the character 'c'.

    Example 3:
    Input: s = "abc"
    Output: false

    Algorithm Description:
    This solution uses a two-pointer approach.
    1. Two pointers, `left` and `right`, start at the beginning and end of the string.
    2. They move towards the center, comparing characters.
    3. If a mismatch is found (`s[left] != s[right]`), it means we must delete one of
       these two characters to have any chance of the string being a palindrome.
    4. We then check two possibilities:
       a) Is the substring from `left+1` to `right` a palindrome? (Simulates deleting `s[left]`)
       b) Is the substring from `left` to `right-1` a palindrome? (Simulates deleting `s[right]`)
    5. If either of these sub-checks returns true, the original string can become a
       palindrome with one deletion.
    6. If the pointers meet without any mismatches, the string is already a palindrome.
*/

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Helper function to check if a substring is a palindrome.
 * @param s The input string.
 * @param left The starting index of the substring.
 * @param right The ending index of the substring.
 * @return True if the substring s[left...right] is a palindrome, false otherwise.
 */
bool isPalindrome(const std::string& s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

/**
 * @brief Checks if a string can become a palindrome by deleting at most one character.
 *
 * @param s The input string.
 * @return True if the string is or can become a palindrome, false otherwise.
 */
bool validPalindrome(const std::string& s) {
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            // Found a mismatch, try deleting either the left or right character
            return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
        }
        left++;
        right--;
    }
    // If the loop completes, the string is already a palindrome.
    return true;
}

/**
 * @brief Main function to test the validPalindrome function.
 * @return 0 on successful execution.
 */
int main() {
    std::vector<std::string> testCases = {"aba", "abca", "abc", "racecar", "abccdba", "abcdefg"};
    std::vector<bool> expected = {true, true, false, true, true, false};

    for (size_t i = 0; i < testCases.size(); ++i) {
        bool result = validPalindrome(testCases[i]);
        std::cout << "Input: \"" << testCases[i] << "\""
                  << ", Can be palindrome? " << (result ? "true" : "false")
                  << " (Expected: " << (expected[i] ? "true" : "false") << ")"
                  << std::endl;
    }

    return 0;
}
