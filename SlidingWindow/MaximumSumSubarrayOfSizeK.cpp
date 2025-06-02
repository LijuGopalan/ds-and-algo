

 /* Program with sliding window pattern */

/*

    Maximum Sum Subarray of Size K
    Given an array of positive numbers and a positive number ‘k’, find the maximum sum of any contiguous subarray of size ‘k’.

    Example 1:

    Input: [2, 1, 5, 1, 3, 2], k=3 
    Output: 9
    Explanation: Subarray with maximum sum is [5, 1, 3].

    Example 2:

    Input: [2, 3, 4, 1, 5], k=2 
    Output: 7
    Explanation: Subarray with maximum sum is [3, 4].

*/

#include <iostream>
#include <vector>
using namespace std;


// Function to find the maximum sum of a subarray of size k
// using the sliding window technique   
// Time Complexity: O(n)
// Space Complexity: O(1)
int maxSumSubarrayOfSizeK(const vector<int>& input, int k) {
    int n = input.size();
    int sum = 0;
    int result = 0;
    int start = 0;

    for(int end = 0; end < n; end++) {
        sum += input[end];

        // When we have added k elements, we can start calculating the maximum
        if(end >= k - 1) {
            result = max(sum, result);
            sum -= input[start];
            start++;
        }
    }

    return result;
}



int main() {

    //input
    vector<int> input {2, 1, 5, 1, 3, 2};
    int k = 3;

    // Function call to find the maximum sum of a subarray of size k
    int result = maxSumSubarrayOfSizeK(input, k);

    cout << " result : " << result << endl;
}
