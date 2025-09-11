/*
    Maximum Subarray

    Problem Statement:
    Given an integer array `nums`, find the contiguous subarray (containing at least one number)
    which has the largest sum and return its sum.

    Example 1:
    Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
    Output: 6
    Explanation: The subarray [4,-1,2,1] has the largest sum 6.

    Example 2:
    Input: nums = [5,4,-1,7,8]
    Output: 23
    Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

    Algorithm Description (Kadane's Algorithm):
    This solution uses Kadane's Algorithm, a dynamic programming approach that solves
    this problem in O(n) time.
    1. Initialize `maxSoFar` and `currentMax` to the first element of the array.
    2. Iterate through the array starting from the second element.
    3. For each element, update `currentMax` to be the maximum of the current element itself
       or the current element plus the `currentMax` from the previous step. This step
       decides whether to extend the existing subarray or start a new one.
    4. Update `maxSoFar` to be the maximum of its current value and `currentMax`. This
       tracks the largest sum found anywhere in the array.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm> // For std::max

/**
 * @brief Finds the largest sum of a contiguous subarray using Kadane's Algorithm.
 *
 * @param nums The input vector of integers.
 * @return The largest sum of any contiguous subarray.
 */
int maxSubArray(const std::vector<int>& nums) {
    if (nums.empty()) {
        return 0; // Or throw an exception for an empty array
    }

    int maxSoFar = nums[0];
    int currentMax = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        // Decide whether to extend the current subarray or start a new one
        currentMax = std::max(nums[i], currentMax + nums[i]);
        // Update the overall maximum sum found
        maxSoFar = std::max(maxSoFar, currentMax);
    }

    return maxSoFar;
}

/**
 * @brief Main function to test the maxSubArray function.
 * @return 0 on successful execution.
 */
int main() {
    // Example 1
    std::vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << "Input: {-2, 1, -3, 4, -1, 2, 1, -5, 4}" << std::endl;
    std::cout << "Maximum subarray sum: " << maxSubArray(nums1) << " (Expected: 6)" << std::endl;
    std::cout << "--------------------" << std::endl;

    // Example 2
    std::vector<int> nums2 = {1};
    std::cout << "Input: {1}" << std::endl;
    std::cout << "Maximum subarray sum: " << maxSubArray(nums2) << " (Expected: 1)" << std::endl;
    std::cout << "--------------------" << std::endl;

    // Example 3
    std::vector<int> nums3 = {5, 4, -1, 7, 8};
    std::cout << "Input: {5, 4, -1, 7, 8}" << std::endl;
    std::cout << "Maximum subarray sum: " << maxSubArray(nums3) << " (Expected: 23)" << std::endl;

    return 0;
}