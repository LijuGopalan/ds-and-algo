/*

        Given an array containing 0s and 1s, if you are allowed to replace no more than ‘k’ 0s with 1s, find the length of the longest contiguous subarray having all 1s.

        Example 1:

        Input: Array=[0, 0, 1, 1, 0, 1, 1], k=2
        Output: 6
        Explanation: Replace the '0' at index 5 and 8 to have the longest contiguous subarray of 1s having length 6.
        Example 2:

        Input: Array=[0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1], k=3
        Output: 9
        Explanation: Replace the '0' at index 6, 9, and 10 to have the longest contiguous subarray of 1s having length 9.


*/

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Finds the length of the longest contiguous subarray of 1s after replacing at most k zeros.
 *
 * This function uses a sliding window approach. The window is expanded by moving the `windowEnd`
 * pointer. Inside the window, we count the number of ones (`maxOnesCount`). The number of zeros
 * is then the window size minus the ones count. If the number of zeros exceeds k, the window
 * is shrunk from the left by moving the `windowStart` pointer. The maximum window size encountered
 * is tracked and returned as the result.
 *
 * @param arr A constant reference to the input vector of 0s and 1s.
 * @param k The maximum number of zeros that can be replaced with ones.
 * @return The length of the longest possible contiguous subarray of 1s.
 */
int findLength(const std::vector<int>& arr, int k) {
    int windowStart = 0, maxLength = 0, maxOnesCount = 0;

    // Iterate through the array to slide the window's end
    for (int windowEnd = 0; windowEnd < arr.size(); ++windowEnd) {
        if (arr[windowEnd] == 1) {
            maxOnesCount++;
        }

        // The number of zeros in the current window is its size minus the count of ones.
        // If this count is greater than k, we must shrink the window from the left.
        if ((windowEnd - windowStart + 1 - maxOnesCount) > k) {
            if (arr[windowStart] == 1) {
                maxOnesCount--; // Decrement ones count if a 1 is sliding out of the window
            }
            windowStart++; // Shrink the window
        }

        // The current window size is a candidate for the max length
        maxLength = std::max(maxLength, windowEnd - windowStart + 1);
    }

    return maxLength;
}

/**
 * @brief Main function to test the findLength function.
 *
 * Runs test cases from the problem description and prints the results to the console.
 *
 * @return 0 on successful execution.
 */
int main() {
    // Example 1
    std::vector<int> input1 = {0, 1, 1, 0, 0, 1, 1};
    int k1 = 2;
    std::cout << "Input: {0, 1, 1, 0, 0, 1, 1}, k=2" << std::endl;
    std::cout << "Length of longest subarray with 1s: " << findLength(input1, k1) << std::endl; // Expected: 6

    std::cout << "--------------------" << std::endl;

    // Example 2
    std::vector<int> input2 = {0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1};
    int k2 = 3;
    std::cout << "Input: {0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1}, k=3" << std::endl;
    std::cout << "Length of longest subarray with 1s: " << findLength(input2, k2) << std::endl; // Expected: 9

    return 0;
}