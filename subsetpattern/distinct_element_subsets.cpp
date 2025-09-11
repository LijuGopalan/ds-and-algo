/*
    Subsets (Powerset)

    Problem Statement:
    Given a set with distinct elements, find all of its distinct subsets.
    This is also known as finding the powerset.

    Example 1:
    Input: [1, 3]
    Output: [], [1], [3], [1,3]

    Example 2:
    Input: [1, 5, 3]
    Output: [], [1], [5], [3], [1,5], [1,3], [5,3], [1,5,3]

    Algorithm Description:
    This solution uses an iterative approach to build the subsets.
    1. Start with an empty set in the list of subsets: `[[]]`
    2. For each number in the input set:
       a. Take all existing subsets found so far.
       b. Create a copy of each existing subset and add the current number to it.
       c. Add these new subsets to the list of subsets.

    Example walk-through for [1, 5, 3]:
    - Start: `[[]]`
    - Add 1: `[[], [1]]`
    - Add 5: `[[], [1], [5], [1,5]]`
    - Add 3: `[[], [1], [5], [1,5], [3], [1,3], [5,3], [1,5,3]]`

    Time Complexity: O(n * 2^n), because for each of the `n` elements, we iterate through
    all existing subsets, and the number of subsets doubles each time.
    Space Complexity: O(n * 2^n), to store the `2^n` subsets, each with an average length of n/2.
*/

#include <iostream>
#include <vector>

/**
 * @brief Finds all distinct subsets (the powerset) of a set of distinct integers.
 *
 * @param nums A vector of distinct integers.
 * @return A 2D vector containing all subsets of the input set.
 */
std::vector<std::vector<int>> findSubsets(const std::vector<int>& nums) {
    std::vector<std::vector<int>> subsets;
    // Start with an empty set in the list of subsets
    subsets.push_back({});

    // Iterate through each number in the input set
    for (int currentNumber : nums) {
        // Take all existing subsets and add the current number to them to create new subsets
        int n = subsets.size();
        for (int i = 0; i < n; i++) {
            std::vector<int> set(subsets[i]);
            set.push_back(currentNumber);
            subsets.push_back(set);
        }
    }
    return subsets;
}

/**
 * @brief Prints the 2D vector of subsets.
 * @param subsets A vector of vectors to print.
 */
void printSubsets(const std::vector<std::vector<int>>& subsets) {
    for (const auto& subset : subsets) {
        std::cout << "[ ";
        for (int num : subset) {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }
}

/**
 * @brief Main function to test the findSubsets function.
 * @return 0 on successful execution.
 */
int main() {
    std::vector<int> nums1 = {1, 5, 3};
    std::cout << "Subsets for {1, 5, 3}:" << std::endl;
    std::vector<std::vector<int>> result1 = findSubsets(nums1);
    printSubsets(result1);

    std::cout << "\nSubsets for {1, 3}:" << std::endl;
    std::vector<int> nums2 = {1, 3};
    std::vector<std::vector<int>> result2 = findSubsets(nums2);
    printSubsets(result2);

    return 0;
}