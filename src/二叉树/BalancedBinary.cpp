// 验证平衡二叉树
// 测试链接 : https://leetcode.cn/problems/balanced-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool isbalance;
public:
    bool isBalanced(TreeNode* root) {
        isbalance = true;
        height(root);
        return isbalance;
    }

    int height(TreeNode* root){
        if(root == nullptr || isbalance == false){
            return 0;
        }

        int lh = height(root->left);
        int rh = height(root->right);
        if(abs(lh-rh)>1){
            isbalance = false;
            return 0;
        }
        return max(lh,rh)+1;
    }
};