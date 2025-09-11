/*
    3Sum: Find all unique triplets that sum up to zero.

    Problem Statement:
    Given an array of unsorted numbers, find all unique triplets in it that add up to zero.

    Example 1:
    Input: [-3, 0, 1, 2, -1, 1, -2]
    Output: [[-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]]
    Explanation: There are four unique triplets whose sum is equal to zero.

    Example 2:
    Input: [-5, 2, -1, -2, 3]
    Output: [[-5, 2, 3], [-2, -1, 3]]
    Explanation: There are two unique triplets whose sum is equal to zero.
*/

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_set>

/**
 * @brief Finds all unique triplets that sum to zero using the Two Pointers technique.
 *
 * This is the classic and most efficient approach. The array is first sorted. Then, we iterate
 * through the array, fixing one number (`arr[i]`). For the rest of the array, we use two
 * pointers (left and right) to find a pair that sums up to `-arr[i]`.
 * Duplicates are skipped to ensure the uniqueness of the resulting triplets.
 *
 * @param arr The input vector of integers. The vector will be sorted in-place.
 * @return A vector of 3-element arrays, where each array is a unique triplet summing to zero.
 */
std::vector<std::array<int, 3>> searchTriplets(std::vector<int>& arr) {
    std::vector<std::array<int, 3>> triplets;
    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
        // Skip duplicate values for the first element of the triplet
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        int left = i + 1;
        int right = arr.size() - 1;
        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == 0) {
                triplets.push_back({arr[i], arr[left], arr[right]});
                left++;
                right--;
                // Skip duplicate values for the second and third elements
                while (left < right && arr[left] == arr[left - 1]) {
                    left++;
                }
                while (left < right && arr[right] == arr[right + 1]) {
                    right--;
                }
            } else if (sum < 0) {
                left++;
            } else { // sum > 0
                right--;
            }
        }
    }
    return triplets;
}

/**
 * @brief Finds all unique triplets that sum to zero using a Hash Set.
 *
 * This approach also sorts the array first to handle duplicates. It iterates through the
 * array, fixing one number (`arr[i]`). For the rest of the array, it uses a hash set
 * to find the third element `target = -arr[i] - arr[j]` in O(1) time on average.
 *
 * @param arr The input vector of integers. The vector will be sorted in-place.
 * @return A vector of 3-element arrays, where each array is a unique triplet summing to zero.
 */
std::vector<std::array<int, 3>> searchTripletsWithSet(std::vector<int>& arr) {
    std::vector<std::array<int, 3>> triplets;
    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
        // Skip duplicate values for the first element
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        std::unordered_set<int> seen;
        for (int j = i + 1; j < arr.size(); j++) {
            int target = -arr[i] - arr[j];
            if (seen.count(target)) {
                triplets.push_back({arr[i], arr[j], target});
                // Skip duplicates for the second element
                while (j + 1 < arr.size() && arr[j] == arr[j + 1]) {
                    j++;
                }
            }
            seen.insert(arr[j]);
        }
    }
    return triplets;
}

/**
 * @brief Helper function to print the resulting triplets.
 * @param triplets A vector of 3-element arrays to print.
 */
void printTriplets(const std::vector<std::array<int, 3>>& triplets) {
    for (const auto& triplet : triplets) {
        std::cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "] ";
    }
    std::cout << std::endl;
}

/**
 * @brief Main function to test the 3Sum solutions.
 *
 * @return 0 on successful execution.
 */
int main() {
    std::vector<int> input1 = {-3, 0, 1, 2, -1, 1, -2};
    std::vector<int> input2 = {-5, 2, -1, -2, 3};

    std::cout << "Input: {-3, 0, 1, 2, -1, 1, -2}" << std::endl;
    std::cout << "Two Pointers Result: ";
    auto result1 = searchTriplets(input1);
    printTriplets(result1);

    // Re-initialize for the second function as the vector is sorted in-place
    input1 = {-3, 0, 1, 2, -1, 1, -2};
    std::cout << "Hash Set Result:     ";
    auto result2 = searchTripletsWithSet(input1);
    printTriplets(result2);

    std::cout << "\n--------------------\n" << std::endl;

    std::cout << "Input: {-5, 2, -1, -2, 3}" << std::endl;
    std::cout << "Two Pointers Result: ";
    auto result3 = searchTriplets(input2);
    printTriplets(result3);

    // Re-initialize for the second function
    input2 = {-5, 2, -1, -2, 3};
    std::cout << "Hash Set Result:     ";
    auto result4 = searchTripletsWithSet(input2);
    printTriplets(result4);

    return 0;
}