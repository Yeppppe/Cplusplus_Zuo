// https://leetcode.cn/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
   bool isSubsequence(string s, string t) {
      int n = t.size();
      int m = s.size();
      int count = 0;
      for(int i = 0; i < n; i++){
         if(s[count] == t[i]){
            count++;
         }
         if(count == m) break;
      }
      return count == m ? true : false;
   }
};