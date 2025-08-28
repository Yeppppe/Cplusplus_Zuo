// https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   vector<int> twoSum(vector<int>& numbers, int target) {
      int n = numbers.size();
      int l = 0, r = n - 1;
      vector<int> ans;
      while(l < r){
         if(numbers[l] + numbers[r] < target){
            l++;
         }
         else if(numbers[l] + numbers[r] > target){
            r--;
         }
         else{
            ans.push_back(l+1);
            ans.push_back(r+1);
            return ans;
         }
      }
      return {-1,-1};
   }
};

