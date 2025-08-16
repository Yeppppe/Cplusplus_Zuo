// 字典序最小的拓扑排序
// 要求返回所有正确的拓扑排序中 字典序最小 的结果
// 建图请使用链式前向星方式，因为比赛平台用其他建图方式会卡空间
// 测试链接 : https://www.luogu.com.cn/problem/U107394
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下所有代码，把主类名改成Main，可以直接通过

//! 已经通过！！！！！！！！！！！！！！！！！
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(){
   int n,m;
   cin >> n >> m;
   vector<vector<int>> edges(m,vector<int>(2));
   for(int i = 0; i < m; i++){
      cin >> edges[i][0] >> edges[i][1];    //* 表示从0 -> 1的边
   }
   vector<vector<int>> graph(n + 1);
   vector<int> indegree(n , 0);
   priority_queue<int,vector<int>,greater<int>> q;

   for(int i = 0; i < m; i++){
      graph[edges[i][0]].push_back(edges[i][1]);
      indegree[edges[i][1]]++;
   }

   for(int i = 1; i <= n; i++){          //! 注意节点是从1还是从0开始的
      if(indegree[i] == 0){
         q.push(i);
      }
   }
   vector<int> ans;
   while(!q.empty()){
      int cur = q.top();
      q.pop();
      ans.push_back(cur);
      for(auto n : graph[cur]){
         if(--indegree[n] == 0){
            q.push(n);
         }
      }
   }
   
   for (int i = 0; i < ans.size(); i++) {
      if (i > 0) cout << " ";  // 除第一个元素外，前面加空格
      cout << ans[i];
  }
  cout << endl;
   return 0;
}

