// https://leetcode.cn/problems/symmetric-tree/description/?envType=study-plan-v2&envId=top-interview-150

struct TreeNode{
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(): val(0),left(nullptr),right(nullptr){}
   TreeNode(int x): val(x),left(nullptr),right(nullptr){}

};

class Solution {
public:
   bool isSymmetric(TreeNode* root) {
      if(root == nullptr || (root -> left == nullptr && root -> right == nullptr)) return true;
      return isMirror(root -> left, root -> right);
   }
   bool isMirror(TreeNode* p, TreeNode* q) {
   if(p == nullptr && q == nullptr){
      return true;
   }
   else if(p == nullptr || q == nullptr){
      return false;
   }
   else if(p -> val != q -> val){
      return false;
   }
   else{
      return isMirror(p -> right, q -> left)&&isMirror(p -> left, q -> right);
   }
   return true;
}
};

