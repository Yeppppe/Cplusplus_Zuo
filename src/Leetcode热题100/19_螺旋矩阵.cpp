// https://leetcode.cn/problems/spiral-matrix/?envType=study-plan-v2&envId=top-100-liked
#include <vector>
using namespace std;

class Solution {
private:
    vector<pair<int, int>> direction;
public:
    Solution(){
        direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<int> ans;
        int i = 0;
        int j = 0;
        int next = 0;
        pair<int, int> dir = direction[next];
        int count = m * n;
        while(count--){
            ans.push_back(matrix[i][j]);
            vis[i][j] = true;

            int ni = i + dir.first;
            int nj = j + dir.second;

            if(ni < 0 || ni >= m || nj < 0 || nj >= n || vis[ni][nj] == true){
                dir = direction[(++next)%4];
                ni = i + dir.first;
                nj = j + dir.second;
            }
            i = ni;
            j = nj;
        }
        return ans;
    }
};
