// 递归序的解释
// 用递归实现二叉树的三序遍历


#include <iostream>
using namespace std;


struct TreeNode{
   int val;
   TreeNode* left;
   TreeNode* right;

   TreeNode(int v):val(v),left(nullptr),right(nullptr){}
};


void pre(TreeNode* head){
   if(head == nullptr) return;
   cout << head->val;
   pre(head->left);
   pre(head->right);
}


void in(TreeNode* head){
   if(head == nullptr) return;
   pre(head->left);
   cout << head->val;
   pre(head->right);
}


void pos(TreeNode* head){
   if(head == nullptr) return;
   pre(head->left);
   pre(head->right);
   cout << head->val;
}
