// 环绕字符串中唯一的子字符串
// 定义字符串 base 为一个 "abcdefghijklmnopqrstuvwxyz" 无限环绕的字符串
// 所以 base 看起来是这样的：
// "..zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd.."
// 给你一个字符串 s ，请你统计并返回 s 中有多少 不同非空子串 也在 base 中出现
// 测试链接 : https://leetcode.cn/problems/unique-substrings-in-wraparound-string/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
   int findSubstringInWraproundString(string s) {
      vector<int> dp(26,0);
      int n = s.size();
      dp[s[0] - 'a'] = 1;
      int len = 1;
      for(int i = 1; i < n; i++){

         int cur = s[i] - 'a';
         int pre = s[i - 1] - 'a';
         if((pre == 25 && cur == 0) || cur == pre + 1){
            len++;                //! 这里不能直接简单的用 len = dp[pre] + 1代替，因为有可能上一个不连续，但是调用了历史中dp该字符的最大值
         }
         else{
            len = 1;
         }
         dp[cur] = max(len,dp[cur]);
      }
      int ans = 0;
      for(auto d : dp){
         ans += d != 0 ? d : 0;
      }
      return ans;
   }
};