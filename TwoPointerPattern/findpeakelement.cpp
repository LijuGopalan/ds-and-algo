/*
    Find Peak Element

    A peak element is an element that is strictly greater than its neighbors.

    Given a 0-indexed integer array nums, find a peak element, and return its index.
    If the array contains multiple peaks, return the index to any of the peaks.

    You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always
    considered to be strictly greater than a neighbor that is outside the array.

    You must write an algorithm that runs in O(log n) time.

    Example 1:
    Input: nums = [1,2,3,1]
    Output: 2
    Explanation: 3 is a peak element and your function should return the index number 2.

    Example 2:
    Input: nums = [1,2,1,3,5,6,4]
    Output: 5
    Explanation: Your function can return either index number 1 where the peak element is 2,
    or index number 5 where the peak element is 6.
*/

/*
    Logic: Binary Search

    This problem can be solved efficiently using binary search. The key insight is that
    we can determine which half of the array must contain a peak by comparing the middle
    element `nums[mid]` with its right neighbor `nums[mid + 1]`.

    - If `nums[mid] > nums[mid + 1]`, it means we are on a downward slope. A peak must exist
      to the left of or at `mid`. So, we can discard the right half by setting `right = mid`.

    - If `nums[mid] < nums[mid + 1]`, it means we are on an upward slope. A peak must exist
      to the right of `mid`. So, we can discard the left half by setting `left = mid + 1`.

    This process continues until `left` and `right` converge, at which point they will both
    point to a peak element.
*/

#include <iostream>
#include <vector>

/**
 * @brief Finds a peak element in an array using binary search.
 *
 * A peak element is an element that is strictly greater than its neighbors.
 * This function implements a binary search to find any peak in O(log n) time.
 *
 * @param nums A constant reference to the input vector of integers.
 * @return The index of any peak element in the array. Returns -1 if the array is empty.
 */
int findPeakElement(const std::vector<int>& nums) {
    if (nums.empty()) {
        return -1;
    }

    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        // Compare mid with its right neighbor to decide which half has a peak
        if (nums[mid] > nums[mid + 1]) {
            // We are on a downward slope, so a peak is in the left half (including mid)
            right = mid;
        } else {
            // We are on an upward slope, so a peak is in the right half
            left = mid + 1;
        }
    }

    // When left == right, we have found a peak
    return left;
}

/**
 * @brief Main function to test the findPeakElement function.
 * @return 0 on successful execution.
 */
int main() {
    std::vector<int> nums1 = {1, 2, 3, 1};
    std::cout << "Input: {1, 2, 3, 1}" << std::endl;
    std::cout << "Peak element index: " << findPeakElement(nums1) << std::endl; // Expected: 2
    std::cout << "--------------------" << std::endl;

    std::vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};
    std::cout << "Input: {1, 2, 1, 3, 5, 6, 4}" << std::endl;
    std::cout << "Peak element index: " << findPeakElement(nums2) << std::endl; // Expected: 1 or 5
    std::cout << "--------------------" << std::endl;

    return 0;
}
