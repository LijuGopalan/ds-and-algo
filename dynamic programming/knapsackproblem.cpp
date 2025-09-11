/*
    0/1 Knapsack Problem

    Problem Statement:
    Given two integer arrays to represent weights and profits of ‘N’ items, we need to find
    a subset of these items which will give us maximum profit such that their cumulative
    weight is not more than a given number ‘C’. Each item can only be selected once.

    Example:
    Items: { Apple, Orange, Banana, Melon }
    Weights: { 2, 3, 1, 4 }
    Profits: { 4, 5, 3, 7 }
    Knapsack capacity: 5
    Output: 10 (Banana + Melon)
*/

#include <iostream>
#include <vector>
#include <algorithm>

// --- 1. Simple Recursive Solution ---
/**
 * @brief Solves the 0/1 Knapsack problem using a simple recursive approach.
 *
 * This function decides for each item whether to include it in the knapsack or not,
 * leading to two recursive calls for each item. This creates a large number of
 * overlapping subproblems, making it inefficient.
 * Time Complexity: O(2^n)
 * Space Complexity: O(n) for the recursion stack.
 *
 * @param profits Vector of profits for each item.
 * @param weights Vector of weights for each item.
 * @param capacity The maximum capacity of the knapsack.
 * @param currentIndex The index of the item currently being considered.
 * @return The maximum profit that can be obtained.
 */
int knapsackRecursive(const std::vector<int>& profits, const std::vector<int>& weights, int capacity, int currentIndex) {
    if (capacity <= 0 || currentIndex >= profits.size()) {
        return 0;
    }

    // Case 1: Include the item at currentIndex if it fits
    int profit1 = 0;
    if (weights[currentIndex] <= capacity) {
        profit1 = profits[currentIndex] + knapsackRecursive(profits, weights, capacity - weights[currentIndex], currentIndex + 1);
    }

    // Case 2: Exclude the item at currentIndex
    int profit2 = knapsackRecursive(profits, weights, capacity, currentIndex + 1);

    return std::max(profit1, profit2);
}

// --- 2. Top-Down DP (Memoization) ---
int knapsackTopDownHelper(std::vector<std::vector<int>>& dp, const std::vector<int>& profits, const std::vector<int>& weights, int capacity, int currentIndex) {
    if (capacity <= 0 || currentIndex >= profits.size()) {
        return 0;
    }

    // If we have already solved this subproblem, return the result
    if (dp[currentIndex][capacity] != -1) {
        return dp[currentIndex][capacity];
    }

    int profit1 = 0;
    if (weights[currentIndex] <= capacity) {
        profit1 = profits[currentIndex] + knapsackTopDownHelper(dp, profits, weights, capacity - weights[currentIndex], currentIndex + 1);
    }
    int profit2 = knapsackTopDownHelper(dp, profits, weights, capacity, currentIndex + 1);

    dp[currentIndex][capacity] = std::max(profit1, profit2);
    return dp[currentIndex][capacity];
}

/**
 * @brief Solves the 0/1 Knapsack problem using Top-Down Dynamic Programming (Memoization).
 *
 * This approach is a recursive solution that stores the results of solved subproblems
 * in a 2D array (memoization table) to avoid redundant computations.
 * Time Complexity: O(N * C) where N is the number of items and C is the capacity.
 * Space Complexity: O(N * C) for the memoization table + O(N) for recursion stack.
 *
 * @param profits Vector of profits.
 * @param weights Vector of weights.
 * @param capacity Knapsack capacity.
 * @return Maximum profit.
 */
int knapsackTopDown(const std::vector<int>& profits, const std::vector<int>& weights, int capacity) {
    std::vector<std::vector<int>> dp(profits.size(), std::vector<int>(capacity + 1, -1));
    return knapsackTopDownHelper(dp, profits, weights, capacity, 0);
}

// --- 3. Bottom-Up DP (Tabulation) ---
/**
 * @brief Solves the 0/1 Knapsack problem using Bottom-Up Dynamic Programming (Tabulation).
 *
 * This approach builds the solution iteratively. It uses a 2D DP table where
 * `dp[i][c]` represents the maximum profit for capacity `c` using the first `i` items.
 * Time Complexity: O(N * C)
 * Space Complexity: O(N * C)
 *
 * @param profits Vector of profits.
 * @param weights Vector of weights.
 * @param capacity Knapsack capacity.
 * @return Maximum profit.
 */
int knapsackBottomUp(const std::vector<int>& profits, const std::vector<int>& weights, int capacity) {
    int n = profits.size();
    if (capacity <= 0 || n == 0) {
        return 0;
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(capacity + 1, 0));

    // Populate the capacity column for the first item
    for (int c = 1; c <= capacity; ++c) {
        if (weights[0] <= c) {
            dp[0][c] = profits[0];
        }
    }

    // Process subproblems for all items
    for (int i = 1; i < n; ++i) {
        for (int c = 1; c <= capacity; ++c) {
            int profit1 = 0;
            // Include the item if it fits
            if (weights[i] <= c) {
                profit1 = profits[i] + dp[i - 1][c - weights[i]];
            }
            // Exclude the item
            int profit2 = dp[i - 1][c];
            dp[i][c] = std::max(profit1, profit2);
        }
    }
    return dp[n - 1][capacity];
}

/**
 * @brief Main function to demonstrate Knapsack problem solutions.
 * @return 0 on successful execution.
 */
int main() {
    std::vector<int> profits = {4, 5, 3, 7};
    std::vector<int> weights = {2, 3, 1, 4};
    int capacity = 5;

    std::cout << "Knapsack problem with capacity " << capacity << std::endl;
    std::cout << "Expected max profit: 10" << std::endl;
    std::cout << "1. Recursive Solution:    " << knapsackRecursive(profits, weights, capacity, 0) << std::endl;
    std::cout << "2. Top-Down DP Solution:  " << knapsackTopDown(profits, weights, capacity) << std::endl;
    std::cout << "3. Bottom-Up DP Solution: " << knapsackBottomUp(profits, weights, capacity) << std::endl;

    return 0;
}