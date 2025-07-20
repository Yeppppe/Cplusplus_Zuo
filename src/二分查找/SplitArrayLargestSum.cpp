// 分割数组的最大值(画匠问题)
// 给定一个非负整数数组 nums 和一个整数 m
// 你需要将这个数组分成 m 个非空的连续子数组。
// 设计一个算法使得这 m 个子数组各自和的最大值最小。
// 测试链接 : https://leetcode.cn/problems/split-array-largest-sum/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   int splitArray(vector<int>& nums, int k) {
      int l = 0;
      int r = 0;
      int ans = 0;
      for(auto n: nums){
         l = max(l, n);
         r += n;
      }
      while(l <= r){
         int m = l + (r - l)/2;
         if(splitnum(nums,m) <= k){
            ans = m;
            r = m - 1;
         }
         else{
            l = m + 1;
         }
      }
      return ans;
   }

   int splitnum(vector<int>& nums, int m){
      int ans = 0;
      int sum = 0;
      for(auto n : nums){
         sum += n;
         if(sum > m){
            sum = n;
            ans += 1;
         }
      }
      return ans+1;
   }
};


