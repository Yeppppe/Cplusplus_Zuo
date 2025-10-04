// https://leetcode.cn/problems/path-sum-iii/description/?envType=study-plan-v2&envId=top-100-liked

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
public:
    int dfs(TreeNode* root, long long targetSum){
        if(root == nullptr) return 0;
        int ret = 0;
        if(root -> val == targetSum){
            ret++;
        }
        ret += dfs(root -> left, targetSum - root -> val);
        ret += dfs(root -> right, targetSum - root -> val);
        return ret;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;
        int sum = 0;
        sum = dfs(root, targetSum);
        sum += pathSum(root -> left, targetSum);
        sum += pathSum(root -> right, targetSum);
        return sum;
    }
};