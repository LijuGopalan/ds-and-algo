/* Problem  #
Given an array of numbers and a number k, find the median of all the ‘k’ sized
sub-arrays of the array.

Example 1:
----------

Input: nums=[1, 2, -1, 3, 5], k = 2
Output: [1.5, 0.5, 1.0, 4.0]

[1, 2, -1, 3, 5] -> median is 1.5
[1, 2, -1, 3, 5] -> median is 0.5
[1, 2, -1, 3, 5] -> median is 1.0
[1, 2, -1, 3, 5] -> median is 4.0

Example 2:
----------

Input: nums=[1, 2, -1, 3, 5], k = 3
Output: [1.0, 2.0, 3.0]

[1, 2, -1, 3, 5] -> median is 1.0
[1, 2, -1, 3, 5] -> median is 2.0
[1, 2, -1, 3, 5] -> median is 3.0

*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class slindingwindowmedian {

private:
  int k;
  vector<int> nums;
  priority_queue<int> maxheap_left;
  priority_queue<int, vector<int>, greater<int>> minheap_right;

  void rebalance() {

    if (maxheap_left.size() > minheap_right.size() - 1) {
      minheap_right.push(maxheap_left.top());
      maxheap_left.pop();
    } else if (minheap_right.size() > maxheap_left.size()) {
      maxheap_left.push(minheap_right.top());
      minheap_right.pop();
    }
  }

public:
  double getMedian() {
    if (maxheap_left.size() == minheap_right.size()) {
      return (maxheap_left.top() + minheap_right.top()) / 2.0;
    } else {
      return maxheap_left.top();
    }
  }

  void insert(int number) {

    if (maxheap_left.empty() || number <= maxheap_left.top()) {
      maxheap_left.push(number);
    } else {
      minheap_right.push(number);
    }
  }

  void remove(int number) {

    if (number <= maxheap_left.top()) {
      maxheap_left.remove(number);
    } else {
      minheap_right.remove(number);
    }
  }
};

int main() { return 0; }
