// 搜索二叉树上寻找两个节点的最近公共祖先
// 测试链接 : https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != nullptr) {
            if (root->val > std::max(p->val, q->val)) {
                root = root->left;
            } else if (root->val < std::min(p->val, q->val)) {
                root = root->right;
            } else {
                // root->val 介于 p 和 q 之间，或者等于 p 或 q
                break;
            }
        }
        return root; // 理论上不会到这里
    }
};