// 找出第K小的数对距离
// 数对 (a,b) 由整数 a 和 b 组成，其数对距离定义为 a 和 b 的绝对差值。
// 给你一个整数数组 nums 和一个整数 k
// 数对由 nums[i] 和 nums[j] 组成且满足 0 <= i < j < nums.length
// 返回 所有数对距离中 第 k 小的数对距离。
// 测试链接 : https://leetcode.cn/problems/find-k-th-smallest-pair-distance/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
   int smallestDistancePair(vector<int>& nums, int k) {
      sort(nums.begin(),nums.end());
      int l = 0;
      int r = nums[nums.size() - 1] - nums[0];
      int m = 0;
      int ans = 0;
      while(l <= r){
         m = l + (r - l)/2;
         if(findless(nums,m) >= k){      //! 这个条件判断要好好思考下
            ans = m;
            r = m - 1;
         }
         else{
            l = m + 1;
         }
      }
      return ans;
   }

   int findless(vector<int>& nums , int less){
      int ans = 0;
      for(int l = 0,r = 0; l < nums.size();l++){
         while(r + 1 < nums.size() && nums[r + 1] - nums[l] <= less){                 //! 这个双指针很妙，也要好好思考下，且越界判断要放在解引用之前
            r++;
         }
         ans += r - l;
      }
      return ans;
   }
};
