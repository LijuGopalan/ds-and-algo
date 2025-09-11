/*
    Top K Frequent Words

    Problem Statement:
    Given an array of strings `words` and an integer `k`, return the `k` most frequent strings.
    Return the answer sorted by the frequency from highest to lowest. Sort words with the
    same frequency by their lexicographical order.

    Example 1:
    Input: words = ["i","love","leetcode","i","love","coding"], k = 2
    Output: ["i","love"]
    Explanation: "i" and "love" are the two most frequent words. "i" comes before "love"
    due to a lower alphabetical order.

    Example 2:
    Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
    Output: ["the","is","sunny","day"]
    Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with
    frequencies 4, 3, 2, and 1 respectively.

    Algorithm Description:
    This solution uses a hash map to count word frequencies and a min-heap to find the
    top k frequent elements efficiently.
    1. Count the frequency of each word using an `unordered_map`.
    2. Create a min-heap (`priority_queue`) of size k. A custom comparator is used to
       order elements. The heap considers an element "smaller" if its frequency is lower.
       If frequencies are equal, it considers the element with the greater lexicographical
       value as "smaller". This ensures that less frequent or alphabetically larger words
       are evicted first.
    3. Iterate through the frequency map and push pairs of {frequency, word} into the heap.
    4. If the heap size exceeds k, pop the top element (the one with the lowest frequency
       or, in a tie, the one that is lexicographically larger).
    5. After processing all words, the heap contains the top k frequent words. Extract them
       and reverse the order to get the final sorted result.

    Time Complexity: O(n log k), where n is the number of words.
    Space Complexity: O(n) for the frequency map.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

// Define a type for a pair of {frequency, word}
using FreqPair = std::pair<int, std::string>;

/**
 * @struct Compare
 * @brief Custom comparator for the min-heap.
 *
 * This comparator is used by the priority_queue to create a min-heap.
 * It orders pairs based on frequency first (ascending), then by the word's
 * lexicographical order (descending). This way, the element at the top of the
 * heap is the "least" of the top k, and is the one to be evicted if the heap
 * size exceeds k.
 */
struct Compare {
    bool operator()(const FreqPair& a, const FreqPair& b) const {
        if (a.first != b.first) {
            return a.first > b.first; // Min-heap on frequency
        }
        return a.second < b.second; // Max-heap on word (lexicographically)
    }
};

/**
 * @brief Finds the k most frequent words from a given list.
 *
 * @param words The input vector of strings.
 * @param k The number of most frequent words to return.
 * @return A vector of strings containing the k most frequent words, sorted correctly.
 */
std::vector<std::string> topKFrequent(const std::vector<std::string>& words, int k) {
    // 1. Count word frequencies
    std::unordered_map<std::string, int> freqMap;
    for (const std::string& word : words) {
        freqMap[word]++;
    }

    // 2. Use a min-heap of size k
    std::priority_queue<FreqPair, std::vector<FreqPair>, Compare> pq;
    for (const auto& pair : freqMap) {
        pq.push({pair.second, pair.first});
        if (pq.size() > k) {
            pq.pop();
        }
    }

    // 3. Extract results from the heap
    std::vector<std::string> result;
    while (!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }

    // 4. Reverse to get the correct final order (highest frequency first)
    std::reverse(result.begin(), result.end());

    return result;
}

void printVector(const std::vector<std::string>& vec) {
    std::cout << "[ ";
    for (const auto& s : vec) {
        std::cout << "\"" << s << "\" ";
    }
    std::cout << "]" << std::endl;
}

/**
 * @brief Main function to test the topKFrequent function.
 * @return 0 on successful execution.
 */
int main() {
    // Example 1
    std::vector<std::string> words1 = {"i", "love", "leetcode", "i", "love", "coding"};
    int k1 = 2;
    std::cout << "Input: {\"i\",\"love\",\"leetcode\",\"i\",\"love\",\"coding\"}, k = 2" << std::endl;
    std::vector<std::string> result1 = topKFrequent(words1, k1);
    std::cout << "Output: ";
    printVector(result1); // Expected: ["i", "love"]
    std::cout << "--------------------" << std::endl;

    // Example 2
    std::vector<std::string> words2 = {"the","day","is","sunny","the","the","the","sunny","is","is"};
    int k2 = 4;
    std::cout << "Input: {\"the\",\"day\",\"is\",\"sunny\",\"the\",\"the\",\"the\",\"sunny\",\"is\",\"is\"}, k = 4" << std::endl;
    std::vector<std::string> result2 = topKFrequent(words2, k2);
    std::cout << "Output: ";
    printVector(result2); // Expected: ["the", "is", "sunny", "day"]

    return 0;
}
