// https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/?envType=study-plan-v2&envId=top-interview-150


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
   int findMinArrowShots(vector<vector<int>>& points) {
      int ans = 1;
      sort(points.begin(),points.end(), [](const vector<int>& a, const vector<int>& b){
         return a[1] < b[1];
      });
      int pos = points[0][1];
      for(auto p : points){
         if(pos < p[0]){
               pos = p[1];
               ans++;
         }
      }
      return ans;
   }
};