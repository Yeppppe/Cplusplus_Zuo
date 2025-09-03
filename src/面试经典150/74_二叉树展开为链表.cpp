// https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
using namespace std;
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
   void flatten(TreeNode* root) {
      if(root == nullptr) return;
      vector<TreeNode*> vec;
      preorder(root, vec);
      TreeNode* dummyNode = new TreeNode(-1);
      TreeNode* pre = dummyNode;
      for(auto n : vec){
         pre -> right = n;
         pre -> left = nullptr;
         pre = n;
      }
   }

   void preorder(TreeNode* root, vector<TreeNode*>& vec){
      if(root == nullptr) return;
      vec.push_back(root);
      preorder(root -> left, vec);
      preorder(root -> right, vec);
   }
};
