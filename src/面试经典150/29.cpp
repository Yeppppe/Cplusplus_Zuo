// https://leetcode.cn/problems/container-with-most-water/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
   int maxArea(vector<int>& height) {
      int l = 0, r = height.size() - 1;
      int sum = 0;
      while(l < r){
         int mh = min(height[l],height[r]);
         sum = max(sum,mh*(r - l));
         if(height[l] <= height[r]){
            l++;
         }
         else{
            r--;
         }
      } 
      return sum; 
   }
};
