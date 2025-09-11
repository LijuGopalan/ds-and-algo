/*
    Find First and Last Position of Element in Sorted Array

    Problem Statement:
    Given an array of integers `nums` sorted in non-decreasing order, find the starting
    and ending position of a given `target` value. If `target` is not found in the
    array, return `[-1, -1]`.

    You must write an algorithm with O(log n) runtime complexity.

    Example 1:
    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]

    Example 2:
    Input: nums = [5,7,7,8,8,10], target = 6
    Output: [-1,-1]
*/

#include <iostream>
#include <vector>
#include <utility> // For std::pair

/**
 * @brief Finds the first occurrence of a target value in a sorted array.
 *
 * This function uses a modified binary search. When the target is found, it doesn't
 * stop. Instead, it records the index and continues searching in the left half
 * of the array to find an even earlier occurrence.
 *
 * @param nums The sorted input vector.
 * @param target The value to find.
 * @return The index of the first occurrence of the target, or -1 if not found.
 */
int findFirst(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int firstPos = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
        if (nums[mid] == target) {
            firstPos = mid;
        }
    }
    return firstPos;
}

/**
 * @brief Finds the last occurrence of a target value in a sorted array.
 *
 * This function uses a modified binary search. When the target is found, it records
 * the index and continues searching in the right half of the array to find a later
 * occurrence.
 *
 * @param nums The sorted input vector.
 * @param target The value to find.
 * @return The index of the last occurrence of the target, or -1 if not found.
 */
int findLast(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int lastPos = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        if (nums[mid] == target) {
            lastPos = mid;
        }
    }
    return lastPos;
}

/**
 * @brief Finds the starting and ending position of a given target value.
 *
 * @param nums The sorted input vector.
 * @param target The value to find.
 * @return A vector of two integers representing the start and end indices.
 *         Returns {-1, -1} if the target is not found.
 */
std::vector<int> searchRange(const std::vector<int>& nums, int target) {
    int first = findFirst(nums, target);
    if (first == -1) {
        return {-1, -1};
    }
    int last = findLast(nums, target);
    return {first, last};
}

/**
 * @brief Main function to test the searchRange function.
 * @return 0 on successful execution.
 */
int main() {
    // Example 1
    std::vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    std::cout << "Input: {5,7,7,8,8,10}, target = 8" << std::endl;
    std::vector<int> result1 = searchRange(nums1, target1);
    std::cout << "Output: [" << result1[0] << ", " << result1[1] << "] (Expected: [3, 4])" << std::endl;
    std::cout << "--------------------" << std::endl;

    // Example 2
    int target2 = 6;
    std::cout << "Input: {5,7,7,8,8,10}, target = 6" << std::endl;
    std::vector<int> result2 = searchRange(nums1, target2);
    std::cout << "Output: [" << result2[0] << ", " << result2[1] << "] (Expected: [-1, -1])" << std::endl;
    std::cout << "--------------------" << std::endl;

    // Example 3
    std::vector<int> nums3 = {3,3,3,3,3};
    int target3 = 3;
    std::cout << "Input: {3,3,3,3,3}, target = 3" << std::endl;
    std::vector<int> result3 = searchRange(nums3, target3);
    std::cout << "Output: [" << result3[0] << ", " << result3[1] << "] (Expected: [0, 4])" << std::endl;

    return 0;
}
