/* Program with sliding window pattern */

/*

    Maximum Sum Subarray of Size K
    Given an array of positive numbers and a positive number ‘k’, find the maximum sum of any contiguous subarray of size ‘k’.

    Example 1:

    Input: [2, 1, 5, 1, 3, 2], k=3 
    Output: 9
    Explanation: Subarray with maximum sum is [5, 1, 3].

    Example 2:

    Input: [2, 3, 4, 1, 5], k=2 
    Output: 7
    Explanation: Subarray with maximum sum is [3, 4].

*/

#include <iostream>
#include <vector>
#include <algorithm> // Required for std::max

/**
 * @brief Finds the maximum sum of any contiguous subarray of size k.
 *
 * This function uses the sliding window technique to efficiently find the maximum sum.
 * It maintains a window of size k, calculates its sum, and slides the window one
 * element at a time, updating the sum and tracking the maximum sum found.
 *
 * @param input A constant reference to a vector of integers.
 * @param k The size of the subarray window.
 * @return The maximum sum of a contiguous subarray of size k. Returns 0 if k is invalid.
 */
int maxSumSubarrayOfSizeK(const std::vector<int>& input, int k) {
    int n = input.size();
    if (k > n || k <= 0) {
        // Handle invalid input: window size cannot be larger than the array or non-positive.
        return 0;
    }

    int sum = 0;
    int result = 0;
    int start = 0;

    for(int end = 0; end < n; end++) {
        sum += input[end]; // Add the next element to the window

        // Once the window is of size k, we can process it
        if(end >= k - 1) {
            result = std::max(result, sum); // Update the maximum sum found so far
            sum -= input[start];            // Subtract the element that is leaving the window
            start++;                        // Slide the window forward
        }
    }

    return result;
}

/**
 * @brief Main function to demonstrate the maxSumSubarrayOfSizeK function.
 *
 * Initializes a sample vector and a window size k, calls the function,
 * and prints the result to the console.
 *
 * @return 0 on successful execution.
 */
int main() {
    // Example 1
    std::vector<int> input1 = {2, 1, 5, 1, 3, 2};
    int k1 = 3;
    int result1 = maxSumSubarrayOfSizeK(input1, k1);
    std::cout << "Input: [2, 1, 5, 1, 3, 2], k=3" << std::endl;
    std::cout << "Maximum sum: " << result1 << std::endl; // Expected output: 9

    std::cout << "--------------------" << std::endl;

    // Example 2
    std::vector<int> input2 = {2, 3, 4, 1, 5};
    int k2 = 2;
    int result2 = maxSumSubarrayOfSizeK(input2, k2);
    std::cout << "Input: [2, 3, 4, 1, 5], k=2" << std::endl;
    std::cout << "Maximum sum: " << result2 << std::endl; // Expected output: 7

    return 0;
}
