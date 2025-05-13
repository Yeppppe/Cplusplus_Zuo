// 验证完全二叉树
// 测试链接 : https://leetcode.cn/problems/check-completeness-of-a-binary-tree/

// 1. 有右无左 则为非完全二叉树
// 2. 如果遇到一个节点左右子节点不全（左子节点或右子节点其中一个为空），则接下来所有节点都应该为根节点

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
private:
    vector<TreeNode*> ans;
    int l;
    int r;
public:
    bool isCompleteTree(TreeNode* root) {
        if(root == nullptr) return true;
        l=0;
        r=1;
        ans.push_back(root);
        bool leaf = false;
        while(l<r){
            TreeNode* node = ans[l++];
            if(node->right != nullptr && node->left== nullptr){
                return false;
            }
            if(leaf && (node->left!=nullptr || node->right!=nullptr)) return false;
            if(node->left != nullptr){
                ans.push_back(node->left);
                r++;
            }
            if(node->right != nullptr){
                ans.push_back(node->right);
                r++;
            }
            //* 在判断完当前节点后 接下里应该均为叶子节点，所以已更改放在后面，如果放在34行之前，直接就会对当前节点判定是否为叶子节点
            if(node->left ==nullptr || node->right == nullptr){
                leaf = true;
            }
        }
        return true;
    }
};


