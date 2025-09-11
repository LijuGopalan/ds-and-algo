/*

Remove Duplicates

Problem Statement #
Given an array of sorted numbers, remove all duplicates from it. 
You should not use any extra space; after removing the duplicates in-place return the new length of the array.

Example 1:

Input: [2, 3, 3, 3, 6, 9, 9]
Output: 4
Explanation: The first four elements after removing the duplicates will be [2, 3, 6, 9].
Example 2:

Input: [2, 2, 2, 11]
Output: 2
Explanation: The first two elements after removing the duplicates will be [2, 11].

*/

#include <iostream>
#include <vector>

/**
 * @brief Prints the first `length` elements of a vector to the console.
 * @param arr The vector to be printed.
 * @param length The number of elements from the start of the vector to print.
 */
void printArray(const std::vector<int>& arr, int length) {
    std::cout << "[";
    for (int i = 0; i < length; ++i) {
        std::cout << arr[i] << (i == length - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;
}

/**
 * @brief Removes duplicates from a sorted array in-place.
 *
 * This function uses a two-pointer approach. A "read" pointer `i` iterates through
 * the array, and a "write" pointer `nextUniqueIndex` tracks the position for the
 * next unique element. When a new unique element is found (arr[i] != arr[i - 1]),
 * it's placed at the `nextUniqueIndex` position.
 *
 * @param arr The sorted vector of integers, which will be modified in-place.
 * @return The new length of the array after removing duplicates.
 */
int removeDuplicates(std::vector<int>& arr) {
    if (arr.empty()) {
        return 0;
    }

    int nextUniqueIndex = 1; // Starts at the second position
    // Iterate through the array starting from the second element
    for (int i = 1; i < arr.size(); ++i) {
        // If the current element is different from the previous one, it's unique
        if (arr[i] != arr[i - 1]) {
            arr[nextUniqueIndex] = arr[i]; // Place it at the next unique position
            nextUniqueIndex++;
        }
    }

    return nextUniqueIndex;
}

/**
 * @brief Main function to test the removeDuplicates function.
 * @return 0 on successful execution.
 */
int main() {
    // Example 1
    std::vector<int> input1 = {2, 3, 3, 3, 6, 9, 9};
    std::cout << "Input: {2, 3, 3, 3, 6, 9, 9}" << std::endl;
    int newLength1 = removeDuplicates(input1);
    std::cout << "New length: " << newLength1 << std::endl;
    std::cout << "Array after removing duplicates: ";
    printArray(input1, newLength1);
    std::cout << "--------------------" << std::endl;

    // Example 2
    std::vector<int> input2 = {2, 2, 2, 11};
    std::cout << "Input: {2, 2, 2, 11}" << std::endl;
    int newLength2 = removeDuplicates(input2);
    std::cout << "New length: " << newLength2 << std::endl;
    std::cout << "Array after removing duplicates: ";
    printArray(input2, newLength2);
    std::cout << "--------------------" << std::endl;

    return 0;
}

