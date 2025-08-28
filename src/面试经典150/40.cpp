// https://leetcode.cn/problems/game-of-life/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
   vector<vector<int>> copy;
public:
   void gameOfLife(vector<vector<int>>& board) {
      int m = board.size();
      int n = board[0].size();
      //! copy.resize(m+2,n+2);  直接这样定义是有问题的
      copy.resize(m+2);  // 先调整外层向量大小
      for (int i = 0; i < m+2; ++i) {
         copy[i].resize(n+2);  // 再逐个调整内层向量大小
      }
      for(int i = 1; i <= m; i++){
         for(int j = 1; j <= n; j++){
            copy[i][j] = board[i -1][j - 1];
         }
      }
      for(int i = 0; i < m; i++){
         copy[i][0] = 2;
         copy[i][n+1] = 2;
      }
      for(int j = 0; j < n; j++){
         copy[0][j] = 2;
         copy[m + 1][j] = 2;
      }
      int alive, dead;
      for(int i = 0; i < m; i++){
         for(int j = 0; j < n; j++){
            count(copy,i + 1, j + 1, alive, dead);
            if(board[i][j] == 1){
               if(alive < 2){
                  board[i][j] = 0;
               }
               if(alive > 3){
                  board[i][j] = 0;
               }
            }
            else{
               if(alive == 3){
                  board[i][j] = 1;
               }
            }
         }
      }
   }
   
   void count(vector<vector<int>>& copy, int row, int col, int& alive, int& dead){
      int cur = copy[row][col];
      int a = 0;
      int d = 0;
      for(int i = row - 1; i <= row + 1; i++){
         for(int j = col - 1; j <= col + 1; j++){
            if(copy[i][j] == 1){
               a++;
            }
            else if(copy[i][j] == 0){
               d++;
            }
         }
      }
      alive = a;
      dead = d;
      if(copy[row][col] == 1) alive--;
      if(copy[row][col] == 0) dead--;
      return;
   }
};