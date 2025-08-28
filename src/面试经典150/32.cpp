// https://leetcode.cn/problems/longest-substring-without-repeating-characters/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
   int lengthOfLongestSubstring(string s) {
      if(s.empty()) return 0;
      int n = s.size();
      int ans = 0;
      int count;
      for(int j = 0; j < n; j++){
         count = 0;
         set<char> set;
         for(int i = j; i < n; i++){
            if(set.count(s[i]) == 0){
               set.insert(s[i]);
               count++;
               ans = max(ans, count);            //! 能够处理空字符串，但是整体效率十分低
            }
            else{
               ans = max(ans, count);
               break;
            }
         }
      }
      return ans;
   }
};



class Solution {
public:
   int lengthOfLongestSubstring(string s) {
      int n = s.size();
      unordered_map<char, int> map;
      int ans = 0;
      for(int l = 0, r = 0; r < n;r++){
         if(map.find(s[r]) != map.end() && map[s[r]] >= l){    //! 在窗口内有重复字符才会进行l的更新
            l = map[s[r]] + 1;
         }
         map[s[r]] = r;
         ans = max(ans, r - l + 1);
      }
      return ans;
   }
};