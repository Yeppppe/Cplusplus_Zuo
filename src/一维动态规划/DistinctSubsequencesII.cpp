// 不同的子序列 II
// 给定一个字符串 s，计算 s 的 不同非空子序列 的个数
// 因为结果可能很大，所以返回答案需要对 10^9 + 7 取余
// 字符串的 子序列 是经由原字符串删除一些（也可能不删除）
// 字符但不改变剩余字符相对位置的一个新字符串
// 例如，"ace" 是 "abcde" 的一个子序列，但 "aec" 不是
// 测试链接 : https://leetcode.cn/problems/distinct-subsequences-ii/

//!
// 纯新 = all - 当前字符上一次的结果
// 当前字符结果 += 纯新
// all += 纯新

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
   int distinctSubseqII(string s) {
      vector<int> dp(26,0);
      int mod = 1000000007;
      int all = 1;
      for(auto st : s){
         int newAdd = (all - dp[st - 'a'] + mod) %mod;
         dp[st - 'a'] = (newAdd + dp[st - 'a']) % mod;
         all =(all + newAdd)%mod;
      }
      return (all - 1 + mod) % mod;
   }
};