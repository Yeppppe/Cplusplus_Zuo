<<<<<<< HEAD
#include <iostream>
#include <vector>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode():val(0),left(nullptr),right(nullptr){};
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
    TreeNode(int x,TreeNode* left,TreeNode* right):val(x),left(left),right(right){};
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q){
            return root;
        }

        TreeNode* l = lowestCommonAncestor()
    }
};

=======
// 普通二叉树上寻找两个节点的最近公共祖先
// 测试链接 : https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/


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
        if(root == nullptr || root == p || root == q) return root;
        
        TreeNode* l = lowestCommonAncestor(root->left,p,q);
        TreeNode* r = lowestCommonAncestor(root->right , p ,q);

        if(l!= nullptr && r!=nullptr) return root;
        if(l == nullptr && r == nullptr) return nullptr;

        return l!=nullptr? l : r;
    }
};
>>>>>>> 3d6d3cf2ecf0497c21999da786ce3443b0c4f01b
