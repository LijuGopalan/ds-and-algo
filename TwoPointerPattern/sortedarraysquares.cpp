/*
    Squares of a Sorted Array

    Problem Statement:
    Given a sorted array, create a new array containing squares of all the numbers
    of the input array in sorted order.

    Example 1:
    Input: [-2, -1, 0, 2, 3]
    Output: [0, 1, 4, 4, 9]

    Example 2:
    Input: [-3, -1, 0, 1, 2]
    Output: [0, 1, 1, 4, 9]
*/

#include <iostream>
#include <vector>
#include <algorithm> // For std::abs if needed

/**
 * @brief Prints the elements of a vector to the console.
 * @param arr The vector to be printed.
 */
void printArray(const std::vector<int>& arr) {
    std::cout << "[";
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i == arr.size() - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;
}

/**
 * @brief Creates a new array containing the squares of elements from a sorted
 *        input array, in sorted order.
 *
 * This function uses a two-pointer approach to build the result array efficiently
 * in O(n) time. Since the input array is sorted, the largest squares will be at
 * the ends (due to negative numbers becoming positive). Pointers `left` and `right`
 * start at the two ends of the input array. Their squares are compared, and the
 * larger square is placed at the end of the `result` array.
 *
 * @param arr A constant reference to the sorted input vector.
 * @return A new vector containing the squared elements in non-decreasing order.
 */
std::vector<int> makeSquares(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> squares(n);
    int highestSquareIdx = n - 1;
    int left = 0, right = n - 1;

    while (left <= right) {
        int leftSquare = arr[left] * arr[left];
        int rightSquare = arr[right] * arr[right];
        if (leftSquare > rightSquare) {
            squares[highestSquareIdx] = leftSquare;
            left++;
        } else {
            squares[highestSquareIdx] = rightSquare;
            right--;
        }
        highestSquareIdx--; // Move to the next position in the result array
    }
    return squares;
}

/**
 * @brief Main function to test the makeSquares function.
 * @return 0 on successful execution.
 */
int main() {
    // Example 1
    std::vector<int> input1 = {-2, -1, 0, 2, 3};
    std::cout << "Input: ";
    printArray(input1);
    std::vector<int> result1 = makeSquares(input1);
    std::cout << "Output: ";
    printArray(result1); // Expected: [0, 1, 4, 4, 9]
    std::cout << "--------------------" << std::endl;

    // Example 2
    std::vector<int> input2 = {-3, -1, 0, 1, 2};
    std::cout << "Input: ";
    printArray(input2);
    std::vector<int> result2 = makeSquares(input2);
    std::cout << "Output: ";
    printArray(result2); // Expected: [0, 1, 1, 4, 9]
    std::cout << "--------------------" << std::endl;

    return 0;
}