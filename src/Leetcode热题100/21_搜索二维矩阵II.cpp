// https://leetcode.cn/problems/search-a-2d-matrix-ii/submissions/665287000/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0;
        int y = n - 1;
        while(x < m && y >= 0){
            if(matrix[x][y] == target) return true;
            if(matrix[x][y] < target){
                x++;
            }
            else{
                y--;
            }
        }
        return false;
    }
};