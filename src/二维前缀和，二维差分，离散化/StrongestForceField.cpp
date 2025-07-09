// 最强祝福力场
// 小扣在探索丛林的过程中，无意间发现了传说中"落寞的黄金之都"
// 而在这片建筑废墟的地带中，小扣使用探测仪监测到了存在某种带有「祝福」效果的力场
// 经过不断的勘测记录，小扣将所有力场的分布都记录了下来
// forceField[i] = [x,y,side] 
// 表示第 i 片力场将覆盖以坐标 (x,y) 为中心，边长为 side 的正方形区域。
// 若任意一点的 力场强度 等于覆盖该点的力场数量
// 请求出在这片地带中 力场强度 最强处的 力场强度
// 注意：力场范围的边缘同样被力场覆盖。
// 测试链接 : https://leetcode.cn/problems/xepqZ5/



//! 经常遇到heap_overflow堆溢出的问题，使用ll替换int 数值溢出也是溢出 int最大能存储约21亿 遇到10的九次方 就统一换成long long吧
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define ll long long 
class Solution {
public:
   int fieldOfGreatestBlessing(vector<vector<int>>& forceField) {
      set<ll> xs,ys;

      for(auto f : forceField){
         ll x = f[0];
         ll y = f[1];
         ll r = f[2];

         //* 左上角
         ll x1 = x*2 -r;
         ll y1 = y*2 -r;

         //* 右上角
         ll x2 = x * 2 + r;
         ll y2 = y * 2 + r;

         xs.insert(x1);
         xs.insert(x2);
         ys.insert(y1);
         ys.insert(y2);
      }

      vector<ll> ax(xs.begin(),xs.end());
      vector<ll> ay(ys.begin(),ys.end());

      int m = ax.size();
      int n = ay.size();
      vector<vector<ll>> diff(n+2,(vector<ll>(m+2, 0)));

      for(auto f : forceField){
         ll x = f[0];
         ll y = f[1];
         ll r = f[2];

         ll x1 = lower_bound(ax.begin(),ax.end(),x*2 -r) - ax.begin();
         ll y1 = lower_bound(ay.begin(),ay.end(),y*2 -r) - ay.begin();
         ll x2 = lower_bound(ax.begin(),ax.end(),x*2 +r) - ax.begin();
         ll y2 = lower_bound(ay.begin(),ay.end(),y*2 +r) - ay.begin();

         diff[y1+1][x1+1]++;
         diff[y1+1][x2+2]--;
         diff[y2+2][x1+1]--;
         diff[y2+2][x2+2]++;
      }

      ll ans = 0;
      for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
               diff[i][j] += diff[i-1][j] + diff[i][j-1] - diff[i-1][j-1];
               ans = max(ans, diff[i][j]);
            }
      }
      return ans;

   }
};