/*

Remove Duplicates

Problem Statement #
Given an array of sorted numbers, remove all duplicates from it. 
You should not use any extra space; after removing the duplicates in-place return the new length of the array.

Example 1:

Input: [2, 3, 3, 3, 6, 9, 9]
Output: 4
Explanation: The first four elements after removing the duplicates will be [2, 3, 6, 9].
Example 2:

Input: [2, 2, 2, 11]
Output: 2
Explanation: The first two elements after removing the duplicates will be [2, 11].

*/

#include <iostream>
#include <vector>

using namespace std;

int remove_duplicates(vector<int>& v) {

    int result = 0;
    if(v.size() < 1) {
        return 0;
    }

    // two pointer approach to parse the array. 
    // use the 2 pointers at the beginning because the array is sorted and our intention is to remove similiar elements. 
    // in case a find pair problem we can use pointers at start and beginning together. here its recommended to proceed with start itself. 

    int start = 0;
    int end = start+1;
    int size = v.size();
    bool duplicatefound = false;

    while (end <= size)
    {
       if(v[start] != v[end]) {

        if(duplicatefound) {
            v[++start] = v[end];
            duplicatefound = false;
        }

        start++;end++;

       } else {

            duplicatefound = true;
            end++;

       }

    }
    
    result = start;



    return result;
}

int main() {

    vector<int> input {2, 3, 3, 3, 6, 9, 9};

    cout << "\n Result : " << remove_duplicates(input) << endl;


 
}

