// 收集累加和等于aim的所有路径
// 测试链接 : https://leetcode.cn/problems/path-sum-ii/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> tmp_path;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return ans;
        f(root,0,targetSum,tmp_path,ans);
        return ans;
    }

    //* 递归
    void f(TreeNode* cur,int sum,int targetSum,vector<int>& tmp_path,vector<vector<int>>& ans){
        if(cur->left == nullptr && cur->right == nullptr){
            if(sum + cur->val == targetSum){
                tmp_path.push_back(cur->val);
                ans.push_back(tmp_path);
                tmp_path.pop_back();               //* 还原现场
            }
        }
        else{
            tmp_path.push_back(cur->val);
            if(cur->left!=nullptr){
                f(cur->left,sum+cur->val,targetSum,tmp_path,ans);
            }
            if(cur->right!=nullptr){
                f(cur->right,sum+cur->val,targetSum,tmp_path,ans);
            }
            tmp_path.pop_back();
        }
    }
};