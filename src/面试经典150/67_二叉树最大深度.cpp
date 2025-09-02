// https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode{
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(): val(0),left(nullptr),right(nullptr){}
   TreeNode(int x): val(x),left(nullptr),right(nullptr){}

};

class Solution {
public:
   int maxDepth(TreeNode* root) {
      return root == nullptr ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
   }
};



//! 广度优先遍历
class Solution2 {
public:
   int maxDepth(TreeNode* root) {
      if(root == nullptr) return 0;
      queue<TreeNode*> q;
      q.push(root);
      int ans = 0;
      while(!q.empty()){
         int sz = q.size();
         while(sz--){
               TreeNode* cur = q.front();
               q.pop();
               if(cur -> left != nullptr){
                  q.push(cur -> left);
               }
               if(cur -> right != nullptr){
                  q.push(cur -> right);
               }
         }
         ans++;
      }
      return ans;
   }
};