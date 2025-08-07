#include <iostream>
#include <vector>
#include <algorithm>

int binarySearch(const std::vector<int>& arr, int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

int main() {
    std::vector<int> arr = {2, 3, 4, 10, 40};
    std::sort(arr.begin(), arr.end()); // Binary search requires a sorted array
    int x = 10;
    int result = binarySearch(arr, 0, arr.size() - 1, x);
    if (result == -1)
        std::cout << "Element is not present in array" << std::endl;
    else
        std::cout << "Element is present at index " << result << std::endl;
    return 0;
}
