// 缺失的第一个正数
// 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
// 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
// 测试链接 : https://leetcode.cn/problems/first-missing-positive/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   int firstMissingPositive(vector<int>& nums) {
      int size = nums.size();
      int l = 0;
      int r = size - 1;
      while(l <= r){                  //! 临界是小于等于
         if(nums[l] == l+1){                     
            l++;
         }
         else if(nums[l] < l+1 || nums[l] >r+1 || nums[nums[l]-1] == nums[l]){
            swap(nums,l,r);
            r--;
         }
         else{
            swap(nums,l,nums[l]-1);
         }
      }  
      return l+1;
   }

   void swap(vector<int>& nums , int i, int j){
      int tmp = nums[i];
      nums[i] = nums[j];
      nums[j] = tmp;
   }
};