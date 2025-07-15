// 至少有K个重复字符的最长子串
// 给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串
// 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度
// 如果不存在这样的子字符串，则返回 0。
// 测试链接 : https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
   int longestSubstring(string s, int k) {
      vector<int> cnt(256,0);
      int ans = 0;
      for(int i=1;i<=26;i++){
         fill(cnt.begin(), cnt.end(), 0); // 重置计数器
         for(int l=0,r=0,collect=0,satisfy=0;r<s.size();r++){
            cnt[s[r]]++;
            if(cnt[s[r]] == 1){
               collect++;
            }
            if(cnt[s[r]] == k){
               satisfy++;
            }
            while(collect > i){     //! 注意这里是collect不是satisfy
               if(cnt[s[l]] == 1){ 
                  collect--;
               }
               if(cnt[s[l]] == k){
                  satisfy--;
               }
               cnt[s[l++]]--;
            }
            if(satisfy == i){
               ans = max(ans,r-l+1);
            }
         }
      }
      return ans;
   }
};