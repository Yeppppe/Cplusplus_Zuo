// 移除最多的同行或同列石头
// n 块石头放置在二维平面中的一些整数坐标点上。每个坐标点上最多只能有一块石头
// 如果一块石头的 同行或者同列 上有其他石头存在，那么就可以移除这块石头
// 给你一个长度为 n 的数组 stones ，其中 stones[i] = [xi, yi] 表示第 i 块石头的位置
// 返回 可以移除的石子 的最大数量。
// 测试链接 : https://leetcode.cn/problems/most-stones-removed-with-same-row-or-column/



#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
private:
   vector<int> father;
   int set;
public:
   int removeStones(vector<vector<int>>& stones) {
      unordered_map<int,int> rowmap,colmap;
      int row,col;
      int n = stones.size();
      build(n);
      for(int i = 0; i < n; i++){
         row = stones[i][0];
         col = stones[i][1];
         if(rowmap.find(row) != rowmap.end()){
            Union(i,rowmap[row]);
         }
         else{
            rowmap[row] = i;     //! 添加到hashmap中的应该是石头的索引，而不是行列号本身
         }
         if(colmap.find(col) != colmap.end()){
            Union(i,colmap[col]);
         }
         else{
            colmap[col] = i;
         }
      }
      return n - set;
   }
   void build(int n){
      father.resize(n);
      set = n;
      for(int i = 0; i < n; i++){
         father[i] = i;
      }
   }

   int Find(int a){
      if(a != father[a]){
         father[a] = Find(father[a]);
      }
      return father[a];
   }

   void Union(int a, int b){
      int fa = Find(a);
      int fb = Find(b);
      if(fa != fb){
         father[fa] = fb;
         set--;
      }
   }
};
