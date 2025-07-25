// 去除重复字母保证剩余字符串的字典序最小
// 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次
// 需保证 返回结果的字典序最小
// 要求不能打乱其他字符的相对位置
// 测试链接 : https://leetcode.cn/problems/remove-duplicate-letters/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   string removeDuplicateLetters(string s) {
      vector<int> store(26,0);
      vector<char> stack;
      stack.reserve(26);
      vector<bool> in_stack(26,false);
      for(auto c : s){
         store[c - 'a']++;
      }
      int n = s.size();
      for(int i = 0; i < n; i++){
         store[s[i] - 'a']--;
         if(in_stack[s[i] - 'a']){
            continue;
         }
         while(!stack.empty() && s[i] < stack.back() && store[stack.back() - 'a'] > 0){
            char cur = stack.back();
            stack.pop_back();
            in_stack[cur - 'a'] = false;
         }
         in_stack[s[i] - 'a'] = true;
         stack.push_back(s[i]);
      }
      string ans;
      for(auto sta : stack){
         ans += sta;
      }
      return ans;
   }
};