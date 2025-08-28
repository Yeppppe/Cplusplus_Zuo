
// https://leetcode.cn/problems/basic-calculator/description/?envType=study-plan-v2&envId=top-interview-150
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
class Solution {
public:
   int calculate(string s) {
      int n = s.size();
      int sign = 1;
      int ret = 0;
      stack<int> ops;
      ops.push(sign);
      for(int i = 0; i < n; i++){
         if(s[i] == ' '){
               continue;
         }
         else if(s[i] == '+'){
               sign = ops.top();
               continue;
         }
         else if(s[i] == '-'){
               sign = -ops.top();
               continue;
         }
         else if(s[i] == '('){
               ops.push(sign);
               continue;
         }
         else if(s[i] == ')'){
               ops.pop();
               continue;
         }
         else{
               long num = 0;
               while(i < n && s[i] >= '0' && s[i] <= '9'){
                  num = num*10 + s[i] - '0';
                  i++;
               }
               ret += sign*num;
               i--;
         }
      }
      return ret;
   }
};
