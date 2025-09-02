// https://leetcode.cn/problems/same-tree/?envType=study-plan-v2&envId=top-interview-150

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
   bool isSameTree(TreeNode* p, TreeNode* q) {
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
         return isSameTree(p -> left, q -> left)&&isSameTree(p -> right, q -> right);
      }
      return true;
   }
};



//! 广度优先遍历的解法
class Solution2 {
public:
   bool isSameTree(TreeNode* p, TreeNode* q) {
      if(p == nullptr && q ==nullptr){
         return true;
      }
      else if(p == nullptr || q == nullptr){
         return false;
      }

      queue<TreeNode*> q1;
      queue<TreeNode*> q2;
      q1.push(p);
      q2.push(q);
      while(!q1.empty() && !q2.empty()){
         TreeNode* cur1 = q1.front();
         q1.pop();
         TreeNode* cur2 = q2.front();
         q2.pop();

         if(cur1 -> val != cur2 -> val){
               return false;
         }
         if((cur1 -> left == nullptr)^(cur2 -> left ==nullptr)){
               return false;
         }
         if((cur1 -> right == nullptr)^(cur2 -> right ==nullptr)){
               return false;
         }
         if(cur1 -> left != nullptr){
               q1.push(cur1 -> left);
         }
         if(cur2 -> left != nullptr){
               q2.push(cur2 -> left);
         }
         if(cur1 -> right != nullptr){
               q1.push(cur1 -> right);
         }
         if(cur2 -> right != nullptr){
               q2.push(cur2 -> right);
         }
      }
      return q1.empty() && q2.empty();
   }
};