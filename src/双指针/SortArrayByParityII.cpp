// 按奇偶排序数组II
// 给定一个非负整数数组 nums。nums 中一半整数是奇数 ，一半整数是偶数
// 对数组进行排序，以便当 nums[i] 为奇数时，i也是奇数
// 当 nums[i] 为偶数时， i 也是 偶数
// 你可以返回 任何满足上述条件的数组作为答案
// 测试链接 : https://leetcode.cn/problems/sort-array-by-parity-ii/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   vector<int> sortArrayByParityII(vector<int>& nums) {
      int index_0 = 0;
      int index_1 = 1;
      vector<int> ans(nums.size(),0);
      for(int i = 0; i<nums.size();i++){
         if(nums[i]%2 == 0){
            ans[index_0] = nums[i];
            index_0 += 2;
         }
         else{
            ans[index_1] = nums[i];
            index_1 += 2;
         }
      }
      return ans;
   }
};