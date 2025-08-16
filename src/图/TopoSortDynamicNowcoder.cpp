// 拓扑排序模版（牛客）
// 邻接表建图（动态方式）
// 测试链接 : https://www.nowcoder.com/practice/88f7e156ca7d43a1a535f619cd3f495c
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下所有代码，把主类名改成Main，可以直接通过

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int m, n;
    cin >> n >> m;
    vector<vector<int>> nums(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> nums[i][0] >> nums[i][1];
    }

    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);
    for (auto edge : nums) {
        graph[edge[0]].push_back(edge[1]);
        indegree[edge[1]]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for (auto i : graph[cur]) {
            if (--indegree[i] == 0) {
                q.push(i);
            }
        }
    }
    if (ans.size() == n) {
        for (int i = 0; i < n; i++) {
            if (i > 0) cout << " ";  // 除第一个元素外，前面加空格
            cout << ans[i];
        }
        cout << endl;
    } else {
        cout << -1 << endl;  // 存在环，无法拓扑排序
    }

    return 0;
}

