// https://leetcode.cn/problems/minimum-absolute-difference-in-bst/description/?envType=study-plan-v2&envId=top-interview-150
#include <algorithm>
#include <climits>
using namespace std;
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    void dfs(TreeNode* root, int& pre, int& ans){
        if(root == nullptr) return;
        dfs(root -> left, pre, ans);
        if(pre == -1){
            pre = root -> val;
        }
        else{
            ans = min(ans, root -> val - pre);
            pre = root -> val;
        }
        dfs(root -> right, pre, ans);
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        int pre = -1;
        int ans = INT_MAX;
        dfs(root, pre, ans);
        return ans;
    }
};