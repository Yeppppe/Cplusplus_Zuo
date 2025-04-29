/**
 * Java转C++代码示例
 * 本文件包含二叉树层序遍历的实现
 * 原始Java代码来自LeetCode题目：二叉树的层序遍历
 * 测试链接: https://leetcode.cn/problems/binary-tree-level-order-traversal/
 */

#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

/**
 * 二叉树节点结构
 * Java转换要点:
 * 1. Java的类 -> C++的struct或class
 * 2. Java的null -> C++的nullptr
 * 3. Java的构造函数 -> C++的构造函数
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    // 构造函数
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * 二叉树层序遍历 - 方法一：普通BFS
 * Java转换要点:
 * 1. Java的ArrayList<List<Integer>> -> C++的vector<vector<int>>
 * 2. Java的Queue<TreeNode> -> C++的queue<TreeNode*>
 * 3. Java的HashMap<TreeNode, Integer> -> C++的unordered_map<TreeNode*, int>
 * 4. Java的queue.add() -> C++的queue.push()
 * 5. Java的queue.poll() -> C++的queue.front() + queue.pop()
 */
class Solution1 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root != nullptr) {
            queue<TreeNode*> q;
            unordered_map<TreeNode*, int> levels;
            q.push(root);
            levels[root] = 0;
            
            while (!q.empty()) {
                TreeNode* cur = q.front();
                q.pop();
                int level = levels[cur];
                
                if (ans.size() == level) {
                    ans.push_back(vector<int>());
                }
                ans[level].push_back(cur->val);
                
                if (cur->left != nullptr) {
                    q.push(cur->left);
                    levels[cur->left] = level + 1;
                }
                if (cur->right != nullptr) {
                    q.push(cur->right);
                    levels[cur->right] = level + 1;
                }
            }
        }
        return ans;
    }
};

/**
 * 二叉树层序遍历 - 方法二：优化BFS
 * Java转换要点:
 * 1. Java的静态数组 -> C++的静态数组
 * 2. Java的类成员变量 -> C++的类成员变量
 * 3. Java的static final -> C++的static const
 */
class Solution2 {
private:
    // 如果测试数据量变大了就修改这个值
    static const int MAXN = 2001;
    TreeNode* queue[MAXN];
    int l, r;
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root != nullptr) {
            l = r = 0;
            queue[r++] = root;
            
            while (l < r) { // 队列里还有东西
                int size = r - l;
                vector<int> list;
                
                for (int i = 0; i < size; i++) {
                    TreeNode* cur = queue[l++];
                    list.push_back(cur->val);
                    
                    if (cur->left != nullptr) {
                        queue[r++] = cur->left;
                    }
                    if (cur->right != nullptr) {
                        queue[r++] = cur->right;
                    }
                }
                
                ans.push_back(list);
            }
        }
        return ans;
    }
};

/**
 * 测试函数
 * Java转换要点:
 * 1. Java的main方法 -> C++的main函数
 * 2. Java的System.out.println -> C++的cout
 * 3. Java的垃圾回收 -> C++的手动内存管理(delete)
 */
int main() {
    // 创建测试用例
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    // 使用两种方法测试
    Solution1 solution1;
    Solution2 solution2;
    
    vector<vector<int>> result1 = solution1.levelOrder(root);
    vector<vector<int>> result2 = solution2.levelOrder(root);
    
    // 输出结果
    cout << "方法1结果:" << endl;
    for (const auto& level : result1) {
        cout << "[";
        for (int i = 0; i < level.size(); i++) {
            cout << level[i];
            if (i < level.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    
    cout << "\n方法2结果:" << endl;
    for (const auto& level : result2) {
        cout << "[";
        for (int i = 0; i < level.size(); i++) {
            cout << level[i];
            if (i < level.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    
    // 释放内存
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;
    
    return 0;
}
