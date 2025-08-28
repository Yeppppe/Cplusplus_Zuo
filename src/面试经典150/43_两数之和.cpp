// https://leetcode.cn/problems/two-sum/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
   vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int> map;
      vector<int> ans;
      int n = nums.size();
      for(int i = 0; i < n; i++){
         if(map.find(target - nums[i]) != map.end()){
            return {i,map[target - nums[i]]};
         }
         map[nums[i]] = i;                             //! 先搜索在 添加 能够避免查询到自己的情况
      }
      return ans;
   }
};