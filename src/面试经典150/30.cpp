// https://leetcode.cn/problems/3sum/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
   vector<vector<int>> threeSum(vector<int>& nums) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      if(nums[0] > 0) return {};
      vector<vector<int>> ans;
      for(int first = 0; first < n - 2; first++){
         if(first > 0 && nums[first] == nums[first - 1]) continue;
         int l = first + 1;
         int r = n - 1;
         while(l < r){
            int sum = nums[first] + nums[l] + nums[r];
            if(sum == 0){
               ans.push_back({nums[first], nums[l], nums[r]});
               while(l < r && nums[l] == nums[l + 1]){
                  l++;
               }
               while(l < r && nums[r] == nums[r - 1]){
                  r--;
               }
               l++;
               r--;
            }
            else if(sum < 0){
               l++;
            }
            else{
               r--;
            }
         }
      }
      return ans;
   }
};