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
 
    int size = v.size();
    if(size < 1) {
        return 0;
    }

    //logic
    // 2 pointer approach
    // compare next 2 elements in a parse. 
    // start and end side by side . increment if start less than end . 
    // in case start >= end, ensure start stays and increment until end find the next qualified element.
    int start = 0;
    int end = 1;

    while (end < size)
    {
        if(v[start] < v[end]) {
            start++;

            // replace only if end is far from start due to any duplicate in between
            if(end-start > 1) {
                v[start] = v[end];
            }

        } 
        
        end++;
    }

    cout << " \n New Array " << endl;
    for(int x: v) {
        cout << x << " ";
    }
    
    return (start+1);
     
}

int main() {

    vector<int> input {2, 3, 3, 3, 6, 9, 9};
    int result = remove_duplicates(input);

    input.clear();
    input = {2, 2, 2, 11};
    result = remove_duplicates(input);


    cout << "\n Result : " << result << endl;

   
 
}

