// 丑数 II
// 给你一个整数 n ，请你找出并返回第 n 个 丑数
// 丑数 就是只包含质因数 2、3 或 5 的正整数
// 测试链接 : https://leetcode.cn/problems/ugly-number-ii/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
   int nthUglyNumber(int n) {
      if(n == 1) return 1;
      if(n == 2) return 2;
      if(n == 3) return 3;
      vector<int> dp(n + 1);
      dp[1] = 1;
      for(int i = 2, i2 = 1,i3 = 1,i5 = 1,cur,a,b,c; i <= n;){
         a = dp[i2] * 2;
         b = dp[i3] * 3;
         c = dp[i5] * 5;
         cur = min(c,min(a,b));
         if(cur == a){
            i2++;
         }
         if(cur == b){
            i3++;
         }
         if(cur == c){
            i5++;
         }
         dp[i++] = cur;
      }
      return dp[n];
   }
};