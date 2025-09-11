/*
    Longest Substring with No Repeating Characters

    Problem Statement:
    Given a string, find the length of the longest substring which has no repeating characters.

    Example 1:
    Input: String="aabccbb"
    Output: 3
    Explanation: The longest substring without any repeating characters is "abc".

    Example 2:
    Input: String="abbbb"
    Output: 2
    Explanation: The longest substring without any repeating characters is "ab".

    Example 3:
    Input: String="abccde"
    Output: 3
    Explanation: Longest substrings without any repeating characters are "abc" & "cde".
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

/**
 * @brief Finds the length of the longest substring with no repeating characters.
 *
 * This function uses a sliding window approach with a hash map. The map stores the
 * last seen index of each character. The window expands from the right. If a character
 * is encountered that is already in the current window (i.e., its last seen index is
 * greater than or equal to the window's start), the window's start is moved to the
 * position right after the last occurrence of that character to ensure no repeats.
 *
 * @param str The input string.
 * @return The length of the longest substring without repeating characters.
 */
int findLongestSubstring(const std::string& str) {
    if (str.empty()) {
        return 0;
    }

    int windowStart = 0;
    int maxLength = 0;
    std::unordered_map<char, int> charIndexMap; // Stores the last seen index of each character

    for (int windowEnd = 0; windowEnd < str.length(); ++windowEnd) {
        char rightChar = str[windowEnd];

        // Check if the character is already in the map
        if (charIndexMap.find(rightChar) != charIndexMap.end()) {
            // If the character's last seen index is within the current window,
            // we must shrink the window from the left. The new start is one
            // position after the last occurrence of the repeating character.
            // We use max to ensure the window only slides forward.
            windowStart = std::max(windowStart, charIndexMap[rightChar] + 1);
        }

        // Update the last seen index of the current character
        charIndexMap[rightChar] = windowEnd;

        // Calculate the length of the current window and update the max length
        maxLength = std::max(maxLength, windowEnd - windowStart + 1);
    }

    return maxLength;
}

/**
 * @brief Main function to test the findLongestSubstring function.
 *
 * Runs examples from the problem description and prints the results to the console.
 *
 * @return 0 on successful execution.
 */
int main() {
    std::string input1 = "aabccbb";
    std::cout << "Input: \"" << input1 << "\"" << std::endl;
    std::cout << "Length of longest substring: " << findLongestSubstring(input1) << std::endl; // Expected: 3
    std::cout << "--------------------" << std::endl;

    std::string input2 = "abbbb";
    std::cout << "Input: \"" << input2 << "\"" << std::endl;
    std::cout << "Length of longest substring: " << findLongestSubstring(input2) << std::endl; // Expected: 2
    std::cout << "--------------------" << std::endl;

    std::string input3 = "abccde";
    std::cout << "Input: \"" << input3 << "\"" << std::endl;
    std::cout << "Length of longest substring: " << findLongestSubstring(input3) << std::endl; // Expected: 3
    std::cout << "--------------------" << std::endl;

    return 0;
}