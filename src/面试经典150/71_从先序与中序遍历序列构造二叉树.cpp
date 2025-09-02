// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?envType=study-plan-v2&envId=top-interview-150

// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?envType=study-plan-v2&envId=top-interview-150\

#include <iostream>
#include <vector>
#include <unordered_map>
struct TreeNode{
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(): val(0),left(nullptr),right(nullptr){}
   TreeNode(int x): val(x),left(nullptr),right(nullptr){}

};

using namespace std;


class Solution {
private:
   unordered_map<int, int> map;
public:
   TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      int n = preorder.size();
      build(inorder);
      return f(preorder, 0 , n - 1, inorder, 0 , n - 1);
   }

   TreeNode* f(vector<int>& preorder, int l1, int r1, vector<int>& inorder, int l2, int r2){
      if(l1 > r1){
         return nullptr; 
      }
      TreeNode* head = new TreeNode(preorder[l1]);
      int head2_index = map[preorder[l1]];
      int num = head2_index - l2;
      head -> left = f(preorder, l1 + 1, l1 + num, inorder,l2, head2_index -1);
      head -> right = f(preorder,l1 + num + 1 , r1, inorder, head2_index + 1, r2);
      return head;
   }
   
   void build(vector<int>& inorder){
      int n = inorder.size();
      for(int i = 0; i < n; i++){
         map[inorder[i]] = i;
      }
   }
};

