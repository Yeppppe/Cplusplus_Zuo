// https://leetcode.cn/problems/palindrome-partitioning/description/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool ishuiwen(string s){
        int n = s.size();
        if(n == 1) return true;
        int l = 0, r = n - 1;
        while(l < r){
            if(s[l++] != s[r--]){
                return false;
            }
        }
        return true;
    }

    void dfs(vector<vector<string>>& ans, vector<string>& sub, string s, int cur){
        if(cur == s.size()){
            ans.push_back(sub);
        }
        string tmp;
        for(int i = cur; i < s.size(); i++){
            tmp.push_back(s[i]);
            if(ishuiwen(tmp)){
                sub.push_back(tmp);
                dfs(ans, sub, s, i + 1);
                sub.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> sub;
        dfs(ans, sub, s, 0);
        return ans;
    }
};