// https://leetcode.cn/problems/reverse-words-in-a-string/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
   string reverseWords(string s) {
      int n = s.size();
      int left = 0,right = n - 1;
      while(left <= right && s[left] == ' ') left++;
      while(left <= right && s[right] == ' ') right--;
      string cur;
      vector<string> ans;
      for(int i = left; i <= right; i++){
         if(s[i] == ' '){
            ans.push_back(cur);
            cur = "";
            while(s[i + 1] == ' '){
               i++;
            }
         }
         else{
            cur += s[i];
         }
      }
      ans.push_back(cur);

      string final;
      for(int i = ans.size() - 1; i >= 1; i--){
         final += ans[i];
         final += " ";
      }
      final += ans[0];
      return final;
   }
};

