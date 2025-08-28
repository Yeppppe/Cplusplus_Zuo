// https://leetcode.cn/problems/valid-parentheses/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
   bool isValid(string s) {
      int n = s.size();
      stack<char> stac;
      for(int i = 0; i < n; i++){
         if(s[i] == '(' || s[i] == '{' || s[i] == '['){
               stac.push(s[i]);
         }
         else{
               if(stac.empty()) return false;
               if(s[i] == ')' && stac.top() == '('){
                  stac.pop();
                  continue;
               }
               if(s[i] == '}' && stac.top() == '{'){
                  stac.pop();
                  continue;
               }
               if(s[i] == ']' && stac.top() == '['){
                  stac.pop();
                  continue;
               }
               stac.push(s[i]);
         }
      }
      return stac.empty() ? true : false;
   }
};
