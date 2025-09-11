/*
    Quick Sort Algorithm

    Problem Statement:
    Given an array of integers, sort the array in ascending order using the
    Quick Sort algorithm.

    Algorithm Description:
    Quick Sort is a highly efficient, divide-and-conquer sorting algorithm.
    1. Pick an element from the array, which is called the pivot.
    2. Partitioning: Reorder the array so that all elements with values less than the pivot
       come before the pivot, while all elements with values greater than the pivot
       come after it. After this partitioning, the pivot is in its final sorted position.
    3. Recursion: Recursively apply the above steps to the sub-array of elements with
       smaller values and separately to the sub-array of elements with greater values.

    This implementation uses the Lomuto partition scheme, which chooses the last
    element as the pivot.

    Time Complexity:
    - Best and Average Case: O(n log n)
    - Worst Case: O(n^2) (occurs when the pivot selection is poor, e.g., on an
      already sorted array).
    Space Complexity: O(log n) for the recursion stack space.
*/

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Partitions the array around a pivot element using the Lomuto scheme.
 *
 * This function takes the last element as a pivot, places the pivot element at its
 * correct position in the sorted array, and places all smaller elements to the left
 * of the pivot and all greater elements to the right of the pivot.
 *
 * @param arr The vector of integers to be partitioned.
 * @param low The starting index of the partition.
 * @param high The ending index of the partition.
 * @return The index of the pivot element after partitioning.
 */
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Pivot is the last element
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // Increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/**
 * @brief Sorts an array in ascending order using the Quick Sort algorithm.
 *
 * This function implements the recursive, divide-and-conquer logic of Quick Sort.
 *
 * @param arr The vector of integers to be sorted (modified in-place).
 * @param low The starting index of the array segment to be sorted.
 * @param high The ending index of the array segment to be sorted.
 */
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is the partitioning index, arr[pi] is now at the right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/**
 * @brief A utility function to print a vector.
 * @param arr The vector to be printed.
 */
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Main function to test the Quick Sort implementation.
 * @return 0 on successful execution.
 */
int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    std::cout << "Given array is: ";
    printArray(arr);

    quickSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array is: ";
    printArray(arr);
    return 0;
}
