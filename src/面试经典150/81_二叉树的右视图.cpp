// https://leetcode.cn/problems/binary-tree-right-side-view/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
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
        if(root == nullptr) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode* cur = q.front();
                q.pop();
                if(sz == 0){
                    ans.push_back(cur -> val);
                }
                if(cur -> left != nullptr){
                    q.push(cur -> left);
                }
                if(cur -> right != nullptr){
                    q.push(cur -> right);
                }
            }
        }
        return ans;
    }
};