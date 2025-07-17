// 接雨水
// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水
// 测试链接 : https://leetcode.cn/problems/trapping-rain-water/



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   int trap(vector<int>& height) {
      int left = height[0];
      int right = height[height.size()-1];
      int l = 1;
      int r = height.size()-2;
      int ans = 0;
      while(l <= r){
         if(left <= right){
            ans += max(0,left - height[l]);
            left = max(left,height[l++]);
         }
         else{
            ans += max(0,right - height[r]);
            right = max(right,height[r--]);
         }
      }
      return ans;
   }
};