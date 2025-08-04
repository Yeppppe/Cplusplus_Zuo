// 最低票价
// 在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行
// 在接下来的一年里，你要旅行的日子将以一个名为 days 的数组给出
// 每一项是一个从 1 到 365 的整数
// 火车票有 三种不同的销售方式
// 一张 为期1天 的通行证售价为 costs[0] 美元
// 一张 为期7天 的通行证售价为 costs[1] 美元
// 一张 为期30天 的通行证售价为 costs[2] 美元
// 通行证允许数天无限制的旅行
// 例如，如果我们在第 2 天获得一张 为期 7 天 的通行证
// 那么我们可以连着旅行 7 天(第2~8天)
// 返回 你想要完成在给定的列表 days 中列出的每一天的旅行所需要的最低消费
// 测试链接 : https://leetcode.cn/problems/minimum-cost-for-tickets/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//* 纯暴力递归 会超时
class Solution {
private:
   vector<int> duration;
public:
   Solution():duration([](){
      vector<int> m(3,0);
      m[0] = 1;
      m[1] = 7;
      m[2] = 30;
      return m;
   }()){}
   int mincostTickets(vector<int>& days, vector<int>& costs) {
      return f(days,costs,0);
   }

   //* 返回至少需要的钱数
   int f(vector<int>& days,vector<int>& costs, int n){
      if( n == days.size() ){
         return 0;
      }
      int ans = INT_MAX;
      for(int i = 0,j; i < 3; i++){
         j = n;
         while(j < days.size() && days[n] + duration[i] > days[j]){
            j++;
         }
         ans = min(ans, costs[i] + f(days,costs,j));
      }
      return ans;
   }
};


//* 可以通过
class Solution {
   private:
      vector<int> duration;
      unordered_map<int,int> map;
   public:
      Solution():duration([](){
         vector<int> m(3,0);
         m[0] = 1;
         m[1] = 7;
         m[2] = 30;
         return m;
      }()){}
      int mincostTickets(vector<int>& days, vector<int>& costs) {
         return f(days,costs,0);
      }
   
      //* 返回至少需要的钱数
      int f(vector<int>& days,vector<int>& costs, int n){
         if( n == days.size() ){
            return 0;
         }
         if( map.find(n) != map.end()){
            return map[n];
         }
         int ans = INT_MAX;
         for(int i = 0,j; i < 3; i++){
            j = n;
            while(j < days.size() && days[n] + duration[i] > days[j]){
               j++;
            }
            ans = min(ans, costs[i] + f(days,costs,j));
            map[n] = ans;
         }
         return ans;
      }
   };
   