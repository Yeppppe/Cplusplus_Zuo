// https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/?envType=study-plan-v2&envId=top-100-liked

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
    TreeNode* dfs(vector<int>& nums, int left, int right){
        if(left > right){
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node -> left = dfs(nums, left, mid - 1);
        node -> right = dfs(nums, mid + 1, right);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size() - 1;
        return dfs(nums, 0, n);
    }
};