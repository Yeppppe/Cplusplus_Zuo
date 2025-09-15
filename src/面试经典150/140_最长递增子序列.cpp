// https://leetcode.cn/problems/longest-increasing-subsequence/submissions/661166484/?envType=study-plan-v2&envId=top-interview-150

#include <algorithm>
#include <vector>
using namespace std;

//! 第一次尝试用dp的写法
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());   
    }
};