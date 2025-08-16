// 火星词典
// 现有一种使用英语字母的火星语言
// 这门语言的字母顺序对你来说是未知的。
// 给你一个来自这种外星语言字典的字符串列表 words
// words 中的字符串已经 按这门新语言的字母顺序进行了排序 。
// 如果这种说法是错误的，并且给出的 words 不能对应任何字母的顺序，则返回 ""
// 否则，返回一个按新语言规则的 字典递增顺序 排序的独特字符串
// 如果有多个解决方案，则返回其中任意一个
// words中的单词一定都是小写英文字母组成的
// 测试链接 : https://leetcode.cn/problems/alien-dictionary/
// 测试链接(不需要会员) : https://leetcode.cn/problems/Jf1JuT/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
   string alienOrder(vector<string>& words) {
      vector<int> indegree(26, -1);
      for(auto str : words){
         for(auto c : str){
            indegree[c - 'a'] = 0;
         }
      }
      vector<vector<int>> graph(26);
      for(int i = 0; i < words.size() - 1; i++){
         string cur = words[i];
         string next = words[i+1];
         int len = min(cur.size(),next.size());
         int j = 0;
         while(j < len){
            if(cur[j] != next[j]){
               graph[cur[j] - 'a'].push_back(next[j] - 'a');
               indegree[next[j] - 'a']++;                                      //! 在这里就直接统计入度节点
               break;                                                          //! 这个地方要break
            }
            j++;
         }
         if(j < cur.size() && j == next.size()) return "";
      }
      int kind = 0;
      queue<int> q;
      for(int i = 0; i < 26; i++){
         if(indegree[i] != -1){
            kind++;
         }
         if(indegree[i] == 0){
            q.push(i);
         }
      }
      string ans;
      while(!q.empty()){
         int cur = q.front();
         q.pop();
         ans += char(cur + 'a');
         for(auto n : graph[cur]){
            if(--indegree[n] == 0){
               q.push(n);
            }
         }
      }
      return ans.size() == kind ? ans : "";
   }
};