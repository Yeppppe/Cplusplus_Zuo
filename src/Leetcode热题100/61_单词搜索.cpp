// https://leetcode.cn/problems/word-search/description/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int cur, int m, int n){
        if(cur == word.size()){
            return true;
        }
        if(m < 0 || m >= board.size()) return false;
        if(n < 0 || n >= board[0].size()) return false;
        bool check = false;
        if(board[m][n] == word[cur]){
            char tmp = board[m][n];
            board[m][n] = '0';
            check = dfs(board, word, cur + 1, m - 1, n) ||
                    dfs(board, word, cur + 1, m + 1, n) ||
                    dfs(board, word, cur + 1, m, n - 1) ||
                    dfs(board, word, cur + 1, m, n + 1);
            board[m][n] = tmp;
        }
        return check;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dfs(board,word,0,i,j)){
                    return true;
                }
            }
        }
        return false;
    }
};