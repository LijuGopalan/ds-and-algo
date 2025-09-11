/*
    Finding Top 'K' and 'Kth' Largest Elements

    This file contains solutions for two related problems:
    1. Find the Kth Largest Element in an Array.
    2. Find the Top K Largest Elements in an Array.

    These problems are classic interview questions that can be solved efficiently
    using data structures like heaps (priority queues).
*/

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <functional>

/**
 * @brief Finds the kth largest element in an array using a min-heap.
 *
 * This function maintains a min-heap of size k. The top of the heap is the kth
 * largest element found so far.
 * Time Complexity: O(n log k)
 * Space Complexity: O(k)
 *
 * @param nums The input vector of integers.
 * @param k The rank of the largest element to find.
 * @return The value of the kth largest element.
 */
int findKthLargest(const std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    for (int num : nums) {
        min_heap.push(num);
        if (min_heap.size() > k) {
            min_heap.pop();
        }
    }
    return min_heap.top();
}

/**
 * @brief Finds the top k largest elements in an array using a min-heap.
 *
 * This function maintains a min-heap of size k. After processing all numbers,
 * the heap contains the top k largest elements.
 * Time Complexity: O(n log k)
 * Space Complexity: O(k)
 *
 * @param nums The input vector of integers.
 * @param k The number of largest elements to find.
 * @return A vector containing the top k largest elements.
 */
std::vector<int> findTopKLargest(const std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    for (int num : nums) {
        min_heap.push(num);
        if (min_heap.size() > k) {
            min_heap.pop();
        }
    }
    std::vector<int> result;
    while (!min_heap.empty()) {
        result.push_back(min_heap.top());
        min_heap.pop();
    }
    std::sort(result.rbegin(), result.rend()); // Sort in descending order
    return result;
}

/**
 * @brief Finds the top k largest elements using a multiset.
 *
 * This approach inserts all elements into a multiset, which keeps them sorted,
 * and then retrieves the first k elements.
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 *
 * @param nums The input vector of integers.
 * @param k The number of largest elements to find.
 * @return A vector containing the top k largest elements.
 */
std::vector<int> findTopKLargestWithSet(const std::vector<int>& nums, int k) {
    std::multiset<int, std::greater<int>> s(nums.begin(), nums.end());
    std::vector<int> result;
    int count = 0;
    for (int val : s) {
        if (count++ < k) {
            result.push_back(val);
        } else {
            break;
        }
    }
    return result;
}


void printVector(const std::vector<int>& arr, const std::string& name) {
    std::cout << name << ": [ ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "]" << std::endl;
}

/**
 * @brief Main function to test the implementations.
 * @return 0 on successful execution.
 */
int main() {
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    std::cout << "--- For nums = {3, 2, 1, 5, 6, 4}, k = 2 ---" << std::endl;
    std::cout << "Kth Largest Element: " << findKthLargest(nums, k) << " (Expected: 5)" << std::endl;
    printVector(findTopKLargest(nums, k), "Top K Largest (Min-Heap)");
    printVector(findTopKLargestWithSet(nums, k), "Top K Largest (Set)");

    std::cout << "\n--- For nums = {3, 2, 3, 1, 2, 4, 5, 5, 6}, k = 4 ---" << std::endl;
    std::vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    std::cout << "Kth Largest Element: " << findKthLargest(nums2, k2) << " (Expected: 4)" << std::endl;
    printVector(findTopKLargest(nums2, k2), "Top K Largest (Min-Heap)");
    printVector(findTopKLargestWithSet(nums2, k2), "Top K Largest (Set)");

    return 0;
}
