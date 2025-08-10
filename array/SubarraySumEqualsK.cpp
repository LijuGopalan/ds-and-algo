#include <iostream>
#include <vector>
#include <unordered_map>

int subarraySum(std::vector<int>& nums, int k) {
    int count = 0;
    int sum = 0;
    std::unordered_map<int, int> preSum;
    preSum[0] = 1;
    for (int num : nums) {
        sum += num;
        if (preSum.find(sum - k) != preSum.end()) {
            count += preSum[sum - k];
        }
        preSum[sum]++;
    }
    return count;
}

int main() {
    std::vector<int> nums1 = {1, 1, 1};
    int k1 = 2;
    std::cout << "The number of subarrays with sum " << k1 << " is " << subarraySum(nums1, k1) << std::endl;

    std::vector<int> nums2 = {1, 2, 3};
    int k2 = 3;
    std::cout << "The number of subarrays with sum " << k2 << " is " << subarraySum(nums2, k2) << std::endl;

    return 0;
}
