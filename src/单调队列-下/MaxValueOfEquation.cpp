// 满足不等式的最大值
// 给你一个数组 points 和一个整数 k
// 数组中每个元素都表示二维平面上的点的坐标，并按照横坐标 x 的值从小到大排序
// 也就是说 points[i] = [xi, yi]
// 并且在 1 <= i < j <= points.length 的前提下，xi < xj 总成立
// 请你找出 yi + yj + |xi - xj| 的 最大值，
// 其中 |xi - xj| <= k 且 1 <= i < j <= points.length
// 题目测试数据保证至少存在一对能够满足 |xi - xj| <= k 的点。
// 测试链接 : https://leetcode.cn/problems/max-value-of-equation/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
   int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
      int n = points.size();
      vector<pair<int, int>> deque(n);
      int h = 0;
      int t = 0;
      int ans = INT_MIN;
      for(int i = 0;i < n; i++){
         while(h < t && points[i][0] - deque[h].first > k){             //!  要注意容器为空的情况
            h++;
         }

         if(h < t){
            ans = max(ans, points[i][0] + points[i][1] + deque[h].second - deque[h].first);
         }

         while(h < t && (deque[t-1].second - deque[t-1].first) <= (points[i][1] - points[i][0])){
            t--;
         }
         deque[t].first = points[i][0];
         deque[t++].second = points[i][1];
      }
      
      return ans;
   }
};