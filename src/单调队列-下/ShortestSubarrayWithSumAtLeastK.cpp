// 和至少为K的最短子数组
// 给定一个数组arr，其中的值有可能正、负、0
// 给定一个正数k
// 返回累加和>=k的所有子数组中，最短的子数组长度
// 测试链接 : https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 尝试暴力解法，可能会超时
// 84 / 98 个通过的测试用例   确实超时了
class Solution {
public:
   int shortestSubarray(vector<int>& nums, int k) {
      int n = nums.size();
      int sum = 0;
      int ans = INT_MAX;
      for(int l = 0, r = 0; l < n;l++){
         r = l;
         sum = 0;
         while(r < n){
            if(sum >= k)
               break;
            sum += nums[r++];
         }
         if(sum >= k)
            ans = min(ans, r - l);
      }
      return ans!=INT_MAX ? ans : -1;
   }
};


//* 先构建前缀和，再使用单调栈
class Solution {
public:
   int shortestSubarray(vector<int>& nums, int k) {
      int n = nums.size();
      vector<long long> sum(n+1,0);
      for(int i = 0;i < n; i++){
         sum[i+1] = sum[i] + nums[i];
      }
      int h = 0;
      int t = 0;
      int ans = INT_MAX;
      vector<int> stack(n+1);
      //* 新进来遍历的每一个数字，先去单调栈中找最小的，如果成立，不断记录长度并弹出最小值，之后进入单调队列，单调队列 小在前，大在后
      for(int i = 0; i <= n; i++){
         while(h < t &&sum[i] - sum[stack[h]] >= k){
            ans = min(ans , i - stack[h++]);
         }
         while(h < t && sum[stack[t - 1]] >= sum[i]){
            t--;
         }
         stack[t++] = i;
      }
      return ans == INT_MAX ? -1 : ans;
   }
};