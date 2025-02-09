
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
 
 -3 -2 -1 0 1 2 

*/

#include <iostream>
#include <set>
#include <vector>
#include <array>
#include <map>
#include <map>

using namespace std;

void sort_array_and_store_in_map(vector<int>& a, multimap<int,bool>& m) {
    for (int i = 0; i < a.size(); i++) {
        m.insert({a[i],false});
        //m[a[i]] = false;
    } 
}

void find_all_unique_triplets(vector<int>& arr, vector<array<int, 3>>& triplets) {

    multimap<int,bool> m;

    sort_array_and_store_in_map(arr, m); 
 
    multimap<int,bool>::iterator itra = m.begin();

    multimap<int,bool>::iterator itr;
    while (itra != m.end())
    {
        multimap<int,bool>::iterator itrb = m.end();
        while (itrb != m.begin())
        {
            int sum = itrb->first + itra->first;
            
            itr = m.find(-sum);            

            if(itr != m.end() && itr != itrb && itr != itra) {

                if( itra->second == false || itrb->second == false || itr->second == false ) {
                    array<int, 3> triplet = {itra->first,itr->first,itrb->first};
                    triplets.push_back(triplet);
                    itra->second = true;
                    itrb->second = true;
                    itr->second = true;
                }
                
            } 
            --itrb;
        }

        itra++;

    }

}


int main() {

    std::cout << " Triplet Sum to Zero " << std::endl;

    vector<int> arr = {-3, 0, 1, 2, -1, 1, -2};
    vector<array<int, 3>> triplets;
    find_all_unique_triplets(arr,triplets);
    
    cout << "Triplets: " << endl;
    for (int i = 0; i < triplets.size(); i++) {
        cout << triplets[i][0] << " " << triplets[i][1] << " " << triplets[i][2] << endl;
    }


    arr.clear();
    arr = {-5, 2, -1, -2, 3};
    triplets.clear();
    find_all_unique_triplets(arr,triplets);
    
    cout << "Triplets: " << endl;
    for ( int i = 0; i < triplets.size(); i++) {
        cout << triplets[i][0] << " " << triplets[i][1] << " " << triplets[i][2] << endl;
    }
    
    return 1;
}


