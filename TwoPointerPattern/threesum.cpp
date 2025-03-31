/*

Working version

Problem Statement #
Given an array of unsorted numbers, find all unique triplets in it that add up to zero.

Example 1:

Input: [-3, 0, 1, 2, -1, 1, -2]
Output: [-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]
Explanation: There are four unique triplets whose sum is equal to zero.
Example 2:

Input: [-5, 2, -1, -2, 3]
Output: [[-5, 2, 3], [-2, -1, 3]]
Explanation: There are two unique triplets whose sum is equal to zero.



*/

/* Logic 

This problem follows the Two Pointers pattern and shares similarities with Pair with Target Sum. A couple of differences are that the input array is not sorted and instead of a pair we need to find triplets with a target sum of zero.

To follow a similar approach, first, we will sort the array and then iterate through it taking one number at a time. Let’s say during our iteration we are at number ‘X’, so we need to find ‘Y’ and ‘Z’ such that 
X+Y+Z==0
X+Y+Z==0. At this stage, our problem translates into finding a pair whose sum is equal to “−X” (as from the above equation 
Y+Z==−X
Y+Z==−X).

Another difference from Pair with Target Sum is that we need to find all the unique triplets. 
To handle this, we have to skip any duplicate number. Since we will be sorting the array, so all the duplicate numbers will be next to each other and are easier to skip.

*/

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;


void printtriplets(vector<array<int, 3>>& triplets) {

    // Print the triplets
   
    for(auto triplet : triplets) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
}   

void twosum(vector<int>& arr, int target, int left, int right, vector<array<int, 3>>& triplets) {
    while(left < right) {
        int sum = arr[left] + arr[right];
     
        if(sum == target) {

         
            triplets.push_back({-target, arr[left], arr[right]});
            left++;
            right--;
            // Skip duplicates
            while(left < right && arr[left] == arr[left-1]) {
                left++;
            }
            while(left < right && arr[right] == arr[right+1]) {
                right--;
            }
        } else if(sum < target) {
            left++;
        } else {
            right--;
        }
    }
}


int main() {
    
    vector<int> arr = {-3, 0, 1, 2, -1, 1, -2};
    vector<array<int, 3>> triplets;

    // Sort the array to make it easier to skip duplicates
    sort(arr.begin(), arr.end());

    cout << "Sorted array: ";
    for(int i=0;i<arr.size();i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int n = arr.size();
    // Iterate through the array
    for(int i=0;i<n;i++) {

        // Skip duplicate numbers
        if((i+1) <n && arr[i+1] == arr[i]) { 
            continue;
        }

        //Y+Z==−X : logic
        //consider arr[i] as X and find Y and Z such that Y+Z==−X
        int target = -arr[i];
        int left = i+1;
        int right = n-1;

        twosum(arr, target, left, right, triplets);

    }
 
    cout << "Unique triplets that add up to zero are: " << endl;
    printtriplets(triplets);

    return 1;

}