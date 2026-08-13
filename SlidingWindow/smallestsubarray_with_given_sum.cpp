/*

Problem Statement #
Given an array of positive numbers and a positive number ‘S’, find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. Return 0, if no such subarray exists.

Example 1:

Input: [2, 1, 5, 2, 3, 2], S=7 
Output: 2
Explanation: The smallest subarray with a sum great than or equal to '7' is [5, 2].
Example 2:

Input: [2, 1, 5, 2, 8], S=7 
Output: 1
Explanation: The smallest subarray with a sum greater than or equal to '7' is [8].
Example 3:

Input: [3, 4, 1, 1, 6], S=8 
Output: 3
Explanation: Smallest subarrays with a sum greater than or equal to '8' are [3, 4, 1] or [1, 1, 6].


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class SmallestSubarrayWithGivenSum {

    public:

        static int findMinSubArray(const vector<int>& arr, int sum) {

            int windowsum = 0;
            int begin = 0;

            int result = INT_MAX;
        
            for(int start =0; start < arr.size(); start++) {

                windowsum += arr[start];

                while(windowsum >= sum) {

                    result = min(result, (start-begin)+1);
                    windowsum -= arr[begin];
                    begin++;

                }
                
            }

            return (result == INT_MAX) ? 0 : result;

        }


};


int main() {

    vector<int> input {2, 1, 5, 2, 3, 2};
    int S = 7;

    int result = SmallestSubarrayWithGivenSum::findMinSubArray(input, S);
    cout << "Smallest subarray length: " << result << endl;
    


}