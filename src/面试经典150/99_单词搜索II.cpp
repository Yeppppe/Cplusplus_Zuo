// https://leetcode.cn/problems/word-search-ii/?envType=study-plan-v2&envId=top-interview-150

#include <string>
#include <vector>
#include <set>
using namespace std;
class Solution {
private:
    struct TrieNode{
        int pass;
        int end;
        TrieNode* next[26];
        string word;
        TrieNode():pass(0),end(0),word(""){
            for(int i = 0; i < 26; i++){
                next[i] = nullptr;
            }
        }
    };
    TrieNode* root;
public:
    Solution(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* node = root;
        node -> pass++;
        for(auto c : word){
            int path = c - 'a';
            if(node -> next[path] == nullptr){
                node -> next[path] = new TrieNode();
            }
            node = node -> next[path];
            node -> pass++;
        }
        node -> end++;
        node -> word = word;
    }

    int search(string word){
        TrieNode* node = root;
        for(auto c : word){
            int path = c - 'a';
            if(node -> next[path] == nullptr){
                return 0;
            }
            node = node -> next[path];
        }
        return node -> end;
    }

    bool prefixSearch(string word){
        TrieNode* node = root;
        for(auto c : word){
            int path = c - 'a'; 
            if(node -> next[path] == nullptr){
                return false;
            }
            node = node -> next[path];
        }
        return node -> pass > 0;
    }

    void dfs(vector<vector<char>>& board, int m, int n, TrieNode* node, set<string>& ans){
        if(m < 0 || m >= board.size() || n < 0 || n >= board[0].size() || board[m][n] == '0'){
            return;
        }

        char currChar = board[m][n];
        int path = board[m][n] - 'a';
        TrieNode* nextnode = node -> next[path];
        if(nextnode == nullptr) return;
        if(nextnode -> end > 0) ans.insert(nextnode -> word);
        if(node -> next[path] == nullptr) return;
        board[m][n] = '0';
        dfs(board , m - 1, n, node -> next[path],ans);
        dfs(board , m + 1, n, node -> next[path],ans);
        dfs(board , m, n - 1, node -> next[path],ans);
        dfs(board , m, n + 1, node -> next[path],ans);
        board[m][n] = currChar;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto word : words){
            insert(word);
        }

        int m = board.size();
        int n = board[0].size();
        set<string> tmp;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dfs(board, i, j, root, tmp);
            }
        }
        vector<string> ans(tmp.begin(),tmp.end());
        return ans;
    }
};

