// 参加会议的最多员工数
// 一个公司准备组织一场会议，邀请名单上有 n 位员工
// 公司准备了一张 圆形 的桌子，可以坐下 任意数目 的员工
// 员工编号为 0 到 n - 1 。每位员工都有一位 喜欢 的员工
// 每位员工 当且仅当 他被安排在喜欢员工的旁边，他才会参加会议
// 每位员工喜欢的员工 不会 是他自己。给你一个下标从 0 开始的整数数组 favorite
// 其中 favorite[i] 表示第 i 位员工喜欢的员工。请你返回参加会议的 最多员工数目
// 测试链接 : https://leetcode.cn/problems/maximum-employees-to-be-invited-to-a-meeting/

//! 这个代码要多看下
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
   int maximumInvitations(vector<int>& favorite) {
      int n = favorite.size();
      vector<int> indegree(n);
      for(int i = 0; i < n; i++){
         indegree[favorite[i]]++;
      }
      queue<int> q;
      for(int i = 0; i < n; i++){
         if(indegree[i] == 0){
            q.push(i);
         }
      }

      //* 删除所有非环状节点
      vector<int> deep(n , 0);    //deep[i]不包括i在内之前的最长的链
      while(!q.empty()){
         int cur = q.front(); 
         int next = favorite[cur];
         q.pop();
         deep[next] = max(deep[next],deep[cur] + 1);
         if(--indegree[favorite[cur]] == 0){
            q.push(favorite[cur]);
         }
      }

      int sumofsmall = 0;
      int bigRings = 0;
      for(int i = 0; i < n; i++){
         if(indegree[i] > 0){
            int ringsize = 1;
            indegree[i] = 0;
            for(int j = favorite[i]; j != i; j = favorite[j]){
               ringsize++;
               indegree[j] = 0;
            }

            if(ringsize == 2){
               sumofsmall += 2 + deep[i] + deep[favorite[i]];
            }
            else{
               bigRings = max(bigRings , ringsize);
            }
         }
      }
      return max(bigRings,sumofsmall);
   }
};

