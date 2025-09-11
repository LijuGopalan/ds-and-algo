
/*

Find All Anagrams in a String
 
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
 
Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.
 
*/


#include <iostream>
#include <vector>
#include <string>

/**
 * @brief Finds all starting indices of p's anagrams in s.
 *
 * This function uses a sliding window approach with frequency maps (represented by vectors)
 * to efficiently find all occurrences of anagrams of string p within string s.
 * An anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
 * typically using all the original letters exactly once.
 *
 * @param s The string to search within.
 * @param p The pattern string for which to find anagrams.
 * @return A vector of integers containing the starting indices of all found anagrams.
 */
std::vector<int> findAnagrams(const std::string& s, const std::string& p) {
    if (s.length() < p.length()) {
        return {};
    }

    std::vector<int> p_freq(26, 0);
    std::vector<int> window_freq(26, 0);

    // Populate frequency map for p and the initial window in s
    for (int i = 0; i < p.length(); ++i) {
        p_freq[p[i] - 'a']++;
        window_freq[s[i] - 'a']++;
    }

    std::vector<int> result;
    // Check if the initial window is an anagram
    if (p_freq == window_freq) {
        result.push_back(0);
    }

    // Slide the window across the rest of string s
    for (int i = p.length(); i < s.length(); ++i) {
        // Add the new character entering the window from the right
        window_freq[s[i] - 'a']++;
        // Remove the character that is leaving the window from the left
        window_freq[s[i - p.length()] - 'a']--;

        // Check if the current window's character frequencies match p's frequencies
        if (p_freq == window_freq) {
            // The starting index of this anagram window is (i - p.length() + 1)
            result.push_back(i - p.length() + 1);
        }
    }

    return result;
}

/**
 * @brief Main function to test the findAnagrams function.
 *
 * Runs test cases from the problem description and prints the starting
 * indices of found anagrams to the console.
 *
 * @return 0 on successful execution.
 */
int main() {
    std::string s1 = "cbaebabacd", p1 = "abc";
    std::vector<int> result1 = findAnagrams(s1, p1);
    std::cout << "Anagrams of \"" << p1 << "\" in \"" << s1 << "\" found at indices: ";
    for (int index : result1) {
        std::cout << index << " ";
    }
    std::cout << std::endl; // Expected: 0 6

    std::string s2 = "abab", p2 = "ab";
    std::vector<int> result2 = findAnagrams(s2, p2);
    std::cout << "Anagrams of \"" << p2 << "\" in \"" << s2 << "\" found at indices: ";
    for (int index : result2) {
        std::cout << index << " ";
    }
    std::cout << std::endl; // Expected: 0 1 2

    return 0;
}

 