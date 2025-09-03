// https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/?envType=study-plan-v2&envId=top-interview-150

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
   TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      int n = inorder.size();
      build(inorder);
      return f(inorder, 0, n - 1, postorder, 0 , n - 1);
   }

   TreeNode* f(vector<int>& inorder, int l1, int r1, vector<int>& postorder, int l2, int r2){
      if(l2 > r2) return nullptr;
      TreeNode* head = new TreeNode(postorder[r2]);
      int index = map[postorder[r2]];
      int num = index - l1;
      head -> left = f(inorder, l1, index - 1, postorder, l2, l2 + num - 1);
      head -> right = f(inorder, index +1, r1, postorder, l2 + num, r2 - 1);
      return head;
   }

   void build(vector<int>& inorder){
      int n = inorder.size();
      for(int i = 0; i < n; i++){
         map[inorder[i]] = i;
      }
   }
};