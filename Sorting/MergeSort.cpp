/*
    Merge Sort Algorithm

    Problem Statement:
    Given an array of integers, sort the array in ascending order using the
    Merge Sort algorithm.

    Algorithm Description:
    Merge Sort is a divide-and-conquer algorithm. It works as follows:
    1. Divide: The unsorted list is divided into n sublists, each containing one element
       (a list of one element is considered sorted).
    2. Conquer: Repeatedly merge sublists to produce new sorted sublists until there is
       only one sublist remaining. This will be the sorted list.

    The `merge()` function is key to this process; it merges two sorted subarrays
    into one sorted array.

    Time Complexity: O(n log n) in all cases (worst, average, and best).
    Space Complexity: O(n) due to the temporary arrays used for merging.
*/

#include <iostream>
#include <vector>

/**
 * @brief Merges two sorted subarrays into a single sorted subarray.
 *
 * The two subarrays are arr[left..mid] and arr[mid+1..right].
 *
 * @param arr The main vector which is being sorted.
 * @param left The starting index of the first subarray.
 * @param mid The ending index of the first subarray.
 * @param right The ending index of the second subarray.
 */
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors for the left and right subarrays
    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary vectors back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/**
 * @brief Sorts an array in ascending order using the Merge Sort algorithm.
 *
 * This function recursively divides the array into two halves, calls itself for the
 * two halves, and then merges the two sorted halves using the `merge` function.
 *
 * @param arr The vector of integers to be sorted (modified in-place).
 * @param left The starting index of the array segment to be sorted.
 * @param right The ending index of the array segment to be sorted.
 */
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow for large left and h
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
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
 * @brief Main function to test the Merge Sort implementation.
 * @return 0 on successful execution.
 */
int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    std::cout << "Given array is: ";
    printArray(arr);

    mergeSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array is: ";
    printArray(arr);
    return 0;
}
