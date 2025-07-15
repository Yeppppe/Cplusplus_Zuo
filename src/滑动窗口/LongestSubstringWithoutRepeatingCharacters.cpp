// 无重复字符的最长子串
// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
// 测试链接 : https://leetcode.cn/problems/longest-substring-without-repeating-characters/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
   int lengthOfLongestSubstring(string s) {
      if(s.empty()) return 0;
      unordered_map<char,int> map;
      int ans = INT_MIN;
      for(int i = 0,l = 0,r = 0;i < s.size(); i++,r++){
         if(map.find(s[i]) != map.end()){
               l = max(l, map[s[r]] + 1); // 防止左指针回退
         }
         map[s[i]] = i;
         ans = max(ans,r-l+1);
      }
      return ans;
   }
};
