
/*

Problem Statement:

Given an array of positive numbers and a positive number S, find the length of the smallest contiguous subarray whose sum is greater than or equal to S. 
If no such subarray exists, return 0.

Approach:
We can solve this problem efficiently using the sliding window technique. 
The idea is to maintain a window of elements that keeps track of the current sum. 
The window will grow and shrink dynamically based on whether the sum is greater than or equal to S


Input: [2, 1, 5, 2, 3, 2], S=7 
Output: 2
Explanation: The smallest subarray with a sum great than or equal to '7' is [5, 2].

Input: [2, 1, 5, 2, 8], S=7 
Output: 1
Explanation: The smallest subarray with a sum greater than or equal to '7' is [8].

*/


 /* Program with sliding window pattern */

#include <iostream>
#include <vector>
using namespace std;

int main() {

    //input
    vector<int> input {2, 1, 5, 2, 8};
    int sum = 7;

    //declaration
    int length = 0;
    int start = 0;
    int size = input.size();
    int s = 0;

    int result = -1;


    if(input.size() > 0 && sum > 0) {

        for(int end=0; end<size; end++) {

            s += input[end];
            if(s >= sum) {

                while (s>=sum && start <= end)
                {
                    length = (end-start)+1;

                    cout << endl << " debug " << length << endl;
                    if(result == -1) {
                        result = length;
                    }
                    result = min(length,result);
                    s -= input[start];
                    start++;
                } 
            }
        }

    }


    cout << endl << "the smallest contiguous subarray whose sum is greater than or equal to " << sum << " is : " << result;


}
