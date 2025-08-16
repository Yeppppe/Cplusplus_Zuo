// 戳印序列
// 你想最终得到"abcbc"，认为初始序列为"?????"。印章是"abc"
// 那么可以先用印章盖出"??abc"的状态，
// 然后用印章最左字符和序列的0位置对齐，就盖出了"abcbc"
// 这个过程中，"??abc"中的a字符，被印章中的c字符覆盖了
// 每次盖章的时候，印章必须完全盖在序列内
// 给定一个字符串target是最终的目标，长度为n，认为初始序列为n个'?'
// 给定一个印章字符串stamp，目标是最终盖出target
// 但是印章的使用次数必须在10*n次以内
// 返回一个数组，该数组由每个回合中被印下的最左边字母的索引组成
// 上面的例子返回[2,0]，表示印章最左字符依次和序列2位置、序列0位置对齐盖下去，就得到了target
// 如果不能在10*n次内印出序列，就返回一个空数组
// 测试链接 : https://leetcode.cn/problems/stamping-the-sequence/

#include <vector>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
   vector<int> movesToStamp(string stamp, string target) {
      int m = stamp.size();
      int n = target.size();
      vector<int> indegree(n - m + 1,m);                //! indegree代表以每个节点作为开头有多少个错误的，如果没有错误的直接进队列，但是最后需要逆序
      vector<vector<int>> graph(n);
      queue<int> q;
      for(int i = 0; i < n - m + 1; i++){
         for(int j = 0; j < m; j++){
            if(stamp[j] == target[i+j]){
               if(--indegree[i] == 0){
                  q.push(i);
               }
            }
            else{
               graph[i+j].push_back(i);
            }
         }
      }

      vector<int> ans;
      vector<bool> visited(n,false);
      while(!q.empty()){
         int cur = q.front();
         q.pop();
         ans.push_back(cur);
         for(int i = cur; i < cur + m; i++){
            if(!visited[i]){
               visited[i] = true;
               for(auto n : graph[i]){                           //! 验证过的不能重复进行验证！
                  if(--indegree[n] == 0){
                     q.push(n);
                  }
               }
            }
         }
      }
      if(ans.size() != n - m + 1) return {};
      vector<int> fina_ans(n-m+1);
      for(int i = 0; i < n-m+1; i++){
         fina_ans[n-m-i] = ans[i];
      }
      return fina_ans;
   }
};