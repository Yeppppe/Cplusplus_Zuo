// 找出知晓秘密的所有专家
// 给你一个整数 n ，表示有 n 个专家从 0 到 n - 1 编号
// 另外给你一个下标从 0 开始的二维整数数组 meetings
// 其中 meetings[i] = [xi, yi, timei] 表示专家 xi 和专家 yi 在时间 timei 要开一场会
// 一个专家可以同时参加 多场会议 。最后，给你一个整数 firstPerson
// 专家 0 有一个 秘密 ，最初，他在时间 0 将这个秘密分享给了专家 firstPerson
// 接着，这个秘密会在每次有知晓这个秘密的专家参加会议时进行传播
// 更正式的表达是，每次会议，如果专家 xi 在时间 timei 时知晓这个秘密
// 那么他将会与专家 yi 分享这个秘密，反之亦然。秘密共享是 瞬时发生 的
// 也就是说，在同一时间，一个专家不光可以接收到秘密，还能在其他会议上与其他专家分享
// 在所有会议都结束之后，返回所有知晓这个秘密的专家列表
// 你可以按 任何顺序 返回答案
// 链接测试 : https://leetcode.cn/problems/find-all-people-with-secret/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//!  勉强运行通过
class Solution {
private:
   vector<int> father;
   vector<bool> secret;
public:
   vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
      build(n,firstPerson);
      sort(meetings.begin(),meetings.end(),[](const vector<int> a, const vector<int> b){
         return a[2] < b[2];
      });
      int r = 0;

      //! 这里面找的是 meet[r] != meet[l]的最后一个，不需要使用r++是的r-1索引是与l相同的最后一个，可以先用r+1作为判断，使用r作为索引，只要保证r+1索引访问不越界即可，循环逻辑更好写
      int m = meetings.size();
      for(int l=0;l < m;){
         r = l;
         while(r + 1 < m){
            if(meetings[r + 1][2] == meetings[l][2])
               r++;
            else break;
         }
         for(int i = l; i <= r; i++){
            int a = meetings[i][0];
            int b = meetings[i][1];
            Union(a,b);
         }
         for(int i = l; i <= r; i++){
            int a = meetings[i][0];
            int b = meetings[i][1];
            if(secret[find(a)] == false){
               father[a] = a;
            }
            if(secret[find(b)] == false){
               father[b] = b;
            }
         }
         l = r + 1;
      }
      vector<int> ans;
      for(int i = 0; i < n; i++){
         if(secret[find(i)] == true)
            ans.push_back(i);
      }
      return ans;
   }
   void build(int n,int first){
      father.resize(n);
      secret.resize(n);
      for(int i = 0; i < n; i++){
         father[i] = i;
         secret[i] = false;
      }
      father[first] = 0;
      secret[0] = true;
      secret[first] = true;
   }

   int find(int a){
      if(a != father[a]){
         father[a] = find(father[a]);
      }
      return father[a];
   }

   void Union(int a, int b){
      int fa = find(a);
      int fb = find(b);
      if(fa != fb){
         father[fa] = fb;
         secret[fb] = secret[fb] | secret[fa];
      }
   }
};

