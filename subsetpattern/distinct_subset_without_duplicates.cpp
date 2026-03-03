/*

Problem Statement
Given a set that may contain duplicate numbers, find all of its distinct
subsets.

Example 1:
  Input:  [1, 3, 3]
  Output: [], [1], [3], [1,3], [3,3], [1,3,3]

Example 2:
  Input:  [1, 5, 3, 3]
  Output: [], [1], [3], [5], [1,3], [1,5], [3,3], [3,5], [1,3,3], [1,3,5],
[3,3,5], [1,3,3,5]

Logic:
  Sort the input so that duplicates are adjacent.
  Use the same BFS/subset-expansion approach as the distinct-elements version,
  but when we encounter a duplicate number, we only add it to the subsets
  that were created in the *previous* iteration (not all existing subsets).
  This avoids re-creating subsets we already have.

  Given [1, 3, 3] (sorted):
    Start    : [[]]
    Add 1    : [[], [1]]                          startIndex=0, endIndex=1
    Add 3    : [[], [1], [3], [1,3]]              startIndex=0, endIndex=3
    Add 3(dup): only extend subsets added last     startIndex=2 (the [3],[1,3]
ones) : [[], [1], [3], [1,3], [3,3], [1,3,3]]

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> get_distinct_subsets_with_dupes(vector<int> nums) {

  // Sort so duplicates are adjacent
  sort(nums.begin(), nums.end());

  vector<vector<int>> result;
  result.push_back(vector<int>());

  for (int i = 0; i < nums.size(); i++) {

    int start_index = 0;
    int end_index = result.size() - 1;

    if (i > 0 && nums[i] == nums[i - 1]) {
      start_index = end_index + 1;
    }

    for (int j = start_index; j <= end_index; j++) {
      vector<int> new_set(result[j]);
      new_set.push_back(nums[i]);
      result.push_back(new_set);
    }
  }
  return result;
}

void printSubsets(const vector<vector<int>> &subsets) {
  cout << "All distinct subsets:" << endl;
  for (const vector<int> &subset : subsets) {
    cout << "[";
    for (int i = 0; i < (int)subset.size(); i++) {
      cout << subset[i];
      if (i < (int)subset.size() - 1)
        cout << ", ";
    }
    cout << "]" << endl;
  }
}

int main() {
  cout << "--- Input: [1, 3, 3] ---" << endl;
  vector<vector<int>> r1 = get_distinct_subsets_with_dupes({1, 3, 3});
  printSubsets(r1);

  cout << endl;

  cout << "--- Input: [1, 5, 3, 3] ---" << endl;
  vector<vector<int>> r2 = get_distinct_subsets_with_dupes({1, 5, 3, 3});
  printSubsets(r2);

  return 0;
}
