/*

        Given an array containing 0s and 1s, if you are allowed to replace no more than ‘k’ 0s with 1s, find the length of the longest contiguous subarray having all 1s.

        Example 1:

        Input: Array=[0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1], k=2
        Output: 6
        Explanation: Replace the '0' at index 5 and 8 to have the longest contiguous subarray of 1s having length 6.
        Example 2:

        Input: Array=[0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1], k=3
        Output: 9
        Explanation: Replace the '0' at index 6, 9, and 10 to have the longest contiguous subarray of 1s having length 9.


*/

#include<iostream>
#include<vector>
using namespace std;

int get_max_length_subarray_with_1(vector<int>& v, int& k) {


    //0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1
    //2
    //count 0
    //end 4

 
    int result = 0;

    if(v.size() < 1 || k < 1) {
        return result;
    }

    int start = 0;
    int end = 0;
    int size = v.size();

    int zerocount = 0;

    while (end <= size)
    { 

       //increment zero count as soon as a zero is found. 
       if(v[end] == 0) {
         zerocount++;
       }

       //if we made zero count more than k, that means we found more than k zeors. Time to calculate the length and reset the start to start +1
       // while incrementing start ensure to check whether its zero . if its zero , reduce the zero count too.
       if(zerocount > k) {

            result = max(result, (end-start));
            
            if(v[start] == 0) {
                zerocount--;
            }

            start++;
       }

       end++;

    }
      
    return result ;


}

int main() {

    vector<int> input {0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1};
    int k = 2;

    cout << endl << "result : " << get_max_length_subarray_with_1(input,k); 


    input.clear();
    input = { 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1};
    k = 3;
    cout << endl << "result : " << get_max_length_subarray_with_1(input,k); 


    return 1;
}