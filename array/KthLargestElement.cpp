#include <iostream>
#include <vector>
#include <queue>

int findKthLargest(std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    for (int num : nums) {
        min_heap.push(num);
        if (min_heap.size() > k) {
            min_heap.pop();
        }
    }
    return min_heap.top();
}

int main() {
    std::vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    std::cout << "The " << k1 << "th largest element is " << findKthLargest(nums1, k1) << std::endl;

    std::vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    std::cout << "The " << k2 << "th largest element is " << findKthLargest(nums2, k2) << std::endl;

    return 0;
}
