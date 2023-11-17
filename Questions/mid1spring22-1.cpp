/*
Mr. Thorin a famous researcher who visits different place and record the temperature of that place. As he uses to visit different place of the world, temperature he recorded can be both positive and negative. He stored the value of the temperature in consecutive way like {-1, 5, 20, -18, -5, 33, 24). Now he wants know maximum continuous subset that has maximum sum. See following example for better understanding.
For example, if the given array is {-2, -5, 6, -2, -3, 1, 5, -6}, then the maximum subarray sum is 7 that is made by {6, -2, -3, 1, 5}.
You are given the temperature of n places. Your task is to design an efficient algorithm using a suitable design technique that find the continuous subset having maximum sum. Worst case run time complexity of your algorithm can not be more than nlogn.
*/

#include <iostream>
#include <vector>

// Function to find the maximum of three integers
int max(int a, int b, int c) {
    return std::max(std::max(a, b), c);
}

// Function to find the maximum sum crossing the middle element
int maxCrossingSum(const std::vector<int>& arr, int low, int mid, int high) {
    // Include elements on the left of the mid
    int leftSum = -999999;
    int sum = 0;
    for (int i = mid; i >= low; --i) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }

    // Include elements on the right of the mid
    int rightSum = -999999;
    sum = 0;
    for (int i = mid + 1; i <= high; ++i) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }

    // Return the sum of elements on the left and right of the mid
    return leftSum + rightSum;
}

// Function to find the maximum contiguous subarray sum using divide and conquer
int maxSubArraySum(const std::vector<int>& arr, int low, int high) {
    // Base case: if there is only one element
    if (low == high) {
        return arr[low];
    }

    // Find the middle point
    int mid = (low + high) / 2;

    // Return the maximum of the following three cases:
    // 1. Maximum subarray sum in the left half
    // 2. Maximum subarray sum in the right half
    // 3. Maximum subarray sum that crosses the middle
    return max(maxSubArraySum(arr, low, mid),
               maxSubArraySum(arr, mid + 1, high),
               maxCrossingSum(arr, low, mid, high));
}

int main() {
    std::vector<int> temperatures = {-2, -5, 6, -2, -3, 1, 5, -6};

    int n = temperatures.size();

    int maxSum = maxSubArraySum(temperatures, 0, n - 1);

    std::cout << "The maximum subarray sum is: " << maxSum << std::endl;

    return 0;
}
