/*

Given a sorted array, create a new array containing squares of all the number of the input array in the sorted order.

Example 1:

Input: [-2, -1, 0, 2, 3]
Output: [0, 1, 4, 4, 9]
Example 2:

Input: [-3, -1, 0, 1, 2]
Output: [0 1 1 4 9]


*/

#include <iostream>
#include <vector>
using namespace std;

void printarray(vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    vector<int> arr = {-2, -1, 0, 2, 3};
    vector<int> result(arr.size());
    int size = arr.size();

    int left = 0;
    int right = size - 1;

    while(left <= right) {
        int leftSquare = arr[left] * arr[left];
        int rightSquare = arr[right] * arr[right];

        if(leftSquare > rightSquare) {
            result[right - left] = leftSquare;
            left++;
        } else {
            result[right - left] = rightSquare;
            right--;
        }
    }

    printarray(result);


    return 1;
}