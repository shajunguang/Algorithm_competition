//求数组中连续子串最大和
//二分法,可以理解为每次分解为中点左侧的最大值,右侧的最大值和中间最大值三者比较
#include<bits/stdc++.h>
using namespace std;

class Solution {
// 分治法
public:
    int maxSubArray(vector<int> &nums) {
        if (nums.size() == 0) return INT_MIN;
        return divide(nums, 0, nums.size() - 1);
    }

    int divide(vector<int> &nums, int left, int right) {
        if (left == right) return nums[left];
        int mid = (left + right) / 2;
        // 1. 最大数列和在左边
        int sumLeft = divide(nums, left, mid);
        // 2. 最大数列和在右边
        int sumRight = divide(nums, mid + 1, right);
        // 3. 最大数列和在中间
        // 先求左边的最大和
        int leftSum = 0, leftMaxSum = INT_MIN;
        for (int i = mid; i >= left; i--) {
            leftSum += nums[i];
            leftMaxSum = max(leftMaxSum, leftSum);
        }
        // 求右边的最大和
        int rightSum = 0, rightMaxSum = INT_MIN;
        for (int i = mid + 1; i <= right; i++) {
            rightSum += nums[i];
            rightMaxSum = max(rightMaxSum, rightSum);
        }
        return max(max(sumLeft, sumRight), leftMaxSum + rightMaxSum);
    }
};

int main()
{
    vector<int> nums={-2,1,-3,4,-1,2,1,-5};
    Solution res;
    cout<<res.maxSubArray(nums)<<endl;

    return 0;
}