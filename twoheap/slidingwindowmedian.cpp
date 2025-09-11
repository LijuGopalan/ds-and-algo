/*
    Sliding Window Median

    Problem Statement:
    Given an array of numbers `nums` and a window size `k`, find the median of each
    window as it slides from left to right.

    Example:
    Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
    Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
    Explanation:
    Window position                Median
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       1
     1 [3  -1  -3] 5  3  6  7      -1
     1  3 [-1  -3  5] 3  6  7      -1
     1  3  -1 [-3  5  3] 6  7       3
     1  3  -1  -3 [5  3  6] 7       5
     1  3  -1  -3  5 [3  6  7]      6

    Algorithm Description:
    This solution uses the two-heap method combined with lazy deletion to handle the
    sliding window efficiently.
    - Two heaps (a max-heap for the smaller half and a min-heap for the larger half)
      are used to find the median in O(1) time.
    - An unordered_map (`invalidated`) is used to mark elements for lazy deletion. When an
      element slides out of the window, we increment its count in the map. We don't
      remove it from the heap immediately.
    - When we access the top of a heap (to calculate the median or to balance), we first
      check if the top element is marked as invalid. If it is, we pop it from the heap,
      decrement its count in the map, and repeat until the top is a valid element.
    - This approach keeps the `add` and `remove` operations at an average of O(log k) time.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>

/**
 * @class SlidingWindowMedian
 * @brief Calculates the median of a sliding window over an array.
 */
class SlidingWindowMedian {
private:
    std::priority_queue<double> maxHeap;
    std::priority_queue<double, std::vector<double>, std::greater<double>> minHeap;
    std::unordered_map<double, int> invalidated;

    /**
     * @brief Balances the two heaps to maintain the size property.
     * The max-heap can have at most one more element than the min-heap.
     */
    void balance() {
        // First, prune invalid elements from the top of the heaps
        while (!maxHeap.empty() && invalidated[maxHeap.top()] > 0) {
            invalidated[maxHeap.top()]--;
            maxHeap.pop();
        }
        while (!minHeap.empty() && invalidated[minHeap.top()] > 0) {
            invalidated[minHeap.top()]--;
            minHeap.pop();
        }
        
        // Now, perform the balancing act
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // Prune again after balancing
        while (!maxHeap.empty() && invalidated[maxHeap.top()] > 0) {
            invalidated[maxHeap.top()]--;
            maxHeap.pop();
        }
        while (!minHeap.empty() && invalidated[minHeap.top()] > 0) {
            invalidated[minHeap.top()]--;
            minHeap.pop();
        }
    }

public:
    /**
     * @brief Finds the median for each sliding window of size k.
     *
     * @param nums The input vector of numbers.
     * @param k The size of the sliding window.
     * @return A vector of doubles containing the median of each window.
     */
    std::vector<double> findSlidingWindowMedian(const std::vector<int>& nums, int k) {
        std::vector<double> medians;
        if (k == 0 || nums.empty()) return medians;

        for (int i = 0; i < nums.size(); ++i) {
            // Add the new element to the heaps
            if (maxHeap.empty() || nums[i] <= maxHeap.top()) {
                maxHeap.push(nums[i]);
            } else {
                minHeap.push(nums[i]);
            }
            balance();

            // Mark the outgoing element for lazy deletion
            if (i >= k) {
                invalidated[nums[i - k]]++;
            }
            
            balance(); // Clean up tops before calculating median

            // If the window has reached size k, calculate and store the median
            if (i >= k - 1) {
                if (maxHeap.size() == minHeap.size()) {
                    medians.push_back((maxHeap.top() + minHeap.top()) / 2.0);
                } else {
                    medians.push_back(maxHeap.top());
                }
            }
        }
        return medians;
    }
};

/**
 * @brief Main function to test the SlidingWindowMedian class.
 * @return 0 on successful execution.
 */
int main() {
    SlidingWindowMedian swm;
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    std::cout << "Input: [1, 3, -1, -3, 5, 3, 6, 7], k = 3" << std::endl;
    std::vector<double> result = swm.findSlidingWindowMedian(nums, k);

    std::cout << "Medians: ";
    for (double median : result) {
        std::cout << median << " ";
    }
    std::cout << "\n(Expected: 1 -1 -1 3 5 6)" << std::endl;

    return 0;
}