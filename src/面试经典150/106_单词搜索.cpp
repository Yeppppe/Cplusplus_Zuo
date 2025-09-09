// https://leetcode.cn/problems/word-search/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int cur, int m, int n){
        if(cur == word.size()){
            return true;
        }
        if(m < 0 || m >= board.size() || n < 0 || n >= board[0].size() || board[m][n] == '0'){
            return false;
        }
        bool check = false;
        char tmp = board[m][n];
        if(board[m][n] == word[cur]){
            board[m][n] = '0';
            check =  dfs(board,word,cur + 1,m - 1, n) ||
                   dfs(board,word,cur + 1,m + 1, n) ||
                   dfs(board,word,cur + 1,m, n - 1) ||
                   dfs(board,word,cur + 1,m, n + 1);
            board[m][n] = tmp;
        }
        return check;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dfs(board,word,0,i,j))
                    return true;
            }
        }
        return false;
    }
};