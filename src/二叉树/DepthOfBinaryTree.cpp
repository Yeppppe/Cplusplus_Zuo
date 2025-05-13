
// 求二叉树的最大深度和最小深度
// 测试链接 : https://leetcode.cn/problems/maximum-depth-of-binary-tree/
// 测试链接 : https://leetcode.cn/problems/minimum-depth-of-binary-tree/


#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class DepthOfBinaryTree{
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return std::max(maxDepth(root->left),maxDepth(root->right))+1;
    }

    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 1;
        //* 初始化为较大值是为了防止当子节点不存在时也纳入深度计算
        int ldeep = INT_MAX;
        int rdeep = INT_MAX;
        if(root->left!=nullptr){
            ldeep = minDepth(root->left)+1;
        }
        if(root->right != nullptr){
            rdeep = minDepth(root->right) + 1;
        }
        return min(ldeep,rdeep);
    }

}