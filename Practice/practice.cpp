#include <iostream>
#include <vector>

int findSmallestMissing(const std::vector<int>& nums) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        // If the mid element is equal to its index, the missing element is on the right.
        // Otherwise, the missing element is on the left.
        if (nums[mid] == mid) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int main() {
    std::vector<int> nums = {0, 1, 2, 6, 9, 11, 15};

    int result = findSmallestMissing(nums);

    std::cout << "The smallest missing non-negative element is: " << result << std::endl;

    return 0;
}
