/*
    Binary Search

    Problem Statement:
    Given a sorted array of integers `arr` and an integer `target`, write a function
    to search for `target` in `arr`. If `target` exists, then return its index.
    Otherwise, return -1.

    You must write an algorithm with O(log n) runtime complexity.
*/

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Searches for a value in a sorted array using a recursive binary search.
 *
 * @param arr The sorted vector of integers to search in.
 * @param l The starting index of the search range.
 * @param r The ending index of the search range.
 * @param x The target value to search for.
 * @return The index of the target value if found; otherwise, -1.
 */
int binarySearchRecursive(const std::vector<int>& arr, int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle itself
        if (arr[mid] == x) {
            return mid;
        }

        // If element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > x) {
            return binarySearchRecursive(arr, l, mid - 1, x);
        }

        // Else the element can only be present in right subarray
        return binarySearchRecursive(arr, mid + 1, r, x);
    }

    // We reach here when element is not present in array
    return -1;
}

/**
 * @brief Searches for a value in a sorted array using an iterative binary search.
 *
 * This version is often preferred to the recursive one to avoid potential stack
 * overflow errors with very large arrays.
 *
 * @param arr The sorted vector of integers to search in.
 * @param x The target value to search for.
 * @return The index of the target value if found; otherwise, -1.
 */
int binarySearchIterative(const std::vector<int>& arr, int x) {
    int l = 0;
    int r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

/**
 * @brief Main function to test the binary search implementations.
 * @return 0 on successful execution.
 */
int main() {
    std::vector<int> arr = {2, 3, 4, 10, 40};
    int x_found = 10;
    int x_not_found = 5;

    std::cout << "Array: {2, 3, 4, 10, 40}" << std::endl;
    std::cout << "Searching for " << x_found << "..." << std::endl;

    // Test Recursive Version
    int result_rec_found = binarySearchRecursive(arr, 0, arr.size() - 1, x_found);
    if (result_rec_found != -1) {
        std::cout << "Recursive: Element found at index " << result_rec_found << std::endl;
    } else {
        std::cout << "Recursive: Element not found" << std::endl;
    }

    // Test Iterative Version
    int result_iter_found = binarySearchIterative(arr, x_found);
    if (result_iter_found != -1) {
        std::cout << "Iterative: Element found at index " << result_iter_found << std::endl;
    } else {
        std::cout << "Iterative: Element not found" << std::endl;
    }

    std::cout << "\nSearching for " << x_not_found << "..." << std::endl;

    // Test Recursive Version
    int result_rec_not_found = binarySearchRecursive(arr, 0, arr.size() - 1, x_not_found);
    if (result_rec_not_found != -1) {
        std::cout << "Recursive: Element found at index " << result_rec_not_found << std::endl;
    } else {
        std::cout << "Recursive: Element not found" << std::endl;
    }

    // Test Iterative Version
    int result_iter_not_found = binarySearchIterative(arr, x_not_found);
    if (result_iter_not_found != -1) {
        std::cout << "Iterative: Element found at index " << result_iter_not_found << std::endl;
    } else {
        std::cout << "Iterative: Element not found" << std::endl;
    }

    return 0;
}
