
/*

Problem Statement #
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
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<array<int,3>> searchtripleteswthset(vector<int> arr) {
  vector<array<int,3>> triplets;
  sort(arr.begin(), arr.end());
  for (int i = 0; i < arr.size(); i++) {
    if (i > 0 && arr[i] == arr[i - 1]) {
      continue;
    }
    unordered_set<int> seen;
    for (int j = i + 1; j < arr.size(); j++) {
      int target = -arr[i] - arr[j];
      if (seen.find(target) != seen.end()) {
        triplets.push_back({arr[i], arr[j], target});
        while (j + 1 < arr.size() && arr[j] == arr[j + 1]) {
          j++;
        }
      }
      seen.insert(arr[j]);
    }
  }
  return triplets;
}

vector<array<int,3>> searchTriplets(vector<int> arr) {
  vector<array<int,3>> triplets;
  sort(arr.begin(), arr.end());
  for (int i = 0; i < arr.size(); i++) {
    if (i > 0 && arr[i] == arr[i - 1]) {
      continue;
    }
    int left = i + 1;
    int right = arr.size() - 1;
    while (left < right) {
      int sum = arr[i] + arr[left] + arr[right];
      if (sum == 0) {
        triplets.push_back({arr[i], arr[left], arr[right]});
        left++;
        right--;
        while (left < right && arr[left] == arr[left - 1]) {
          left++;
        }
        while (left < right && arr[right] == arr[right + 1]) {
          right--;
        }
      } else if (sum < 0) {
        left++;
      } else {
        right--;
      }
    }
  }
  return triplets;
}

int main() {
  

    vector<array<int,3>> result = searchTriplets({-3, 0, 1, 2, -1, 1, -2});
    for (auto vec : result) {
      cout << "[";
      for (auto num : vec) {
        cout << num << " ";
      }
      cout << "]";
    }


  return 0;
}