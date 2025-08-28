// https://leetcode.cn/problems/valid-anagram/?envType=study-plan-v2&envId=top-interview-150


#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
   bool isAnagram(string s, string t) {
      vector<int> ans(26,0);
      int sn = s.size();
      int tn = t.size();
      if(sn != tn) return false;
      for(int i = 0; i < sn; i++){
         ans[s[i] - 'a']++;
         ans[t[i] - 'a']--;
      }
      for(auto a : ans){
         if(a != 0) return false;
      }
      return true;
   }
};