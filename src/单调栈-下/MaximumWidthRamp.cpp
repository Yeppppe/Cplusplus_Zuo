// 最大宽度坡
// 给定一个整数数组 A，坡是元组 (i, j)，其中  i < j 且 A[i] <= A[j]
// 这样的坡的宽度为 j - i，找出 A 中的坡的最大宽度，如果不存在，返回 0
// 测试链接 : https://leetcode.cn/problems/maximum-width-ramp/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   int maxWidthRamp(vector<int>& nums) {
      int ans = 0;
      vector<int> stack;
      int n = nums.size();
      stack.push_back(0);
      for(int i = 1; i < n; i++){
         while(!stack.empty() && nums[stack.back()] > nums[i]){
            stack.push_back(i);
         }
      }
      for(int i = n-1; i >=0 ; i--){
         while(!stack.empty() && nums[stack.back()] <= nums[i]){
            int cur = stack.back();
            ans = max(ans, i - cur);
            stack.pop_back();
         }
      }
      return ans;
   }
};