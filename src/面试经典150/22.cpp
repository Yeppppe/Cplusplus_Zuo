// https://leetcode.cn/problems/zigzag-conversion/description/?envType=study-plan-v2&envId=top-interview-150
//! Z字形变换

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
   string convert(string s, int numRows) {
      if(numRows <= 1){                //! 注意这个边界条件
         return s;
      }
      vector<string> ans(numRows);
      int n = s.size();
      int flag = -1;
      int cur = 0;
      for(int i = 0; i < n; i++){
         ans[cur].push_back(s[i]);
         if(cur == 0 || cur == numRows - 1){            //! 转换条件不需要用i 直接用cur即可
            flag = -flag; 
         } 
         cur += flag;
      }
      string final;
      for(int i = 0; i < numRows; i++){
         for(int j = 0; j < ans[i].size(); j++){
            final += ans[i][j];
         }
      }
      return final;
   }
};