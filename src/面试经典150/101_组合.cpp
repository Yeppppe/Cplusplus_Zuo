// https://leetcode.cn/problems/combinations/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
using namespace std;
class Solution {
private:
    vector<int> tmp;
    vector<vector<int>> ans;
public:
    void dfs(int cur, int n, int k){
        if(tmp.size() + n - cur + 1 < k){
            return;
        }
        if(tmp.size() == k){
            ans.push_back(tmp);
            return;
        }
        if(cur == n + 1){
            return;
        }
        tmp.push_back(cur);
        dfs(cur + 1, n , k);
        tmp.pop_back();
        dfs(cur + 1, n , k);
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(1,n,k);
        return ans;
    }
};