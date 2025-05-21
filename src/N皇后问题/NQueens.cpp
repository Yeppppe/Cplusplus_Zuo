// N皇后问题
// 测试链接 : https://leetcode.cn/problems/n-queens-ii/

class Solution {
private:
    vector<int> path;
public:
    int totalNQueens(int n) {
        int ans = 0;
        path.resize(n);
        ans = f(path, 0, n);
        return ans;
    }

    //* 已经摆好了 0 - i-1 从i - n-1还有多少种摆法
    int f(vector<int>& path, int i, int n){
        if(i == n){
            return 1;
        }
        int ans = 0;
        for(int j=0; j<n; j++){
            if(check(path, i, j)){
                path[i] = j;
                ans += f(path, i+1, n);
            }
        }
        return ans;
    }

    bool check(vector<int>& path, int i, int j){
        for(int k = 0; k < i; k++){
            if(path[k] == j || abs(k-i) == abs(path[k]-j)) 
                return false;
        }
        return true;
    }
};



//* 位运算版本 快很多
class Solution {

public:
    int totalNQueens(int n) {
        int limit = (1<<n)-1;
        int ans = 0;
        ans = f(limit,0,0,0);
        return ans;
    }

    int f(int limit, int col, int left, int right){
        if (col == limit){
            return 1;
        }

        int ban = col|left|right;
        int candidate = limit & (~ban);
        int ans = 0;
        while(candidate!=0){
            int place = candidate&(-candidate);
            candidate ^= place;
            ans += f(limit,col|place,(left|place)<<1,(right|place)>>1); 
        }
        return ans;
    }
};
