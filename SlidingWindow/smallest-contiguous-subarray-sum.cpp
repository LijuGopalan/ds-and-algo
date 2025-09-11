
/*

Problem Statement:

Given an array of positive numbers and a positive number S, find the length of the smallest contiguous subarray whose sum is greater than or equal to S. 
If no such subarray exists, return 0.

Approach:
We can solve this problem efficiently using the sliding window technique. 
The idea is to maintain a window of elements that keeps track of the current sum. 
The window will grow and shrink dynamically based on whether the sum is greater than or equal to S


Input: [2, 1, 5, 2, 3, 2], S=7 
Output: 2
Explanation: The smallest subarray with a sum great than or equal to '7' is [5, 2].

Input: [2, 1, 5, 2, 8], S=7 
Output: 1
Explanation: The smallest subarray with a sum greater than or equal to '7' is [8].

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

/**
 * @brief Finds the length of the smallest contiguous subarray with a sum >= S.
 *
 * This function uses the sliding window technique. It expands a window from the right,
 * adding elements to `windowSum`. Once `windowSum` is greater than or equal to the target `S`,
 * it records the window's length as a candidate for the smallest length, and then shrinks
 * the window from the left until the sum is no longer >= S. This process continues until
 * the end of the array is reached.
 *
 * @param arr A constant reference to the input vector of positive integers.
 * @param S The target sum to be greater than or equal to.
 * @return The length of the smallest contiguous subarray, or 0 if no such subarray exists.
 */
int findMinSubArray(const std::vector<int>& arr, int S) {
    if (arr.empty()) {
        return 0;
    }

    int windowStart = 0;
    int windowSum = 0;
    int minLength = std::numeric_limits<int>::max();

    for (int windowEnd = 0; windowEnd < arr.size(); ++windowEnd) {
        windowSum += arr[windowEnd]; // Add the next element to the window

        // Shrink the window as small as possible while the sum is still >= S
        while (windowSum >= S) {
            // Update the minimum length found so far
            minLength = std::min(minLength, windowEnd - windowStart + 1);

            // Subtract the element leaving the window and slide the window forward
            windowSum -= arr[windowStart];
            windowStart++;
        }
    }

    // If minLength was never updated, it means no subarray was found
    if (minLength == std::numeric_limits<int>::max()) {
        return 0;
    }

    return minLength;
}

/**
 * @brief Main function to test the findMinSubArray function.
 *
 * Runs examples from the problem description and prints the results.
 *
 * @return 0 on successful execution.
 */
int main() {
    // Example 1
    std::vector<int> input1 = {2, 1, 5, 2, 3, 2};
    int S1 = 7;
    std::cout << "Input: {2, 1, 5, 2, 3, 2}, S=7" << std::endl;
    std::cout << "Length of smallest subarray: " << findMinSubArray(input1, S1) << std::endl; // Expected: 2
    std::cout << "--------------------" << std::endl;

    // Example 2
    std::vector<int> input2 = {2, 1, 5, 2, 8};
    int S2 = 7;
    std::cout << "Input: {2, 1, 5, 2, 8}, S=7" << std::endl;
    std::cout << "Length of smallest subarray: " << findMinSubArray(input2, S2) << std::endl; // Expected: 1
    std::cout << "--------------------" << std::endl;

    // Example 3 (No such subarray)
    std::vector<int> input3 = {1, 1, 1, 1};
    int S3 = 5;
    std::cout << "Input: {1, 1, 1, 1}, S=5" << std::endl;
    std::cout << "Length of smallest subarray: " << findMinSubArray(input3, S3) << std::endl; // Expected: 0

    return 0;
}
