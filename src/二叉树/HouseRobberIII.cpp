// 二叉树打家劫舍问题
// 测试链接 : https://leetcode.cn/problems/house-robber-iii/

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
    int yes;   //投当前节点下的最大收益
    int no;    //不偷当前节点下的最大收益
public:
    int rob(TreeNode* root) {
        f(root);
        return max(yes,no);
    }

    void f(TreeNode* root){
        if(root == nullptr){
            yes = 0;
            no = 0;
        }
        else{
            int y = root->val;
            int n = 0;

            f(root->left);
            y+=no;
            n+=max(yes,no);

            f(root -> right);
            y+=no;
            n+=max(yes,no);

            yes = y;
            no = n;
        }
    }
};
