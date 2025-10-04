// https://leetcode.cn/problems/rotting-oranges/submissions/667524583/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<int> dirx = {-1, 1, 0, 0};
        vector<int> diry = {0, 0, -1, 1};
        int freshcount = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                if(grid[i][j] == 1){
                    freshcount++;
                }
            }
        }
        if(freshcount == 0) return 0;
        int minutes = -1;
        while(!q.empty()){
            int size = q.size();
            minutes++;
            for(int i = 0; i < size; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int j = 0; j < 4; j++){
                    int nx = x + dirx[j];
                    int ny = y + diry[j];
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1){
                        q.push({nx, ny});
                        grid[nx][ny] = 2;
                        freshcount--;
                    }
                }
            }
        }
        return freshcount == 0 ? minutes : -1;
    }
};