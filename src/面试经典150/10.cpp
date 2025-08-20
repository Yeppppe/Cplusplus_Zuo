// https://leetcode.cn/problems/jump-game-ii/?envType=study-plan-v2&envId=top-interview-150
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
   int jump(vector<int>& nums) {
      int cur = 0;
      int end = 0;
      int max_pose = 0;
      int step = 0;
      int n = nums.size();
      while(max_pose < n - 1){
         for(int i = cur; i <= end; i++){
            max_pose = max(max_pose , i+nums[i]);
         }
         cur = end + 1;
         end = max_pose;
         step++;
      }
      return step;
   }
};