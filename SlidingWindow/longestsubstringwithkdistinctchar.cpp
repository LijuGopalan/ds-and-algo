/*


  Program with sliding window pattern 
 -------------------------------------

Longest Substring with K Distinct Characters (medium)

Problem Statement #
Given a string, find the length of the longest substring in it with no more than K distinct characters.

Example 1:
Input: String="araaci", K=2
Output: 4
Explanation: The longest substring with no more than '2' distinct characters is "araa".

Example 2:
Input: String="araaci", K=1
Output: 2
Explanation: The longest substring with no more than '1' distinct characters is "aa".

Example 3:
Input: String="cbbebi", K=3
Output: 5
Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".


*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

/**
 * @brief Finds the length of the longest substring with no more than K distinct characters.
 *
 * This function implements the sliding window pattern. It expands a window from the right
 * and keeps track of the distinct characters within the window using a hash map.
 * If the number of distinct characters exceeds K, the window is shrunk from the left
 * until the condition is met again. The maximum window size seen during this process
 * is recorded and returned.
 *
 * @param str The input string.
 * @param k The maximum number of distinct characters allowed in the substring.
 * @return The length of the longest substring with at most K distinct characters. Returns 0 if input is invalid.
 */
int findLongestSubstringLength(const std::string& str, int k) {
    if (str.empty() || k <= 0) {
        return 0;
    }

    int windowStart = 0;
    int maxLength = 0;
    std::unordered_map<char, int> charFrequencyMap;

    // Expand the window by adding one character at a time from the right
    for (int windowEnd = 0; windowEnd < str.length(); ++windowEnd) {
        char rightChar = str[windowEnd];
        charFrequencyMap[rightChar]++;

        // Shrink the window from the left if the number of distinct characters exceeds k
        while (charFrequencyMap.size() > k) {
            char leftChar = str[windowStart];
            charFrequencyMap[leftChar]--;
            if (charFrequencyMap[leftChar] == 0) {
                charFrequencyMap.erase(leftChar);
            }
            windowStart++; // Contract the window
        }

        // Update the maximum length after every expansion
        maxLength = std::max(maxLength, windowEnd - windowStart + 1);
    }

    return maxLength;
}

/**
 * @brief Main function to test the findLongestSubstringLength function.
 *
 * Runs the examples from the problem description and prints their output to the console.
 *
 * @return 0 on successful execution.
 */
int main() {
    std::string input1 = "araaci";
    int k1 = 2;
    std::cout << "Input: \"" << input1 << "\", K=" << k1 << std::endl;
    std::cout << "Length of the longest substring: " << findLongestSubstringLength(input1, k1) << std::endl; // Expected: 4
    std::cout << "--------------------" << std::endl;

    std::string input2 = "araaci";
    int k2 = 1;
    std::cout << "Input: \"" << input2 << "\", K=" << k2 << std::endl;
    std::cout << "Length of the longest substring: " << findLongestSubstringLength(input2, k2) << std::endl; // Expected: 2
    std::cout << "--------------------" << std::endl;

    std::string input3 = "cbbebi";
    int k3 = 3;
    std::cout << "Input: \"" << input3 << "\", K=" << k3 << std::endl;
    std::cout << "Length of the longest substring: " << findLongestSubstringLength(input3, k3) << std::endl; // Expected: 5
    std::cout << "--------------------" << std::endl;

    // Test case where the whole string is the answer
    std::string input4 = "abc";
    int k4 = 3;
    std::cout << "Input: \"" << input4 << "\", K=" << k4 << std::endl;
    std::cout << "Length of the longest substring: " << findLongestSubstringLength(input4, k4) << std::endl; // Expected: 3

    return 0;
}