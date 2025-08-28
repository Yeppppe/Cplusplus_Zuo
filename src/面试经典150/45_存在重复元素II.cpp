// https://leetcode.cn/problems/contains-duplicate-ii/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
   bool containsNearbyDuplicate(vector<int>& nums, int k) {
      int n = nums.size();
      unordered_map<int, int> map;
      int len = 0;
      for(int i = 0; i < n; i++){
         if(map.count(nums[i])){
               len = i - map[nums[i]];
               if(len <= k) return true;
         }
         map[nums[i]] = i;
      }
      return false;
   }
};
