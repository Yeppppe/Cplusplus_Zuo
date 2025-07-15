// 最小覆盖子串
// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串
// 如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
// 测试链接 : https://leetcode.cn/problems/minimum-window-substring/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
   string minWindow(string s, string t) {
      if(s.size() < t.size()){
         return "";
      }
      vector<int> cnt(256,0);
      int debt = 0;
      for(auto tar : t){
         cnt[tar]--;
         debt--;
      }
      int len = INT_MAX;
      int start = 0;
      for(int l=0,r=0;r<s.size();r++){
         if(cnt[s[r]]++ < 0){
            debt++;
         }
         if(debt == 0){
            while(cnt[s[l]] > 0){       //! 注意这里判断的是 cnt[s[l]]
               cnt[s[l++]]--;   
            }
         
            if(r-l+1 < len){
               len = r - l +1;
               start = l;
            }
         }
      }
      return len == INT_MAX ? "" : s.substr(start, len);
   }
};

