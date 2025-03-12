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

void printarray(vector<int>& v) {
    for(auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int remove_duplicates(vector<int>& v) {
 
    //2, 3, 3, 3, 6, 9, 9

    int size = v.size();
    if(size == 0) return 0;

    int i =  1;
    int end = 1;
    for(;end<size;end++) {
        if(v[end] != v[end-1]) {
            v[i] = v[end];
            i++;
        }
    }

    return i;
}

int main() {

    vector<int> input {2, 3, 3, 3, 6, 9, 9};
    int result = remove_duplicates(input);

    cout << "\n Result : " << result << endl;
    printarray(input);

    input.clear();
    input = {2, 2, 2, 11};
    result = remove_duplicates(input);

    cout << "\n Result : " << result << endl;
    printarray(input);
 
}

