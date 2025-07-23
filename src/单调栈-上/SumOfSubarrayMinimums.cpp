// 子数组的最小值之和
// 给定一个整数数组 arr，找到 min(b) 的总和，其中 b 的范围为 arr 的每个（连续）子数组。
// 由于答案可能很大，因此 返回答案模 10^9 + 7
// 测试链接 : https://leetcode.cn/problems/sum-of-subarray-minimums/

#include <iostream>
#include <vector>
using namespace std;

//! 同余原理
/// 加法同余：(a + b)%m = ((a%m) + (b%m)) % m
/// 减法同余：(a - b)%m = ((a%m) - (b%m) + m) % m
/// 乘法同余：（a * b)%m = ((a%m)*(b%m)) % m
class Solution {
public:
   int sumSubarrayMins(vector<int>& arr) {
      int n = arr.size();
      const int mod = 1000000007;
      vector<int> stack;    //* 一开始要初始化一个空栈
      long cur;
      long long ans = 0;
      long left = -1;
      for(int i = 0; i < n; i++){
         while(!stack.empty() && arr[i] <= arr[stack.back()]){
            cur = stack.back();
            stack.pop_back();
            left = !stack.empty() ? stack.back() : -1;
            ans = (long long)(ans + (cur - left)*(i - cur)*arr[cur]% mod) % mod;
         }
         stack.push_back(i);
      }
      while(!stack.empty()){
         long cur = stack.back();
         stack.pop_back();
         long left = stack.empty() ? -1 : stack.back();
         ans = (long long)(ans + (cur - left)*(n - cur)*arr[cur]% mod) % mod;
      }
      return ans;
   }
};