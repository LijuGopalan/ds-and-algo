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
#include <unordered_map>
#include <map>

using namespace std;


int get_length_of_distinct_string( string question, int length) 
{

    //follow sliding window approach ( 2 variables start,end begin together. end increments, while start stays unitl length )
    //start increments when a match found to reset the match and look for another. 

    int result = -1;

    if(question.size()<=0 || length <=0 ) {
        return result;
    }

    char temp;
    int size = question.size();
    int start = 0;
    int end = 0;

    // map is required for keep track of distinct characters
    // cannot use set because characters repeat. so we need count of chracters to keep track of length.
    // hence a map is advisible here for quick solution
    unordered_map<char,int> m;

    while( end < size) {

        temp = question[end];
        //store the character to map
        
        if(m.find(temp) == m.end()) {
            m.insert({temp,1}); 
        } else {
            m[temp]++;
        }

        //check whether we found distinct substring of size length
        if(m.size() > length) {

            result = max(end-start,result);

            //we found the first qualified substring length.
            //now increment start pointer to find an another substring from the next start position
            // increment th start pointer until map size is reset to less than length.
            while(m.size()>length) {
                temp = question[start];
                if(m[temp]>1) {
                    m[temp]--;
                } else {
                    m.erase(temp);
                }
                start++;
            }

        } 

        end++;
    }

    return result;

    
}


int main() {

    string input = "araaci"; 
    int k = 2;
    cout << "\n  The longest substring with no more than " << k <<" distinct characters is : " << get_length_of_distinct_string(input,k);
    
    input = "araaci"; 
    k = 1;
    cout << "\n  The longest substring with no more than " << k <<" distinct characters is : " << get_length_of_distinct_string(input,k);

    input = "cbbebi"; 
    k = 3;
    cout << "\n  The longest substring with no more than " << k <<" distinct characters is : " << get_length_of_distinct_string(input,k);

}