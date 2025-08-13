// https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/?envType=study-plan-v2&envId=top-interview-150
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
   int removeDuplicates(vector<int>& nums) {
      // 处理特殊情况
      if(nums.size() <= 2) return nums.size();
      
      int l = 2;  // 前两个元素直接保留
      for(int r = 2; r < nums.size(); r++){
         // 如果当前元素与前两个元素不同，则保留
         if(nums[r] != nums[l - 2]){
               nums[l++] = nums[r];
         }
         // 否则说明已经重复超过两次，跳过当前元素
      }
      return l;
   }
}; 