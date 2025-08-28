// https://leetcode.cn/problems/merge-intervals/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
   vector<vector<int>> merge(vector<vector<int>>& intervals) {
      sort(intervals.begin(),intervals.end(),[](const vector<int>& a, const vector<int>& b){
         return a[0] < b[0];
      });
      vector<vector<int>> ans;
      int n = intervals.size();
      for(int i = 0; i < n; i++){
         vector<int> tmp = intervals[i];
         int bg = intervals[i][0];
         int ed = intervals[i][1];
         while((i < n - 1) && intervals[i + 1][0] <= ed){
               // bg = min(bg, intervals[i + 1][0]);
               ed = max(ed, intervals[i + 1][1]);
               tmp = {bg, ed};
               i++;
         }
         ans.push_back(tmp);
      }
      return ans;
   }
};

