// https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <queue>
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        bool re = false;
        vector<vector<int>> ans;
        while(!q.empty()){
            int sz = q.size();
            vector<int> tmp;
            while(sz--){
                TreeNode* cur = q.front();
                q.pop();
                tmp.push_back(cur -> val);
                if(cur -> left != nullptr){
                        q.push(cur -> left);
                    }
                    if(cur -> right != nullptr){
                        q.push(cur -> right);
                    }
            }
            if(re){
                reverse(tmp.begin(), tmp.end());
            }
            re = !re;
            ans.push_back(tmp);
        }
        return ans;
    }
};