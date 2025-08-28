
// https://leetcode.cn/problems/valid-palindrome/solutions/292148/yan-zheng-hui-wen-chuan-by-leetcode-solution/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
   bool isPalindrome(string s) {
      string ans;
      for(auto c : s){
         if((c >= 'a' && c <= 'z' )||(c >= 'A' && c <= 'Z') ||(c >= '0' && c <= '9')){
            ans += tolower(c);
         }
      }
      int n = ans.size();
      for(int i = 0; i < n/2; i++){
         if(ans[i] != ans[n - 1 - i]){
            return false;
         }
      }
      return true;
   }
};

   
