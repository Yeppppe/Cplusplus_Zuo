// 使数组和能被P整除
// 给你一个正整数数组 nums，请你移除 最短 子数组（可以为 空）
// 使得剩余元素的 和 能被 p 整除。 不允许 将整个数组都移除。
// 请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 -1 。
// 子数组 定义为原数组中连续的一组元素。
// 测试链接 : https://leetcode.cn/problems/make-sum-divisible-by-p/


// 问题分析
// 核心目标：找到最短的连续子数组，移除后使剩余数组和能被p整除
// 数学转化：
// 设原数组总和为sum，总和对p的余数为mod (mod = sum % p)
// 如果mod为0，则不需要移除任何元素
// 否则，需要找到一个子数组，其和对p的余数为mod
// 解题思路
// 前缀和 + 同余定理：
// 计算整个数组的和对p的余数mod
// 如果mod为0，直接返回0（不需要移除任何元素）
// 否则，需要找到子数组，使其和对p的余数为mod
// 数学原理：
// 设前缀和为prefixSum，我们要找的子数组为[i+1...j]
// 要使移除这个子数组后剩余和能被p整除，需要满足：
// (prefixSum[j] - prefixSum[i]) % p = mod
// 等价于：prefixSum[j] % p = (prefixSum[i] + mod) % p
// 即：当前前缀和cur，需要找到之前出现过的前缀和find，满足(find + mod) % p = cur
// 哈希表优化：
// 使用哈希表记录每个前缀和余数最后出现的位置
// 对于当前位置i和前缀和余数cur，查找是否存在前缀和余数find，满足上述条件
// 如果存在，计算子数组长度并更新答案

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
   int minSubarray(vector<int>& nums, int p) {
      int mod = 0;
      for(auto num : nums){
         mod = (mod+num)%p;
      }
      if (mod == 0) return 0;
      unordered_map<int , int> map;
      map[0] = -1;
      int sum = 0;
      int ans = INT_MAX;
      int find = 0;
      int cur = 0;
      for(int i = 0;i < nums.size(); i++){
         cur = (cur+nums[i])%p;
         find = cur >= mod ? cur - mod : cur + p -mod;
         if(map.find(find) != map.end()){
            ans = min(ans , i - map[find]);
         }
         map[cur] = i;
      }
      return ans == nums.size() ? -1 : ans;
   }
};