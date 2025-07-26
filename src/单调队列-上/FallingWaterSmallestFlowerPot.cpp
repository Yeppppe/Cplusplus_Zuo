// 接取落水的最小花盆
// 老板需要你帮忙浇花。给出 N 滴水的坐标，y 表示水滴的高度，x 表示它下落到 x 轴的位置
// 每滴水以每秒1个单位长度的速度下落。你需要把花盆放在 x 轴上的某个位置
// 使得从被花盆接着的第 1 滴水开始，到被花盆接着的最后 1 滴水结束，之间的时间差至少为 D
// 我们认为，只要水滴落到 x 轴上，与花盆的边沿对齐，就认为被接住
// 给出 N 滴水的坐标和 D 的大小，请算出最小的花盆的宽度 W
// 测试链接 : https://www.luogu.com.cn/problem/P2698
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过


//!  洛谷是噩梦
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 
using namespace std;

vector<int> max_stack(100005);
vector<int> min_stack(100005);
int max_h = 0;
int min_h = 0;
int max_t = 0;
int min_t = 0;

// 无需传入water，push仅操作索引
void push(vector<pair<int, int>>& water, int r) {
    while (max_h < max_t && water[max_stack[max_t - 1]].second <= water[r].second) {
        max_t--;
    }
    max_stack[max_t++] = r;
    while (min_h < min_t && water[min_stack[min_t - 1]].second >= water[r].second) {
        min_t--;
    }
    min_stack[min_t++] = r;
}

// 移除water参数，仅需索引判断
void pop(int l) {
    if (max_h < max_t && max_stack[max_h] == l) {
        max_h++;
    }
    if (min_h < min_t && min_stack[min_h] == l) {
        min_h++;
    }
}

int get_max(vector<pair<int, int>>& water) {
    return max_h < max_t ? water[max_stack[max_h]].second : -1; // 用-1避免初始0的误判
}  

int get_min(vector<pair<int, int>>& water) {
    return min_h < min_t ? water[min_stack[min_h]].second : -1;
}

int main() {
    // 优化输入输出速度，避免大数据量下的异常
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, limit;
    cin >> n >> limit;
    vector<pair<int, int>> water(n);
    for (int i = 0; i < n; i++) {
        cin >> water[i].first >> water[i].second;
    }
    sort(water.begin(), water.end(),
        [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        }
    );

    int ans = INT_MAX;
    int r = 0; // r定义在循环外，避免重复初始化
    for (int l = 0; l < n; l++) {
        // 扩展右边界，直到满足条件或遍历完所有元素
        while (r < n) {
            // 先判断当前窗口是否已满足条件（避免无效push）
            if (get_max(water) - get_min(water) >= limit) {
                break;
            }
            push(water, r);
            r++;
        }

        // 检查是否满足条件，同时避免r=0时r-1越界
        if (r > 0 && get_max(water) - get_min(water) >= limit) {
            ans = min(ans, water[r - 1].first - water[l].first);
        }

        pop(l); // 移除左边界
    }

    ans = (ans == INT_MAX) ? -1 : ans;
    cout << ans << endl;
    return 0;
}
