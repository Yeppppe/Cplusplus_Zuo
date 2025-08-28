// https://leetcode.cn/problems/minimum-window-substring/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
private:
   unordered_map<char, int> ori,win;
   bool check(){
      for(auto p : ori){
         if(win[p.first] < p.second)
            return false;
      }
      return true;
   }
public:
   string minWindow(string s, string t) {
      for(auto c : t){
         ori[c]++;
      }
      
      int n = s.size();
      int l = 0, r = 0;
      int ansL = -1;
      int min_len = INT_MAX;
      while(r < n && l <= r){
         win[s[r]]++;
         r++;
         while(check() && l <= r){               
            if(r - l < min_len){             //! r++后的长度就单纯的是 r - l
               min_len = r - l;
               ansL = l;
            }
            win[s[l]]--;
            l++;
         }
      }
      return ansL == -1 ? "" : s.substr(ansL,min_len);
   }
};

