// https://leetcode.cn/problems/sum-root-to-leaf-numbers/description/?envType=study-plan-v2&envId=top-interview-150
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
   int dfs(TreeNode* root, int presum){
      if(root == nullptr) return 0;
      int sum = presum*10 + root -> val;
      if(root -> left == nullptr && root -> right == nullptr){
         return sum;
      }
      else{
         return dfs(root -> left, sum) + dfs(root -> right, sum);
      }
   }
   int sumNumbers(TreeNode* root) {
      return dfs(root , 0);
   }
};



//! 广度优先搜索的解法
#include <queue>
using namespace std;
class Solution2 {
public:
   int sumNumbers(TreeNode* root) {
      if(root == nullptr) return 0;
      queue<int> qnum;
      queue<TreeNode*> qnode;
      qnode.push(root);
      qnum.push(root -> val);
      int sum = 0;
      while(!qnode.empty()){
         TreeNode* cur = qnode.front();
         int num = qnum.front();
         qnode.pop();
         qnum.pop();
         if(cur -> left == nullptr && cur -> right == nullptr){
               sum += num;
         }
         else{
               if(cur -> left != nullptr){
                  qnode.push(cur -> left);
                  qnum.push(num*10 + cur -> left -> val);
               }

               if(cur -> right != nullptr){
                  qnode.push(cur -> right);
                  qnum.push(num*10 + cur -> right -> val);
               }
         }
      }
      return sum;
   }
};