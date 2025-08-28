// https://leetcode.cn/problems/isomorphic-strings/description/?envType=study-plan-v2&envId=top-interview-150


#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
   bool isIsomorphic(string s, string t) {
      unordered_map<char,char> s2t;
      unordered_map<char,char> t2s;
      int n = s.length();
      for(int i = 0; i < n; i++){
         if((s2t.count(s[i]) && s2t[s[i]] != t[i]) || (t2s.count(t[i]) && t2s[t[i]] != s[i]))
            return false;
         s2t[s[i]] = t[i];
         t2s[t[i]] = s[i];
      }
      return true;
   }
};

