/* 

A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

*/


/* Logic 

We have to solve this question with O(logn) time. Let's solve this question with binary search.

> Calculate middle index.

In the next step, we have to move a left or a right pointer. The description says "an element is always considered to be strictly greater than a neighbor that is outside the array."

In other words, if a number at middle + 1 index is less than a number at middle index, we have one of peaks on the left side of middle index, so move the right pointer to middle. Middle pointer itself may be one of peaks.

On the other hand, middle + 1 is greater than middle, we should move left pointer to middle + 1.

Why + 1 for only left?
Because middle + 1 is greater than middle. That means middle is definitely not one of peaks. Just in case for right pointer, middle is greater than middle + 1, that means there is a possibility that middle is one of peaks.

That's why we move right to middle and move left to middle + 1.

In this case, move left pointer to middle + 1.


*/


#include <iostream>
#include <vector>
using namespace std;
 
int findPeakElement(vector<int>& nums) {

    int n = nums.size();

    if(n<1) {
        return 0;
    }

    int left = 0;
    int right = n;

    while(left < right) {
        int mid = (left+right)/2;

        if(nums[mid+1] < nums[mid]) {
            right = mid;
        } else {
            left = mid+1;
        }
    }

      
    return left;

}
 

// To execute C++, please define "int main()"
int main() {

  vector<int> nums = {1,2,1,3,5,6,4};

  cout << endl << " result " << findPeakElement(nums);
  
}
