// https://leetcode.cn/problems/construct-quad-tree/description/?envType=study-plan-v2&envId=top-interview-150
#include <vector>
#include <functional>
using namespace std;
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> pre(n + 1,vector<int>(n + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }

        auto getSum = [&](int r1, int c1, int r2, int c2){
            return pre[r2][c2] - pre[r2][c1 - 1] - pre[r1 - 1][c2] + pre[r1 - 1][c1 - 1];
        };

        function<Node* (int,int,int,int)> dfs = [&](int r0,int c0, int r1, int c1){
            int total = getSum(r0 + 1,c0 + 1, r1+1,c1+1);
            if(total == 0){
                return new Node(false, true);
            }
            if(total == (r1 - r0 +1)*(c1 - c0 + 1)){
                return new Node(true,true);
            }
            // 计算中点（关键：正确拆分区域）
            int midR = (r0 + r1) / 2;  // 行中点（上半部分终点）
            int midC = (c0 + c1) / 2;  // 列中点（左半部分终点）

            // 正确拆分4个子区域（无重叠、无遗漏）
            return new Node(
                true,  // val值不影响非叶子节点
                false,
                dfs(r0, c0, midR, midC),                  // 左上：r0~midR, c0~midC
                dfs(r0, midC + 1, midR, c1),              // 右上：r0~midR, midC+1~c1
                dfs(midR + 1, c0, r1, midC),              // 左下：midR+1~r1, c0~midC
                dfs(midR + 1, midC + 1, r1, c1)           // 右下：midR+1~r1, midC+1~c1
            );
        };
        return dfs(0,0,n-1,n-1);
    }
};


