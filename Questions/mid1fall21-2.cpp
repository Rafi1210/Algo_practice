/*
X is a youtuber. Now, he is in a mission to visit several tourist spots and stay distinct number of days in each spot. 
So while he is visiting a particular spot , he is in a problem to find out the number of days he should stay in that spot.
You are given a sorted non-negative distinct integers, design an algorithm that finds the smallest missing non-negative element on it.
Your solution should not takr more than logn instructions in worst case.

Example :
Input : nums[] = {0,1,2,6,9,11,15}
Output : 3
*/

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
