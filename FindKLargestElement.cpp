
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
 
class Solution
{
    public:


        //Function to return k largest elements from an array.
        // Using the priotity queue data structure and using max heap property.
        // pushing all integers to priority queue and poping the required k elements 
        // complexity of this approach is O(n+k)
        vector<int> kLargest(int arr[], int n, int k)
        {
            priority_queue<int> q;
            vector<int> r;
            
            for(int j=0;j<n;j++) {
                q.push(arr[j]);
            }
            
            for(int i=0;i<k;i++) {
                r.push_back(q.top());
                q.pop();
            }
            
            return r;
        }

        
};


int main() {

    cout << " A program to return k largest elements from an array. " << endl;
    Solution obj;

    int n[] = {12,5,787,1,23};
    int k =2;

    vector<int> r = obj.kLargest(n,5,k);

    if( r.size() > 0) {

        for( int t: r) {
            cout << t << " ";
        }

    }


}
