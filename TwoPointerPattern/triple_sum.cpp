
/*

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

#include <iostream>
#include <set>
#include <vector>
#include <array>
using namespace std;


void sort_array_to_set(vector<int>& a, set<int>& s) {
    for (int i = 0; i < a.size(); i++) {
        s.insert(a[i]);
    }

    cout << "Set: " << endl;
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    //-3 -2 -1 0 1 2
}


int main() {

    std::cout << " Triplet Sum to Zero " << std::endl;

    vector<int> arr = {-3, 0, 1, 2, -1, 1, -2};
    
    set<int> s;
    sort_array_to_set(arr, s);

    //set has the elements in sorted order now. 
    //use the set to find the triplets.
    //set sorted the data and removed the duplicates. 

    vector<array<int, 3>> triplets;

    set<int>::iterator itb = s.begin();
    int size = s.size();
    
    while (size > 0)
    {
        set<int>::iterator ite = s.end();

        while (itb != ite)
        {
            int sum = *itb + *ite;
            int target = -sum;
            if(s.find(target) != s.end() && s.find(target) > itb && s.find(target) < ite) {
                array<int, 3> triplet = {*itb, target, *ite};
                triplets.push_back(triplet);
            }
            ite--;
        }

        itb++;size--;
    
    }

    cout << "Triplets: " << endl;
    for (int i = 0; i < triplets.size(); i++) {
        cout << triplets[i][0] << " " << triplets[i][1] << " " << triplets[i][2] << endl;
    }
    
    return 0;
}