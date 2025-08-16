// https://leetcode.cn/problems/rotate-array/?envType=study-plan-v2&envId=top-interview-150
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
   void rotate(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int> tmp(nums);
      for(int i = 0; i < n; i++){
         nums[(i + k)%n] = tmp[i];
      }
   }
};