// 最大食物链计数
// a -> b，代表a在食物链中被b捕食
// 给定一个有向无环图，返回
// 这个图中从最初级动物到最顶级捕食者的食物链有几条
// 测试链接 : https://www.luogu.com.cn/problem/P4017
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下所有代码，把主类名改成Main，可以直接通过
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
   int n, m;
   int MOD = 80112002;
   cin >> n >> m;     // n 为生物种类    m为被吃关系数（边的条数）
   vector<int> indegree(n,0);
   vector<int> lines(n,0);
   vector<vector<int>> graph(n);
   //! 建图
   for(int i = 0; i < m; i++){
      int a,b;
      cin >> a >> b;
      graph[a - 1].push_back(b - 1);
      indegree[b - 1]++;
   }

   queue<int> q;
   for(int i = 0; i < n; i++){
      if(indegree[i] == 0){
         lines[i] = 1;
         q.push(i);
      }
   }

   long long ans = 0;
   while(!q.empty()){
      int cur = q.front();
      q.pop();
      if(graph[cur].empty()){                        //* 如果当前节点不再有后续的邻居了，相当于最高的捕食者
         ans = (ans + lines[cur]) % MOD;                               
      }
      for(auto edg : graph[cur]){
         lines[edg] = (lines[edg] + lines[cur])%MOD;         //! 加法同余原理，过程中所有的加法都需要进行取模 %MOD
         if(--indegree[edg] == 0){
            q.push(edg);
         }
      }
   }
   cout << ans%MOD << endl;
   return 0;
}

