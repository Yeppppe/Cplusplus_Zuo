// https://leetcode.cn/problems/valid-sudoku/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   bool isValidSudoku(vector<vector<char>>& board) {
      //* 每一行
      for(int i = 0; i < 9; i++){
         vector<int> count(9,0);
         for(int j = 0; j < 9; j++){
            if(board[i][j] != '.'){
               if(++count[board[i][j] - '0' - 1] > 1)
                  return false;
            }
         }
      }

      for(int i = 0; i < 9; i++){
         vector<int> count(9,0);
         for(int j = 0; j < 9; j++){
            if(board[j][i] != '.'){
               if(++count[board[j][i] - '0' - 1] > 1)
                  return false;
            }
         }
      }

      for(int i = 0; i < 9; i+=3){
         for(int j = 0; j < 9; j+=3){
            vector<int> count(9,0);
            for(int m = i; m < i + 3; m++){
               for(int n = j; n < j + 3; n++){
                  if(board[m][n] != '.'){
                     if(++count[board[m][n] - '0' - 1] > 1)
                        return false;
                  }
               }
            }
         }
      }
      return true;
   }
};

