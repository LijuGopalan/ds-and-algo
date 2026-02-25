/*

The median is the middle value in a sorted list of numbers.
If the list has an even number of elements, the median is the average of the two
middle numbers. If the list has an odd number of elements, the median is the
middle number.

Sorted makes indertion difficult, unless we use a proper data structure to keep
the numbers. Storing the number in an array and sorting it every time we need to
find the median is not efficient. We can use a heap data structure to keep the
numbers in sorted order.



Problem Statement #
Design a class to calculate the median of a number stream. The class should have
the following two methods:

insertNum(int num): stores the number in the class
findMedian(): returns the median of all numbers inserted in the class
If the count of numbers inserted in the class is even, the median will be the
average of the middle two numbers.

Example 1:

1. insertNum(3)
2. insertNum(1)
3. findMedian() -> output: 2
4. insertNum(5)
5. findMedian() -> output: 3
6. insertNum(4)
7. findMedian() -> output: 3.5
Try it yourself #

*/

// using heap datastructure. 2 heap stratogy

// Will keep maxheap with 1 more element than minheap. else both should have
// same element. always adjust the min and max heap while insert according to
// the above logic. The max heap will have the smaller half of the numbers and
// the min heap will have the larger half of the numbers. The median will be the
// top of the max heap if the number of elements is odd, or the average of the
// tops of both heaps if even.

/*

Time complexity #
The time complexity of the insertNum() will be O(logN) due to the insertion in
the heap. The time complexity of the findMedian() will be O(1) as we can find
the median from the top elements of the heaps.

Space complexity #
The space complexity will be
O(N) because, as at any time, we will be storing all the numbers.

*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {

public:
  priority_queue<int> max_queue;
  priority_queue<int, vector<int>, greater<int>> min_queue;

  void insertNum(int num) {

    if (max_queue.empty() || num <= max_queue.top()) {
      max_queue.push(num);
    } else {
      min_queue.push(num);
    }

    // rebalance
    if (max_queue.size() > (min_queue.size() + 1)) {
      min_queue.push(max_queue.top());
      max_queue.pop();
    } else if (min_queue.size() > max_queue.size()) {
      max_queue.push(min_queue.top());
      max_queue.pop();
    }
  }

  double getMedian() {

    if (max_queue.size() == min_queue.size()) {
      return (max_queue.top() + min_queue.top()) / 2.0;
    } else {
      return max_queue.top();
    }
  }
};

int main() {

  MedianFinder med_obj;

  med_obj.insertNum(5);
  med_obj.insertNum(4);
  med_obj.insertNum(4);
  med_obj.insertNum(5);

  cout << "\nMedian is " << med_obj.getMedian() << endl;

  return 0;
}