// https://leetcode.cn/problems/count-complete-tree-nodes/description/?envType=study-plan-v2&envId=top-interview-150

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
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = countNodes(root -> left);
        int right = countNodes(root -> right);
        return left + right + 1;
    }
};




//! 利用二叉树性质的版本
class Solution2 {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int l = 0;
        int r = 0;
        TreeNode* node = root;
        while(node -> left != nullptr){
            l += 1;
            node = node -> left;
        }
        node = root;
        while(node -> right != nullptr){
            r += 1;
            node = node -> right;
        }
        if(l == r){
            return (1 << (l + 1)) - 1;
        }
        return countNodes(root -> left) + countNodes(root -> right) + 1;
    }
};
