// 救生艇
// 给定数组 people
// people[i]表示第 i 个人的体重 ，船的数量不限，每艘船可以承载的最大重量为 limit
// 每艘船最多可同时载两人，但条件是这些人的重量之和最多为 limit
// 返回 承载所有人所需的最小船数
// 测试链接 : https://leetcode.cn/problems/boats-to-save-people/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
   int numRescueBoats(vector<int>& people, int limit) {
      sort(people.begin(),people.end());
      int l = 0;
      int r = people.size()-1;
      int ans= 0;    //! 注意变量一定要初始化
      int sum = 0;
      while(l <= r){
         sum = l == r ? people[l] : people[l] + people[r];
         if(sum > limit){
            r--;
         }
         else{
            l++;
            r--;
         }
         ans += 1;
      }
      return ans;
   }
};