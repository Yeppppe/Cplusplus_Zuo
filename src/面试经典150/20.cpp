// https://leetcode.cn/problems/longest-common-prefix/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
   string longestCommonPrefix(vector<string>& strs) {
      int n = strs.size();
      string stand = strs[0];
      int first_size = strs[0].size();
      int count = 0;
      string ans;
      for(int i = 0; i < first_size; i++){
         count = 0;
         for(int j = 1; j < n; j++){
            if(stand[i] == strs[j][i]) count++;
         }
         if(count == n - 1){
            ans += stand[i];
         }
         else{
            break;
         }
      }
      return ans;
   }
};
   
   