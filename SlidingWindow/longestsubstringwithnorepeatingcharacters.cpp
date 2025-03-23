/*

    Problem Statement #
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

using namespace std;

int main () {

    string str = "aabccbb";
    int result = 0;

    //sliding window logic
    int windowStart = 0;
    unordered_map<char, int> charIndexMap;

    for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
        char rightChar = str[windowEnd];

        if (charIndexMap.find(rightChar) != charIndexMap.end()) {

            charIndexMap[rightChar] = windowEnd;

            windowStart =  (charIndexMap[rightChar] );
        } else {
            charIndexMap[rightChar] = windowEnd;
        } 
     
        result = max(result, windowEnd - windowStart + 1);
    }

    cout << endl << "result is : " << result << endl;

    return result;
}