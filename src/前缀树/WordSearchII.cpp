// 在二维字符数组中搜索可能的单词
// 给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words
// 返回所有二维网格上的单词。单词必须按照字母顺序，通过 相邻的单元格 内的字母构成
// 其中“相邻”单元格是那些水平相邻或垂直相邻的单元格
// 同一个单元格内的字母在一个单词中不允许被重复使用
// 1 <= m, n <= 12
// 1 <= words.length <= 3 * 10^4
// 1 <= words[i].length <= 10
// 测试链接 : https://leetcode.cn/problems/word-search-ii/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
private:
    static const int MAXN = 300001;
    int tree[MAXN][26];
    int pass[MAXN];
    string end[MAXN];
    int count;

    void build(vector<string>& words){
        count = 1;
        for(auto word : words){
            int cur = 1;
            pass[cur]++;
            for(int i = 0; i < word.size();i++){
                int path = word[i] - 'a';
                if(tree[cur][path] == 0)
                    tree[cur][path] = ++count;
                cur = tree[cur][path];
                pass[cur]++;
            }
            end[cur] = word;
        }
    }


    int dfs(vector<vector<char>>& board, int i, int j, int cur, vector<string>& ans){
        if(i >= board.size() || j >= board[0].size() || board[i][j] == '0')
            return 0;
        char tmp = board[i][j];
        int path = board[i][j] - 'a';
        cur = tree[cur][path];
        if(pass[cur] == 0) return 0;

        int fix;
        if(!end[cur].empty()){
            ans.push_back(end[cur]);
            fix++;
            end[cur] = "";
        }

        board[i][j] = '0';
        fix+=dfs(board,i+1,j,cur,ans);
        fix+=dfs(board,i-1,j,cur,ans);
        fix+=dfs(board,i,j+1,cur,ans);
        fix+=dfs(board,i,j-1,cur,ans);

        pass[cur] -= fix;
        board[i][j] = tmp;
        return fix;

    }

    void clear(){
        for(int i = 1;i<=count;i++){
            memset(tree[i],0,sizeof(tree[i]));         //# include <cstring>
            pass[i] = 0;
            end[i] = "";
        }
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        build(words);
        vector<string> ans;
        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0; j<board[0].size();j++){
                dfs(board,i,j,1,ans);
            }
        }
        return ans;
    }
};
