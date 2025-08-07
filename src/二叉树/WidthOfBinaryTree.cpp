#include <iostream>

// 二叉树的最大特殊宽度
// 测试链接 : https://leetcode.cn/problems/maximum-width-of-binary-tree/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){};
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
    TreeNode(int x,TreeNode* left,TreeNode* right):val(x),left(left),right(right){};
}

// *注意有可能出现越界情况
class Solution {
private:
    static const int MAXN = 3001;
    TreeNode* q[MAXN];
    unsigned long long iq[MAXN];
    int l=0;
    int r=0;
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        l = 0;
        r = 0;
        q[r++] = root;
        iq[l] = 1;
        unsigned long long ans = 1;
        while(l<r){
            int size = r-l;
            ans = std::max(ans,iq[r-1]-iq[l]+1);
            for(int i=0;i<size;i++){
                TreeNode* cur = q[l];
                unsigned long long id_cur = iq[l++];
                if(cur->left != nullptr){
                    q[r] = cur->left;
                    iq[r++] = id_cur*2;
                }
                if(cur->right != nullptr){
                    q[r] = cur->right;
                    iq[r++] = id_cur*2 +1;
                }
            }
        }
        return ans;
    }
};

