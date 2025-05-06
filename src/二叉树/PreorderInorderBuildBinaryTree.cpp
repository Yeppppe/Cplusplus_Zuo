// 利用先序与中序遍历序列构造二叉树
// 测试链接 : https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include <iostream>
#include <vector>
#include <unorderded_map>


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v):val(v),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> map;
        for(int i = 0;i<inorder.size();i++){
            map[inorder[i]] = i;
        }
        return f(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,map);
    }

    //* 递归返回先序和中序的的头节点
    TreeNode* f(vector<int>& preorder,int l1,int r1,vector<int>& inorder,int l2,int r2,unordered_map<int,int>& map){
        if(l1 > r1) return nullptr;
        TreeNode* head = new TreeNode(preorder[l1]);
        if(l1 == r1) return head;

        int k = map[preorder[l1]];
        head->left = f(preorder,l1+1,l1+k-l2,inorder,l2,k-1,map);
        head->right = f(preorder,l1+k-l2+1,r1,inorder,k+1,r2,map);
        return head;
    }
};
