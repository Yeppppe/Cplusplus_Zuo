
// 归并排序，填函数练习风格
// 测试链接 : https://leetcode.cn/problems/sort-an-array/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   vector<int> sortArray(vector<int>& nums) {
      int n = nums.size();
      mergesort(nums, 0 , n-1);
      return nums;
   }

   void mergesort(vector<int>& nums, int l, int r){
      if(l == r) return;
      int m = (l + r)/2;
      mergesort(nums, l , m);
      mergesort(nums, m+1, r);
      merge(nums,l , m , r);
   }

   void merge(vector<int> &nums, int l, int m, int r){
      int a = l;
      int b = m+1;
      vector<int> help;
      while(a <= m && b <= r){
         if(nums[a] <= nums[b]){
            help.push_back(nums[a++]);
         }
         else{
            help.push_back(nums[b++]);
         }
      }
      while(a <= m){
         help.push_back(nums[a++]);
      }
      while(b <= r){
         help.push_back(nums[b++]);
      }

      for(int i = 0, j = l; j <= r; i++,j++){
         nums[j] = help[i];
      }
   }
};

