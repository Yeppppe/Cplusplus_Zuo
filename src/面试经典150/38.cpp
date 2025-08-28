// https://leetcode.cn/problems/rotate-image/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
   void rotate(vector<vector<int>>& matrix) {
      int n = matrix.size();
      vector<vector<int>> copy(matrix);
      for(int i = 0; i < n; i++){
         for(int j = 0; j < n; j++){
            matrix[i][j] = copy[n - 1 -j][i];
         }
      }
      return;
   }
};