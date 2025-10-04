// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/?envType=study-plan-v2&envId=top-100-liked


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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q){
            return root;
        }
        TreeNode* l = lowestCommonAncestor(root -> left, p ,q);
        TreeNode* r = lowestCommonAncestor(root -> right, p, q);
        
        if(l != nullptr && r != nullptr) return root;
        if(l == nullptr && r == nullptr) return nullptr;

        return l != nullptr ? l : r;
    }
};