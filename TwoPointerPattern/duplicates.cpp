/*

Find the Duplicate Number 
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2

Example 2:

Input: nums = [3,1,3,4,2]
Output: 3

Example 3:

Input: nums = [3,3,3,3,3]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?


*/

/* Logic without using any extra space  

This solution is based on binary search.

At first the search space is numbers between 1 to n. Each time I select a number mid (which is the one in the middle) and count all the numbers equal to or less than mid. 
Then if the count is more than mid, the search space will be [1 mid] otherwise [mid+1 n]. I do this until search space is only one number.

Let's say n=10 and I select mid=5. Then I count all the numbers in the array which are less than equal mid. If the there are more than 5 numbers that are less than 5, 
then by Pigeonhole Principle (https://en.wikipedia.org/wiki/Pigeonhole_principle) one of them has occurred more than once. 
So I shrink the search space from [1 10] to [1 5]. Otherwise the duplicate number is in the second half so for the next step the search space would be [6 10].


*/

// O(nlog(n)) : time complexity
// O(1) : space complexity


#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {

    int low = 0;
    int high = nums.size()-1;

    while(low < high ) {

        int mid = low+(high-low)/2;
        int count = 0;

        for(int n: nums) {
            if(n <= mid) {  
                count++;
            }
        }

        if(count > mid) {
            high = mid;
        } else {
            low = mid+1;
        }

    }
    return low;
}

int main() {

    vector<int> nums = {1, 3, 4, 2, 2};
    int duplicate = findDuplicate(nums);
    cout << "The duplicate number is: " << duplicate << endl;

    return 0;
}