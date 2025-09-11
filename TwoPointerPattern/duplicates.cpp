/*
    Find the Duplicate Number
    Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

    There is only one repeated number in nums, return this repeated number.

    You must solve the problem without modifying the array nums and using only constant extra space.

    Example 1:
    Input: nums = [1,3,4,2,2]
    Output: 2

    Example 2:
    Input: nums = [3,1,3,4,2]
    Output: 3
*/

/*
    Logic: Binary Search on the Range of Numbers

    This solution is based on binary search. The search space is the range of numbers from 1 to n.
    In each step, we select the middle number `mid` of the current search range and count all numbers
    in the input array that are less than or equal to `mid`.

    If the `count` is greater than `mid`, it means the duplicate number must be in the lower half
    of the range (from 1 to `mid`), according to the Pigeonhole Principle. So, we shrink the search
    space to `[low, mid]`.

    Otherwise, the duplicate must be in the upper half, so we shrink the search space to `[mid + 1, high]`.
    This process continues until the search space is reduced to a single number, which is the duplicate.

    Time Complexity: O(n log n)
    Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

/**
 * @brief Finds the single duplicate number in an array using binary search on the value range.
 *
 * The array `nums` contains n + 1 integers where each integer is in the range [1, n].
 * This function finds the duplicate by performing a binary search on the range of
 * possible number values (from 1 to n), not on the array indices. This is a clever
 * approach that avoids modifying the array and uses constant extra space.
 *
 * @param nums A constant reference to the input vector of integers.
 * @return The repeated number in the array.
 */
int findDuplicate(const std::vector<int>& nums) {
    int low = 1;
    int high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;
        for (int num : nums) {
            if (num <= mid) {
                count++;
            }
        }

        if (count > mid) {
            // The duplicate is in the lower half, including mid
            high = mid;
        } else {
            // The duplicate is in the upper half
            low = mid + 1;
        }
    }
    return low;
}

/**
 * @brief Main function to test the findDuplicate function.
 * @return 0 on successful execution.
 */
int main() {
    std::vector<int> nums1 = {1, 3, 4, 2, 2};
    std::cout << "Input: {1, 3, 4, 2, 2}" << std::endl;
    std::cout << "The duplicate number is: " << findDuplicate(nums1) << std::endl; // Expected: 2
    std::cout << "--------------------" << std::endl;

    std::vector<int> nums2 = {3, 1, 3, 4, 2};
    std::cout << "Input: {3, 1, 3, 4, 2}" << std::endl;
    std::cout << "The duplicate number is: " << findDuplicate(nums2) << std::endl; // Expected: 3
    std::cout << "--------------------" << std::endl;

    std::vector<int> nums3 = {3, 3, 3, 3, 3};
    std::cout << "Input: {3, 3, 3, 3, 3}" << std::endl;
    std::cout << "The duplicate number is: " << findDuplicate(nums3) << std::endl; // Expected: 3
    std::cout << "--------------------" << std::endl;

    return 0;
}