// https://leetcode.cn/problems/trapping-rain-water/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   int trap(vector<int>& height) {
      int n = height.size();
      int left = height[0];
      int right = height[n - 1];
      int l = 1;
      int r = n - 2;
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