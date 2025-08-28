// https://leetcode.cn/problems/simplify-path/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
   string simplifyPath(string path) {
      int n = path.size();
      stack<string> stac;
      for(int i = 0; i < n; i++){
         string tmp;
         while(i <n && path[i] != '/'){
               tmp += path[i];
               i++;
         }
         if(!tmp.empty()){
               if(tmp == "."){
                  continue;
               }
               else if(!stac.empty() && tmp == ".."){
                  stac.pop();
               }
               else if(tmp == ".."){
                  continue;
               }
               else{
                  stac.push(tmp);
               }
         }
      }
      if(stac.empty()) return "/";
      string ans;
      stack<string> final;
      while(!stac.empty()){
         string cur = stac.top();
         final.push(cur);
         stac.pop();
      }
      while(!final.empty()){
         string cur = final.top();
         ans += '/' + cur;
         final.pop();
      }
      return ans;
   }
};
