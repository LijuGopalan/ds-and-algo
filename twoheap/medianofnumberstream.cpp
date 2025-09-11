/*
    Find Median from Data Stream

    Problem Statement:
    Design a class to calculate the median of a number stream. The class should have
    the following two methods:
    1. `addNum(int num)`: stores the number in the class.
    2. `findMedian()`: returns the median of all numbers inserted in the class.
    If the count of numbers is even, the median is the average of the two middle numbers.

    Algorithm Description: Two-Heap Strategy
    This problem can be efficiently solved by using two heaps:
    - A Max-Heap (`maxHeap`) to store the smaller half of the numbers.
    - A Min-Heap (`minHeap`) to store the larger half of the numbers.

    The heaps are balanced such that the `maxHeap` either has the same number of elements
    as the `minHeap` or one more element. This ensures that the median can be calculated
    quickly from the top elements of the heaps.
    - If the total number of elements is even, the median is the average of the tops of both heaps.
    - If the total number of elements is odd, the median is the top of the `maxHeap`.

    Time Complexity:
    - `addNum()`: O(log n) due to heap insertion and balancing.
    - `findMedian()`: O(1).
    Space Complexity: O(n) to store all the numbers in the heaps.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

/**
 * @class MedianFinder
 * @brief A data structure that finds the median of a stream of numbers.
 */
class MedianFinder {
private:
    // Max-heap to store the smaller half of the numbers
    std::priority_queue<int> maxHeap;
    // Min-heap to store the larger half of the numbers
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

public:
    /**
     * @brief Adds a number to the data structure.
     * @param num The number to add.
     */
    void addNum(int num) {
        // Add the new number to the appropriate heap
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance the heaps to maintain the property
        // maxHeap can have at most one more element than minHeap
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    /**
     * @brief Finds the median of all numbers added so far.
     * @return The median of the numbers.
     */
    double findMedian() {
        if (maxHeap.empty()) {
            return 0.0;
        }

        // If the heaps have the same size, the median is the average of their tops
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }

        // Otherwise, the median is the top of the max-heap
        return maxHeap.top();
    }
};

/**
 * @brief Main function to test the MedianFinder class.
 * @return 0 on successful execution.
 */
int main() {
    MedianFinder mf;

    mf.addNum(3);
    mf.addNum(1);
    std::cout << "After adding 3, 1 -> Median is: " << mf.findMedian() << " (Expected: 2)" << std::endl;

    mf.addNum(5);
    std::cout << "After adding 5   -> Median is: " << mf.findMedian() << " (Expected: 3)" << std::endl;

    mf.addNum(4);
    std::cout << "After adding 4   -> Median is: " << mf.findMedian() << " (Expected: 3.5)" << std::endl;

    return 0;
}