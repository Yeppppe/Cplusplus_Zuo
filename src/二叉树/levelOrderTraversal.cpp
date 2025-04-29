#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
// 层序遍历
// 测试链接: https://leetcode.cn/problems/binary-tree-level-order-traversal/
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    //构造函数
    TreeNode():val(0),left(nullptr),right(nullptr);
    TreeNode(int x):val(x),left(nullptr),right(nullptr);
    TreeNode(int x,TreeNode* left,TreeNode* right):val(x),left(left),right(right);
};

//普通BFS
class Normal_BFS{
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root != nullptr){
            queue<TreeNode*> q;
            q.push(root);
            unordered_map<TreeNode*,int> levels;
            levels[root] = 0;
            while(!q.empty()){
                TreeNode* cur = q.front();
                q.pop();
                int level = levels[cur];
                if(ans.size() == level){
                    ans.push_back(vector<int>());
                }
                ans[level].push_back(cur->val);

                if(cur->left!=nullptr){
                    levels[cur->left] = level+1;
                    q.push(cur->left);
                }
                if(cur->right!=nullptr){
                    levels[cur->right] = level+1;
                    q.push(cur->right);
                }
            }
        }
        return ans;
    }
}


优化BFS
class BFS{
private:
    static const int Maxn = 2001;
    TreeNode* q[Maxn];
    int l = 0;
    int r = 0;
public:
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> ans;
        if(root!=nullptr){
            q[r++] = root;
            while(l<r){
                int size = r-l;
                vector<int> list;
                for(int i = 0;i<size;i++){
                    list.push_back(q[l]->val);
                    if(q[l] -> left != nullptr){
                        q[r++] = q[l] -> left;
                    }
                    if(q[l] -> right != nullptr){
                        q[r++] = q[l] -> right;
                    }
                    l++;
                }
                ans.push_back(list);
            }
        }
        return ans;
    }
}


// 二叉树的锯齿形层序遍历
// 测试链接 : https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/
// 注意，遍历顺序其实没变，只是拿值的时候变了，不能混淆了！！！
class zigzagBFS{
private:
    static const int MAXN = 2001;
    TreeNode* q[MAXN];
    int l = 0;
    int r = 0;
    bool Reverse = false;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root!=nullptr){
            q[r++] = root;
            while(l<r){
                vector<int> list;
                int size = r - l;
                for(int k = 0, i = Reverse ? r-1 : l, j = Reverse ? -1 : 1; k < size; i += j, k++){
                    list.push_back(q[i]->val);
                }
                for(int i = 0; i < size ; i++){
                    TreeNode* cur = q[l++];
                    if(cur->left!=nullptr){
                        q[r++] = cur->left;
                    }
                    if(cur->right!=nullptr){
                        q[r++] = cur->right;
                    }
                }
                Reverse = !Reverse;
                ans.push_back(list);
            }
        }
        return ans;
    }
}