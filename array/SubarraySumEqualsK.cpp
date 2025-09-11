/*
    Subarray Sum Equals K

    Problem Statement:
    Given an array of integers `nums` and an integer `k`, return the total number
    of continuous subarrays whose sum equals to k.

    Example 1:
    Input: nums = [1,1,1], k = 2
    Output: 2
    Explanation: The two subarrays are [1,1] and [1,1].

    Example 2:
    Input: nums = [1,2,3], k = 3
    Output: 2
    Explanation: The two subarrays are [1,2] and [3].

    Algorithm Description:
    This solution uses a hash map to store the cumulative prefix sums encountered so far
    and their frequencies. The approach is as follows:
    1. Initialize a hash map `prefixSumMap` with `{0, 1}` to handle subarrays that
       start from index 0.
    2. Iterate through the array, maintaining a `currentSum`.
    3. For each `currentSum`, we check if `currentSum - k` exists in the hash map.
       If it does, it means there is a previous prefix sum that, if removed from the
       `currentSum`, would leave us with a subarray sum of `k`. The number of times
       `currentSum - k` has occurred is the number of new subarrays ending at the
       current position that sum to `k`.
    4. Add the `currentSum` to the hash map, incrementing its frequency.

    Time Complexity: O(n), as we iterate through the array once.
    Space Complexity: O(n), as the hash map can store up to n different prefix sums in the worst case.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

/**
 * @brief Counts the number of continuous subarrays whose sum equals k.
 *
 * @param nums The input vector of integers. The const qualifier is added as the vector is not modified.
 * @param k The target sum.
 * @return The total number of continuous subarrays summing to k.
 */
int subarraySum(const std::vector<int>& nums, int k) {
    int count = 0;
    int currentSum = 0;
    // Map to store prefix sums and their frequencies.
    std::unordered_map<int, int> prefixSumMap;
    // Base case: a prefix sum of 0 has occurred once (the empty prefix).
    prefixSumMap[0] = 1;

    for (int num : nums) {
        currentSum += num;
        // Check if a subarray with sum k can be formed by removing a previous prefix sum.
        if (prefixSumMap.count(currentSum - k)) {
            count += prefixSumMap.at(currentSum - k);
        }
        // Add the current prefix sum to the map.
        prefixSumMap[currentSum]++;
    }
    return count;
}

/**
 * @brief Main function to test the subarraySum function.
 * @return 0 on successful execution.
 */
int main() {
    // Example 1
    std::vector<int> nums1 = {1, 1, 1};
    int k1 = 2;
    std::cout << "Input: {1, 1, 1}, k = 2" << std::endl;
    std::cout << "The number of subarrays with sum " << k1 << " is " << subarraySum(nums1, k1) << " (Expected: 2)" << std::endl;
    std::cout << "--------------------" << std::endl;

    // Example 2
    std::vector<int> nums2 = {1, 2, 3};
    int k2 = 3;
    std::cout << "Input: {1, 2, 3}, k = 3" << std::endl;
    std::cout << "The number of subarrays with sum " << k2 << " is " << subarraySum(nums2, k2) << " (Expected: 2)" << std::endl;

    return 0;
}
