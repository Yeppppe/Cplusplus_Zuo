// https://leetcode.cn/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int, int>> ans;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n ; j++){
                if(matrix[i][j] == 0){
                    ans.push_back(pair(i, j));
                }
            }
        }
        for(auto p : ans){
            for(int i = 0; i < m; i++){
                matrix[i][p.second] = 0;
            }
            for(int j = 0; j < n; j++){
                matrix[p.first][j] = 0;
            }
        }
    }
};