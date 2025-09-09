// https://leetcode.cn/problems/maximum-sum-circular-subarray/description/?envType=study-plan-v2&envId=top-interview-150


#include <vector>
#include <algorithm>
using namespace std;
// 1. 构成最大子数组和的子数组为 nums[i:j]，包括 nums[i] 到 nums[j−1] 共 j−i 个元素，其中 0≤i<j≤n。
// 2. 构成最大子数组和的子数组为 nums[0:i] 和 nums[j:n]，其中 0<i<j<n。

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int pre = nums[0];
        int res = nums[0];
        vector<int> left_max(n);
        int left_sum = nums[0];
        left_max[0] = nums[0];
        for(int i = 1; i < n; i++){
            pre = max(pre + nums[i], nums[i]);
            res = max(res, pre);
            left_sum += nums[i];
            left_max[i] = max(left_max[i - 1], left_sum);
        }

        int right_sum = 0;
        for(int i = n - 1; i > 0; i--){
            right_sum += nums[i];
            res = max(res, right_sum + left_max[i - 1]);
        }
        return res;
    }
};




//! 环形部分按照取反表示
class Solution2 {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int premax = nums[0];
        int maxres = nums[0];
        int premin = nums[0];
        int minres = nums[0];
        int sum = nums[0];
        for(int i = 1; i < n; i++){
            premax = max(premax + nums[i], nums[i]);
            maxres = max(maxres, premax);

            premin = min(premin + nums[i], nums[i]);
            minres = min(minres, premin);

            sum += nums[i];
        }
        if(premax < 0) return maxres;
        return max(maxres, sum - minres);
    }
};