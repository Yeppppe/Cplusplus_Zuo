// https://leetcode.cn/problems/jump-game/?envType=study-plan-v2&envId=top-interview-150
// 55.跳跃问题

//! 难  多看 贪心
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
   bool canJump(vector<int>& nums) {
      int n = nums.size();
      int next_max = 0;
      for(int i = 0; i < n; i++){
         if(i <= next_max){
            next_max = max(next_max , i + nums[i]);
            if(next_max >= n - 1) return true;
         }
      }
      return false;
   }
};