// https://leetcode.cn/problems/maximum-subarray/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int pre = 0;
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            pre += nums[i];
            pre = max(pre, nums[i]);
            ans = max(ans, pre);
        }
        return ans;
    }
};