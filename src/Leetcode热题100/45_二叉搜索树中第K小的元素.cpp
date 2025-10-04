// https://leetcode.cn/problems/kth-smallest-element-in-a-bst/?envType=study-plan-v2&envId=top-100-liked

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
    void dfs(TreeNode* root, int k, int& count, int& target){
        if(root == nullptr) return;
        dfs(root -> left, k , count, target);
        count++;
        if(count == k){
            target = root -> val;
            return;
        }
        dfs(root -> right, k , count, target);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int target;
        dfs(root, k, count, target);
        return target;
    }
};