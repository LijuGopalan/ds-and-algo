
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


// Solution: Sliding window approach

#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool findmatch(map<char,int>& m, string& p) {
    
    for(char c: p) {
        if(m.find(c) == m.end()) {
            return false;
        }
    }
    return true;
}


        
vector<int> findAnagrams(string s, string p) {
    
    map<char,int> m;
    int end = 0;
    int start = 0;
    vector<int> r;

    char c;

    for(;end<s.size();end++) {

        c = s[end];
        if(m.find(c) != m.end()) {
          
            m[c]++;
        } else {

           
            m.insert({c,1});
        } 

        if(end < (p.size()-1)) {
           continue;
        }

        if(findmatch(m,p)) {
            r.push_back(start);
        }

        c = s[start];

        if(m[c] > 1) {
           
            m[c]--;
        } else {
            
            m.erase(c);
        }

        start++;
 
    } 

    return r;
    
} 

int main () {

    string s = "cbaebabacd", p = "abc";

    vector<int> r = findAnagrams(s,p);

    cout << "Result: ";

    for(int i=0;i<r.size();i++) {
        cout << " " << r[i] << " ";
    }
 
}

 