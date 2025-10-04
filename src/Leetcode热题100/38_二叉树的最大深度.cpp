// https://leetcode.cn/problems/maximum-depth-of-binary-tree/?envType=study-plan-v2&envId=top-100-liked

#include <algorithm>
#include <vector>
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
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
        int ld = dfs(root -> left) + 1;
        int rd = dfs(root -> right) + 1;
        return max(ld, rd);
    }   
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};