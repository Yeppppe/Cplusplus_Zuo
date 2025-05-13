// 求完全二叉树的节点个数
// 测试链接 : https://leetcode.cn/problems/count-complete-tree-nodes/




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
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        return f(root,1,mostLeft(root,1));
    }

    int f(TreeNode* cur,int cur_level,int h){
        if(cur_level == h) return 1;
        int ans = 0;
        if(mostLeft(cur->right,cur_level+1) == h){
            ans = ((1<<(h-cur_level)) + f(cur->right,cur_level+1,h));
        }
        else{
            ans = ((1<<(h-cur_level-1)) + f(cur->left , cur_level+1 , h));
        }
        return ans;
    }

    // 从当前节点开始扎，能扎到第几层
    int mostLeft(TreeNode* cur,int cur_level){
        int level = cur_level;
        while(cur != nullptr){
            cur = cur->left;
            level += 1;
        }
        return level-1;
    }
};