// https://leetcode.cn/problems/diameter-of-binary-tree/description/?envType=study-plan-v2&envId=top-100-liked

#include <algorithm>
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
private:
    int maxn;
public:
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
        int ld = dfs(root -> left);
        int rd = dfs(root -> right);
        maxn = max(maxn, ld + rd + 1);
        return max(ld, rd) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxn = 0;
        dfs(root);
        return maxn - 1;
    }
};