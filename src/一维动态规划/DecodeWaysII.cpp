// 解码方法 II
// 一条包含字母 A-Z 的消息通过以下的方式进行了 编码 ：
// 'A' -> "1"
// 'B' -> "2"
// ...
// 'Z' -> "26"
// 要 解码 一条已编码的消息，所有的数字都必须分组
// 然后按原来的编码方案反向映射回字母（可能存在多种方式）
// 例如，"11106" 可以映射为："AAJF"、"KJF"
// 注意，像 (1 11 06) 这样的分组是无效的，"06"不可以映射为'F'
// 除了上面描述的数字字母映射方案，编码消息中可能包含 '*' 字符
// 可以表示从 '1' 到 '9' 的任一数字（不包括 '0'）
// 例如，"1*" 可以表示 "11"、"12"、"13"、"14"、"15"、"16"、"17"、"18" 或 "19"
// 对 "1*" 进行解码，相当于解码该字符串可以表示的任何编码消息
// 给你一个字符串 s ，由数字和 '*' 字符组成，返回 解码 该字符串的方法 数目
// 由于答案数目可能非常大，返回10^9 + 7的模
// 测试链接 : https://leetcode.cn/problems/decode-ways-ii/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
   vector<long long> dp;
   static const int MOD = 1000000007;
public:
   int numDecodings(string s) {
      dp.resize(s.size());
      for(int i = 0 ; i < s.size(); i++){
         dp[i] = -1;
      }
      return f(s,0);
   }
   long long f(const string& s, int i){
      if(i == s.size()){
         return 1;
      }
      if(dp[i] != -1){
         return dp[i];
      }
      long long ans;
      if(s[i] == '0') ans=0;
      else{
         ans = f(s, i + 1) * (s[i] == '*' ? 9 : 1);;
         if(i + 1 < s.size()){
            //* 1_
            if(s[i] != '*'){
               if(s[i+1] != '*'){
                  if ((s[i] - '0') * 10 + s[i + 1] - '0' <= 26) {
                     ans += f(s, i + 2);
                  }
               }
               else{
                  if(s[i] == '1') ans += 9*f(s,i+2);
                  if(s[i] == '2') ans += 6*f(s,i+2);
               }
            }
            //*  *1
            else{
               if(s[i+1] != '*'){
                  if(s[i+1] - '0' <= 6) ans += 2*f(s,i+2);
                  else ans += f(s,i+2);
               }
               else{
                  ans += 15*f(s,i+2);
               }
            }
         }
      }
      ans = ans%MOD;
      dp[i] = ans;
      return ans;
   }
};

