// https://leetcode.cn/problems/n-queens-ii/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool check(vector<int>& path, int m, int n){
        for(int i = 0; i < m; i++){
            if(path[i] == n || abs(i - m) == abs(path[i] - n)){
                return false;
            }
        }
        return true;
    }

    int dfs(int n, int cur, vector<int>& path, int& sum){
        if(cur == n){
            return 1;
        }
        for(int i = 0; i < n; i++){
            path[cur] = i;
            if(check(path, cur, i)){
                sum += dfs(n, cur + 1, path, sum);
            }
        }
        return 0;
    }
    int totalNQueens(int n) {
        vector<int> path(n, 0);
        int sum = 0;
        dfs(n,0,path,sum);
        return sum;
    }
};

