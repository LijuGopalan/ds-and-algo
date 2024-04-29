
#include <vector>
#include <queue>
#include <iostream>
#include <set>


using namespace std;
 
class Solution
{
    public:


        //Function to return k largest elements from an array.
        // Using the priotity queue data structure and using max heap property.
        // pushing all integers to priority queue and poping the required k elements 
        // complexity of this approach is O(n*log n + k*log n)
        vector<int> kLargestUsingMaxHeap(int arr[], int n, int k)
        {
            priority_queue<int> q;
            vector<int> r;

            if(n < 1 || k < 1 || k > n) {
                return r;
            }
            
            for(int j=0;j<n;j++) {
                q.push(arr[j]);
            }
            
            for(int i=0;i<k;i++) {
                r.push_back(q.top());
                q.pop();
            }
            
            return r;
        }

        // algo using set data structure. 
        // using c++ multiset property. 
        // descenting order set. 
        // complexity is O(n*logn + k)
        vector<int> kLargestUsingSet(int arr[], int n, int k)
        {
            vector<int> result;

            if(n < 1 || k < 1 || k > n) {
                return result;
            }

            // set with ascenting order
            multiset<int, greater<int>> s;

            for(int j=0;j<n;j++) {
                s.insert(arr[j]);
            }

            // get the top K elements from set. 
            multiset<int, greater<int>>::iterator itr = s.begin();

            while (k >= 1 && itr != s.end())
            {
                result.push_back(*itr);
                k--; itr++;
            } 

            s.clear();

            return result; 

        } 
        
};


int main() {

    cout << " A program to return k largest elements from an array. " << endl;
    Solution obj;

    int n[] = {12,5,787,1,23,23};
    int k=3;

    vector<int> r = obj.kLargestUsingSet(n,6,k);

    if( r.size() > 0) {

        for( int t: r) {
            cout << t << " ";
        }

    }
}


