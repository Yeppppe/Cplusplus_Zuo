// https://leetcode.cn/problems/invert-binary-tree/?envType=study-plan-v2&envId=top-100-liked




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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        TreeNode* left = root -> left;
        TreeNode* right = root -> right;
        root -> left = invertTree(right);
        root -> right = invertTree(left);
        return root;
    }
};