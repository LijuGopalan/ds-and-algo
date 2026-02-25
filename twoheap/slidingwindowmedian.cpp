#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class slidemedian {

  int k;
  vector<int> nums;
  priority_queue<int> maxheap;
  priority_queue<int, vector<int>, greater<int>> minheap;

public:
  void insert(int number) {

    if (maxheap.empty() || maxheap.top() >= number)
      maxheap.push(number);
    else
      minheap.push(number);

    if (maxheap.size() > minheap.size() + 1) {
      minheap.push(maxheap.top());
      maxheap.pop();
    } else if (minheap.size() > maxheap.size()) {
      maxheap.push(minheap.top());
      minheap.pop();
    }
  }

  void remove(int number) {

    if (number <= maxheap.top()) {

      // need to fix the erase problem
      maxheap.erase(maxheap.find(number));
    }

    else if (number > maxheap.top()) {

      // need to fix the remove problem
      minheap.remove(number);
    }
  }

  float getmedian() {

    if (maxheap.size() == minheap.size())
      return (float)(maxheap.top() + minheap.top()) / 2;
    else
      return (float)maxheap.top();
  }

  vector<double> slidingmedian(int k, vector<int> &nums) {

    this->k = k;
    this->nums = nums;
    vector<double> result;

    // sliding window
    int begin = 0;
    int end = 0;

    int count = 0;
    while (end < nums.size()) {

      while (count < k) {
        insert(nums[end]);
        end++;
        count++;
      }

      result.push_back(getmedian());

      // remove the first element of the window
      remove(nums[begin]);

      begin++;
      count--;
    }
  }
};

int main() {

  slidemedian sm;
  vector<int> nums = {1, 3, 5, 7, 9};
  int k = 3;

  vector<double> result = sm.slidingmedian(k, nums);
  for (double median : result) {
    cout << median << " ";
  }

  return 1;
}