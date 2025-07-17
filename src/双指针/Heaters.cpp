// 供暖器
// 冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。
// 在加热器的加热半径范围内的每个房屋都可以获得供暖。
// 现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置
// 请你找出并返回可以覆盖所有房屋的最小加热半径。
// 说明：所有供暖器都遵循你的半径标准，加热的半径也一样。
// 测试链接 : https://leetcode.cn/problems/heaters/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
   int findRadius(vector<int>& houses, vector<int>& heaters) {
      sort(houses.begin(),houses.end());
      sort(heaters.begin(),heaters.end());
      int l = 0;
      int j = 0;
      int ans = INT_MIN;
      while(l < houses.size()){
         while(!isbest(houses,heaters,l,j)){
            j++;
         }
         ans = max(ans,abs(houses[l] - heaters[j]));
         l++;
      }
      return ans;
   }

   int isbest(vector<int>& houses, vector<int>& heaters,int i, int j){
      return j == heaters.size()-1 || (abs(houses[i] - heaters[j]) < abs(houses[i] - heaters[j+1]));      //! 这个逻辑比较绕，什么时候j不继续加，一个是到头了，不能加了，或者当前距离是最小值了不能加了，要反过来想
   }
};