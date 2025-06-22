// 验证搜索二叉树
// 测试链接 : https://leetcode.cn/problems/validate-binary-search-tree/

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
//* 注意溢出问题
class Solution {
private:
    long long min;
    long long max;
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr){
            min = LLONG_MAX;
            max = LLONG_MIN;
            return true;
        }
        bool lok = isValidBST(root->left);
        long long lmin = min;
        long long lmax = max;
        bool rok = isValidBST(root -> right);
        long long rmin = min;
        long long rmax = max;

        min = std::min(std::min(lmin,rmin),(long long)root->val);
        max = std::max(std::max(lmax,rmax),(long long)root->val);
        return lok&&rok&&(lmax<root->val)&&(root->val < rmin);
   }
};