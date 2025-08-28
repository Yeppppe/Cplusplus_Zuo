// https://leetcode.cn/problems/insert-interval/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
   vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      int left = newInterval[0];
      int right = newInterval[1];
      vector<vector<int>> ans;
      int n = intervals.size();
      bool place = false;
      for(int i = 0; i < n; i++){
         if(intervals[i][1] < left){
               ans.push_back(intervals[i]);
               continue;
         }
         else if(intervals[i][0] > right){
               ans.push_back(intervals[i]);
               continue;
         }
         else{
               left = min(left,intervals[i][0]);
               right = max(right,intervals[i][1]);
         }
      }
      ans.push_back({left,right});
      sort(ans.begin(),ans.end(),[](const vector<int>& a, const vector<int>& b){
         return a[0] < b[0];
      });
      return ans;
   }
};