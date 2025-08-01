// 岛屿数量
// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成
// 此外，你可以假设该网格的四条边均被水包围
// 测试链接 : https://leetcode.cn/problems/number-of-islands/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
vector<int> father;
int col;
int row;
int set;
public:
   int numIslands(vector<vector<char>>& grid) {
      build(grid);
      for(int i = 0; i < row; i++){
         for(int j = 0; j < col ; j++){
            if(grid[i][j] == '1'){
               if(j > 0 && grid[i][j-1] == '1'){
                  Union(index(i,j),index(i,j-1));
               }
               if(i > 0 && grid[i-1][j] == '1'){
                  Union(index(i,j),index(i - 1,j));
               }
            }            
         }
      }
      return set;
   }

   int index(int i, int j){
      return i * col + j;
   }
   void build(vector<vector<char>>& grid){
      row = grid.size();
      col = grid[0].size();
      set = 0;
      father.resize(row*col+1,0);
      for(int i = 0; i < row; i++){
         for(int j = 0; j < col; j++){
            if(grid[i][j] == '1'){
               father[index(i,j)] = index(i,j);
               set++;
            }
         }
      }
   }

   int find(int i){
      if(i != father[i]){
         father[i] = find(father[i]);
      }
      return father[i];
   }

   void Union(int a, int b){
      int fa = find(a);
      int fb = find(b);
      if(fa != fb){
         father[fa] = fb;    //* 这个地方写fb 或 father[fb] 都对 ，但是fb的时间更短
         set--;
      }
   }
};