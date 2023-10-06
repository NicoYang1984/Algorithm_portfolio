#include <bits/stdc++.h>
#include <vector>

using namespace std;

// 分治函数，计算最大子序和
int maxSubArray(vector<int>& nums, int left, int right) {
    if (left == right) {
        return nums[left];
    }
    
    int mid = left + (right - left) / 2;
    
    // 分别计算左半部分、右半部分和跨越中点的子序和
    int maxLeftSum = maxSubArray(nums, left, mid);
    int maxRightSum = maxSubArray(nums, mid + 1, right);
    int maxCrossingSum = 0;
    
    int leftSum = INT_MIN;
    int rightSum = INT_MIN;
    
    for (int i = mid; i >= left; --i) {
        maxCrossingSum += nums[i];
        leftSum = max(leftSum, maxCrossingSum);
    }
    
    maxCrossingSum = 0;
    
    for (int i = mid + 1; i <= right; ++i) {
        maxCrossingSum += nums[i];
        rightSum = max(rightSum, maxCrossingSum);
    }
    
    // 返回三者中的最大值
    return max(maxLeftSum, max(maxRightSum, leftSum + rightSum));
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    int result = maxSubArray(nums, 0, n - 1);
    cout << result << endl;
    
    return 0;
}

