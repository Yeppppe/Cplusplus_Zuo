// https://leetcode.cn/problems/validate-binary-search-tree/?envType=study-plan-v2&envId=top-100-like

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
    bool dfs(TreeNode* root, long low, long high){
        if(root == nullptr) return true;
        if(root -> val <= low || root -> val >= high) return false;
        return dfs(root -> left, low, root -> val) && dfs(root -> right, root -> val, high);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};