// https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/?envType=study-plan-v2&envId=top-100-liked

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
    TreeNode* prev = nullptr;

    void flatten(TreeNode* root) {
        if (!root) return;

        // 先序遍历：根 -> 左 -> 右
        // 因为要修改指针，先保存右子树
        TreeNode* right = root->right;

        if (prev) {
            prev->right = root;
            prev->left = nullptr;
        }
        prev = root;

        flatten(root->left);
        flatten(right);
    }
};
