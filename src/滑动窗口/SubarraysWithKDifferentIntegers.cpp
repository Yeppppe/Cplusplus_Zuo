// K个不同整数的子数组
// 给定一个正整数数组 nums和一个整数 k，返回 nums 中 「好子数组」 的数目。
// 如果 nums 的某个子数组中不同整数的个数恰好为 k
// 则称 nums 的这个连续、不一定不同的子数组为 「好子数组 」。
// 例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。
// 子数组 是数组的 连续 部分。
// 测试链接 : https://leetcode.cn/problems/subarrays-with-k-different-integers/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
   int subarraysWithKDistinct(vector<int>& nums, int k) {
      return getAllk(nums,k) - getAllk(nums,k-1);
   }

   int getAllk(vector<int>& nums, int k){
      int max_val = *max_element(nums.begin(), nums.end());    //! max_element(nums.begin(),nums.end()) 返回一个迭代器，指向当前范围内的最大元素
      vector<int> cnt(max_val + 1, 0); // 确保数组大小足够容纳所有可能的值  
      int ans = 0;
      for(int l=0,r=0,collect=0;r<nums.size();r++){
         if(cnt[nums[r]]++ == 0){
            collect++;
         }
         while(collect > k){
            if(--cnt[nums[l++]] == 0){
               collect--;
            }
         }
         ans += r - l + 1;
      }
      return ans;
   }
};