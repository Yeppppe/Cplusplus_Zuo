// https://leetcode.cn/problems/minimum-size-subarray-sum/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
   int minSubArrayLen(int target, vector<int>& nums) {
      int n = nums.size();
      int l = 0, r = 0;
      int sum = nums[l];
      int ans = INT_MAX;
      if(sum >= target) return 1;
      while(l < n && r < n){
         while(r < n - 1 && sum < target){
            sum += nums[++r];
         }
         if(sum >= target){
            ans = min(ans, r - l + 1);
         }
         sum -= nums[l++];
      }
      return ans == INT_MAX ? 0 : ans;
   }
};