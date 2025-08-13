// https://leetcode.cn/problems/remove-duplicates-from-sorted-array/?envType=study-plan-v2&envId=top-interview-150
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
   int removeDuplicates(vector<int>& nums) {
      unordered_map<int,int> map;
      int left = 0;
      for(int r = 0; r < nums.size();r++){
         if(map.find(nums[r]) == map.end()){
               map[nums[r]] = 1;
               nums[left] = nums[r];
               left++;
         }
      }
      return left;
   }
};

