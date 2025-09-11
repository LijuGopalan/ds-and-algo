/*
    Dynamic Programming: Fibonacci Number Example

    This file demonstrates three different approaches to calculating the nth Fibonacci number,
    illustrating the concepts of simple recursion, top-down dynamic programming (memoization),
    and bottom-up dynamic programming (tabulation).

    The Fibonacci sequence is defined as:
    F(0) = 0, F(1) = 1
    F(n) = F(n-1) + F(n-2) for n > 1.
*/

#include <iostream>
#include <vector>

/**
 * @brief Calculates the nth Fibonacci number using simple recursion.
 *
 * This is a classic but inefficient approach. It has overlapping subproblems,
 * leading to an exponential time complexity.
 *
 * @param n The index in the Fibonacci sequence.
 * @return The nth Fibonacci number.
 */
int fibonacciRecursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

/**
 * @brief A helper for the top-down (memoization) approach.
 *
 * @param n The index in the Fibonacci sequence.
 * @param memo A vector used for memoization.
 * @return The nth Fibonacci number.
 */
int fibonacciTopDownHelper(int n, std::vector<int>& memo) {
    if (n <= 1) {
        return n;
    }
    // If the value has not been computed yet, compute and store it
    if (memo[n] == -1) {
        memo[n] = fibonacciTopDownHelper(n - 1, memo) + fibonacciTopDownHelper(n - 2, memo);
    }
    return memo[n];
}

/**
 * @brief Calculates the nth Fibonacci number using top-down DP (memoization).
 *
 * This approach uses recursion but stores the results of subproblems in a `memo`
 * array to avoid re-computation.
 *
 * @param n The index in the Fibonacci sequence.
 * @return The nth Fibonacci number.
 */
int fibonacciTopDown(int n) {
    if (n < 0) return -1; // Or throw an exception
    std::vector<int> memo(n + 1, -1);
    return fibonacciTopDownHelper(n, memo);
}

/**
 * @brief Calculates the nth Fibonacci number using bottom-up DP (tabulation).
 *
 * This approach avoids recursion by building the solution iteratively from the base
 * cases up to the desired value `n`.
 *
 * @param n The index in the Fibonacci sequence.
 * @return The nth Fibonacci number.
 */
int fibonacciBottomUp(int n) {
    if (n <= 1) {
        return n;
    }
    std::vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

/**
 * @brief Main function to demonstrate and compare Fibonacci implementations.
 * @return 0 on successful execution.
 */
int main() {
    int n = 10;
    std::cout << "Calculating the " << n << "th Fibonacci number:" << std::endl;

    std::cout << "1. Simple Recursive:    " << fibonacciRecursive(n) << std::endl;
    std::cout << "2. Top-Down DP (Memo):  " << fibonacciTopDown(n) << std::endl;
    std::cout << "3. Bottom-Up DP (Tab):  " << fibonacciBottomUp(n) << std::endl;

    return 0;
}
