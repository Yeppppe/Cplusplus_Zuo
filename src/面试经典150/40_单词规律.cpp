// https://leetcode.cn/problems/word-pattern/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
   bool wordPattern(string pattern, string s) {
      vector<char> pa;
      vector<string> ss;
      unordered_map<char,string> c2s;
      unordered_map<string,char> s2c;
      for(auto s : pattern){
         pa.push_back(s);
      }
      int n = s.size();
      string tmp;
      for(int i = 0; i < n; i++){
         if(s[i] == ' '){
            ss.push_back(tmp);
            tmp.clear();
         }
         else{
            tmp += s[i];
         }
         if(i == n - 1){
            ss.push_back(tmp);
         }
      }
      if(pa.size() != ss.size()) return false;
      int pn = pa.size();
      for(int i = 0; i < pn; i++){
         if((c2s.count(pa[i]) && c2s[pa[i]] != ss[i]) || (s2c.count(ss[i]) && s2c[ss[i]] != pa[i])){
            return false;
         }
         else{
            c2s[pa[i]] = ss[i];
            s2c[ss[i]] = pa[i];
         }
      }
      return true;
   }
};

