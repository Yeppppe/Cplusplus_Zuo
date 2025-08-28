// https://leetcode.cn/problems/summary-ranges/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
   vector<string> summaryRanges(vector<int>& nums) {
      int n = nums.size();
      int start;
      int end;
      vector<string> ans;
      for(int i = 0; i < n; i++){
         start = nums[i];
         end = nums[i];
         while(i + 1 < n && nums[i + 1] == nums[i] + 1){
               i++;
               end = nums[i];
         }
         string tmp;
         if(start == end){
               tmp = to_string(start);
         }
         else{
               tmp = to_string(start) + "->" + to_string(end);
         }
         ans.push_back(tmp);
      }
      return ans;
   }
};