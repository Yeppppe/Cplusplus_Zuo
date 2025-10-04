// https://leetcode.cn/problems/binary-tree-inorder-traversal/description/?envType=study-plan-v2&envId=top-100-liked

#include <stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        vector<int> ans;
        if(!root) return ans;
        while(!stack.empty() || root != nullptr){
            while(root != nullptr){
                stack.push(root);
                root = root -> left;
            }
            
            root = stack.top();
            stack.pop();
            ans.push_back(root -> val);
            root = root -> right;
        }
        return ans;
    }
};