// https://leetcode.cn/problems/binary-search-tree-iterator/description/?envType=study-plan-v2&envId=top-interview-150

//! 这题很怪，没有看懂

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
class BSTIterator {
private:
    vector<int> vec;
    int idx;
    void inorder(TreeNode* root, vector<int>& vec){
        if(root == nullptr) return;
        inorder(root -> left, vec);
        vec.push_back(root -> val);
        inorder(root -> right, vec);
    }

    void buildvec(TreeNode* root){
        inorder(root,vec);
        return;
    }
public:
    BSTIterator(TreeNode* root):idx(0) {
        buildvec(root);
    }
    
    int next() {
        return vec[idx++];
    }
    
    bool hasNext() {
        return idx < vec.size();
    }
};
