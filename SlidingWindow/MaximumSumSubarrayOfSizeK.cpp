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

int main() {


    /* Program with sliding window pattern */

    //input
    vector<int> input {2, 1, 5, 1, 3, 2};
    int k = 3;

    // variable declaration
    int n = input.size();
    int sum = 0;
    int result = 0;

    // start pointer
    int start = 0;

    for(int end=0; end<n ; end++) {

        
        sum += input[end];
 
        //loop until first k set of elements addition. 
        if(end >= k-1) {

            result = max(sum, result);
            sum -= input[start];
            start++;
            
        }

    }

    cout << " result : " << result << endl;
}
