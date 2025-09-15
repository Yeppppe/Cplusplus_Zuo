// https://leetcode.cn/problems/maximal-square/solutions/234964/zui-da-zheng-fang-xing-by-leetcode-solution/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(m == 0 || n == 0) return 0;
        vector<vector<int>> dp(m,vector<int>(n , 0));
        int curmax = 0;
        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1'){
                    if(i == 0 || j == 0){
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    }
                    if(dp[i][j] > curmax) curmax = dp[i][j];
                }
            }
        }
        return curmax * curmax;
    }
};