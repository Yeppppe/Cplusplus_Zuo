// https://leetcode.cn/problems/invert-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150

#include <queue>
using namespace std;
struct TreeNode{
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode():val(0),left(nullptr),right(nullptr){}
   TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
   TreeNode* invertTree(TreeNode* root) {
      if(root == nullptr) return nullptr;
      TreeNode* left = invertTree(root -> left);
      TreeNode* right = invertTree(root -> right);
      root -> right = left;
      root -> left = right;
      return root;
   }
};