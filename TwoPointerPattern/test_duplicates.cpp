#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int low = 1;               // value range starts at 1, not index 0
    int high = nums.size()-1;  // nums.size()-1 == n, the max possible value

    while(low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;
        for(int n: nums) {
            if(n <= mid) count++;
        }
        if(count > mid) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    // Example 1: [1,3,4,2,2] -> 2
    {
        vector<int> nums = {1, 3, 4, 2, 2};
        int result = findDuplicate(nums);
        cout << "Test 1: got " << result << " (expected 2) -> " << (result == 2 ? "PASS" : "FAIL") << endl;
        assert(result == 2);
    }

    // Example 2: [3,1,3,4,2] -> 3
    {
        vector<int> nums = {3, 1, 3, 4, 2};
        int result = findDuplicate(nums);
        cout << "Test 2: got " << result << " (expected 3) -> " << (result == 3 ? "PASS" : "FAIL") << endl;
        assert(result == 3);
    }

    // Example 3: [3,3,3,3,3] -> 3
    {
        vector<int> nums = {3, 3, 3, 3, 3};
        int result = findDuplicate(nums);
        cout << "Test 3: got " << result << " (expected 3) -> " << (result == 3 ? "PASS" : "FAIL") << endl;
        assert(result == 3);
    }

    // Edge case: duplicate at 1 -> [1,1]
    {
        vector<int> nums = {1, 1};
        int result = findDuplicate(nums);
        cout << "Test 4 (edge n=1, dup=1): got " << result << " (expected 1) -> " << (result == 1 ? "PASS" : "FAIL") << endl;
        assert(result == 1);
    }

    // Edge case: duplicate at end -> [1,2,3,4,4]
    {
        vector<int> nums = {1, 2, 3, 4, 4};
        int result = findDuplicate(nums);
        cout << "Test 5 (dup=4): got " << result << " (expected 4) -> " << (result == 4 ? "PASS" : "FAIL") << endl;
        assert(result == 4);
    }

    cout << "\nAll tests passed!" << endl;
    return 0;
}
