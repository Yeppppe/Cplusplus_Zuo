// https://leetcode.cn/problems/generate-parentheses/?envType=study-plan-v2&envId=top-100-liked

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<string>& ans, string& tmp, int left, int right, int cur, int n){
        if(cur == 2 * n){
            ans.push_back(tmp);
            return;
        }
        if(left < n){
            tmp.push_back('(');
            dfs(ans, tmp, left + 1, right, cur + 1, n);
            tmp.pop_back();
        }
        if(left > right){
            tmp.push_back(')');
            dfs(ans, tmp, left, right + 1, cur + 1, n);
            tmp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string tmp;
        dfs(ans, tmp, 0, 0, 0, n);
        return ans;
    }
};

