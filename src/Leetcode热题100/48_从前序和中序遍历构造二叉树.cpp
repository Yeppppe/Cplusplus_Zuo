// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/?envType=study-plan-v2&envId=top-100-liked
#include <unordered_map>
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
private:
    unordered_map<int, int> map;
public:
    TreeNode* dfs(vector<int>& preorder, int b1, int e1, vector<int>& inorder, int b2, int e2){
        if (b1 > e1 || b2 > e2) return nullptr;
        TreeNode* node = new TreeNode(preorder[b1]);
        int in_index = map[preorder[b1]];
        int len = in_index - b2;
        node -> left = dfs(preorder,b1 + 1, b1 + len,inorder, b2, in_index - 1);
        node -> right = dfs(preorder, b1 + len + 1, e1, inorder, in_index + 1, e2);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            map[inorder[i]] = i;
        }
        TreeNode* head = dfs(preorder, 0, n - 1, inorder, 0, n - 1);
        return head;
    }
};

