// https://leetcode.cn/problems/binary-tree-maximum-path-sum/?envType=study-plan-v2&envId=top-100-liked

#include <algorithm>
#include <climits>
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
    int maxsum;
public:
    Solution():maxsum(INT_MIN){} 
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;

        int l = max(dfs(root -> left),0);
        int r = max(dfs(root -> right),0);

        maxsum = max(maxsum, root -> val + l + r);
        return root -> val + max(l, r);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxsum;
    }
};