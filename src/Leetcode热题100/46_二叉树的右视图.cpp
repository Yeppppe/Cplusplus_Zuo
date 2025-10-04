// https://leetcode.cn/problems/binary-tree-right-side-view/description/?envType=study-plan-v2&envId=top-100-liked


#include <vector>
#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* cur = q.front();
                q.pop();
                if(size == 0){
                    ans.push_back(cur -> val);
                }
                if(cur -> left != nullptr) q.push(cur -> left);
                if(cur -> right != nullptr) q.push(cur -> right);
            }
        }
        return ans;
    }
};
