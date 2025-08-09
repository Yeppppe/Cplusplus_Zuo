// 被围绕的区域
// 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域
// 并将这些区域里所有的 'O' 用 'X' 填充。
// 测试链接 : https://leetcode.cn/problems/surrounded-regions/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   void solve(vector<vector<char>>& board) {
      for(int j = 0; j < board[0].size(); j++){
         if(board[0][j] == 'O'){
            dfs(board , 0 , j , 'E');
         }
         if(board[board.size() - 1][j] == 'O'){
            dfs(board , board.size()-1 , j , 'E');
         }
      }

      for(int i = 0; i < board.size(); i++){
         if(board[i][0] == 'O'){
            dfs(board, i , 0, 'E');
         }
         if(board[i][board[0].size()-1] == 'O'){
            dfs(board , i, board[0].size()-1, 'E');
         }
      }
      int ans = 0;
      for(int i = 1; i < board.size()-1; i++){
         for(int j = 1 ; j < board[0].size() -1; j++){
            if(board[i][j] == 'O'){
               dfs(board, i , j , 'X');
            }
         }
      }
      for(int i = 0; i < board.size(); i++){
         for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] == 'E'){
               board[i][j] = 'O';
            }
         }
      }
   }

   void dfs(vector<vector<char>>& board, int i, int j, char place){
      if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O'){
         return;
      }
      board[i][j] = place;
      dfs(board, i - 1, j , place);
      dfs(board, i + 1, j , place);
      dfs(board, i , j - 1 , place);
      dfs(board, i , j + 1, place);
   }
};

