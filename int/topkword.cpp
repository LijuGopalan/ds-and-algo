/*

Top K Frequent Words

Given an array of strings words and an integer k, return the k most frequent strings.
Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 
Constraints:

1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]

Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?

*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
using namespace std;

int main() {

    vector<string> words = {"i","love","leetcode","i","love","coding"};
    int k = 2;
    vector<string> result;

    map<string,int> m;

    //find the word frequency using map
    for(string t : words) {
        m[t]++; // if the word is not in the map, it will be added with value 1
    }

    //create a priority queue to store the frequency of the words
    priority_queue<pair<int,string>> pq; // max heap

    //store the frequency of the words in the priority queue
    for(auto it : m) {
        pq.push({it.second,it.first});

        //if the size of the priority queue is greater than k, pop the top element
        if(pq.size() > k) {
            pq.pop();
        }
    }

    //store the top k frequent words in the result vector
    while(!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }

    //print the result
    for(string t : result) {
        cout << t << " ";
    }

    return 1;

}
