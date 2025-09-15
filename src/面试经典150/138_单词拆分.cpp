// https://leetcode.cn/problems/word-break/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
#include <string>
using namespace std;

//! 仍然是记忆化搜索的写法  关于
class Solution {
private:
    vector<int> memo;
public:
    bool dfs(vector<string>& wordDict, string s, int cur){
        if(cur == s.size()) return true;
        if(memo[cur] != -1) return memo[cur]; 
        for(auto word : wordDict){
            string tmp = s.substr(cur, word.size());
            if (tmp == word){
                if(dfs(wordDict,s,cur + word.size())){
                    memo[cur] = 1;
                    return memo[cur];
                }
            }
        }
        memo[cur] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memo.resize(s.size(), -1);
        return dfs(wordDict, s, 0);
    }
};
