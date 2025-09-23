// https://leetcode.cn/problems/rotate-image/description/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> tmp(matrix);
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] = tmp[n - j - 1][i];
            }
        }
    }
};