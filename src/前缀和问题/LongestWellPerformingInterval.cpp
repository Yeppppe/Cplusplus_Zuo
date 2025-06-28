// 表现良好的最长时间段
// 给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数
// 我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是 劳累的一天
// 所谓 表现良好的时间段 ，意味在这段时间内，「劳累的天数」是严格 大于 不劳累的天数
// 请你返回 表现良好时间段 的最大长度
// 测试链接 : https://leetcode.cn/problems/longest-well-performing-interval/


// 解题思路
// 问题转化：
// 将 > 8 小时的天记为 +1
// 将 ≤ 8 小时的天记为 -1
// 问题变成：找到最长的子数组，其元素和为正数
// 前缀和 + 哈希表：
// 使用前缀和记录从开始到当前位置的累计和
// 使用哈希表记录每个前缀和第一次出现的位置
// 对于每个位置i，检查两种情况：
// 如果当前前缀和 > 0，则从开始到当前位置的整个数组是一个有效解
// 如果当前前缀和 ≤ 0，查找是否存在前缀和为sum-1的位置j，如果存在，则j+1到i是一个有效解
// 为什么检查sum-1：
// 如果在位置j的前缀和是sum-1，那么从j+1到i的子数组和为：sum - (sum-1) = 1
// 子数组和为正数，满足条件

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
   int longestWPI(vector<int>& hours) {
      int ans = 0;
      int sum = 0;
      unordered_map<int , int> map;
      map[0] = -1;
      for(int i = 0;i < hours.size(); i++){
         hours[i] = hours[i] > 8 ? 1 : -1;
         sum = sum+hours[i];
         if(sum > 0)
            ans = max(ans, i - map[0]); // 因为map[0]=-1，所以实际是i+1
         else{
            if(map.find(sum-1) != map.end()){
               ans = max(ans, i - map[sum-1]);
            }
         }
         if(map.find(sum) == map.end()) map[sum] = i;
      }
      return ans;
   }
};
