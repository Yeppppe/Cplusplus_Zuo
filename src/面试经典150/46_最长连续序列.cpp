// https://leetcode.cn/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
   int longestConsecutive(vector<int>& nums) {
      if(nums.size() == 0) return 0;
      unordered_set<int> set;
      for(auto n : nums){
         set.insert(n);
      }
      int max_len = 1;
      for(auto n : set){
         if(!set.count(n - 1)){
               int curnum = n;
               int curlen = 1;
               while(set.count(curnum + 1)){
                  curnum++;
                  curlen++;
               }
               max_len = max(max_len,curlen);
         }
      }
      return max_len;
   }
};