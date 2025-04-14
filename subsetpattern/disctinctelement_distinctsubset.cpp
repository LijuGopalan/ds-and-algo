/*

Problem Statement #
Given a set with distinct elements, find all of its distinct subsets.

Example 1:

Input: [1, 3]
Output: [], [1], [3], [1,3]
Example 2:

Input: [1, 5, 3]
Output: [], [1], [5], [3], [1,5], [1,3], [5,3], [1,5,3]

*/

/* logic

Given set: [1, 5, 3]

Start with an empty set: [[]]
Add the first number (1) to all the existing subsets to create new subsets: [[], [1]];
Add the second number (5) to all the existing subsets: [[], [1], [5], [1,5]];
Add the third number (3) to all the existing subsets: [[], [1], [5], [1,5], [3], [1,3], [5,3], [1,5,3]].

*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> get_distinct_subset(vector<int> nums) {

  vector<vector<int>> result;
 
  // assign an empty vector to result.
  result.push_back(vector<int>());

  //loop through every numbers in nums
  for(int n : nums) {

    int s = result.size();
    for(int i=0;i<s;i++) {

      vector<int> temp(result[i]);
      temp.push_back(n);
      result.push_back(temp);

    }

  }

  return result;
}

int main() {


  vector<vector<int>> r = get_distinct_subset(vector<int> { 1,5,3 });

  cout << endl << "subset" <<endl;

  for(vector<int> t : r) {

    for(int x: t) {
      cout<<x<<" ";
    }
    cout <<endl;

  }

  return 1;
}