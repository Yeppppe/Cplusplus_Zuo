// 替换子串得到平衡字符串
// 有一个只含有 'Q', 'W', 'E', 'R' 四种字符，且长度为 n 的字符串。
// 假如在该字符串中，这四个字符都恰好出现 n/4 次，那么它就是一个「平衡字符串」。
// 给你一个这样的字符串 s，请通过「替换一个子串」的方式，使原字符串 s 变成一个「平衡字符串」。
// 你可以用和「待替换子串」长度相同的 任何 其他字符串来完成替换。
// 请返回待替换子串的最小可能长度。
// 如果原字符串自身就是一个平衡字符串，则返回 0。
// 测试链接 : https://leetcode.cn/problems/replace-the-substring-for-balanced-string/


#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
   int balancedString(string s) {
      vector<int> st(4,0);
      vector<int> cnt(4,0);
      //统计词频
      for(auto str1 : s){
         int index = str1 == 'Q' ? 0 :(str1 == 'W' ? 1 : (str1 == 'E' ? 2 : 3));
         st[index]++;
      }

      int req = s.size()/4;
      int debt = 0;

      //* 找到欠几个
      for(int i =0;i<4;i++){
         if(st[i] > req){
            cnt[i] = req - st[i];
            debt -= cnt[i];
         }
      }
      if(debt == 0) return 0;

      int ans = s.size();
      for(int l=0,r=0; r < s.size();r++){
         int index = s[r] == 'Q' ? 0 :(s[r] == 'W' ? 1 : (s[r] == 'E' ? 2 : 3));
         if(cnt[index]++ < 0){
            debt--;
         }
         if(debt == 0){
            ans = min(ans,r-l+1);
            while(l<r){
               int indexl = s[l] == 'Q' ? 0 :(s[l] == 'W' ? 1 : (s[l] == 'E' ? 2 : 3));
               if(cnt[indexl] > 0){
                  cnt[indexl]--;
                  l++;
                  ans = min(ans,r-l+1);
               }
               else break;
            }
            
         }
      }
      return ans;
   }
};