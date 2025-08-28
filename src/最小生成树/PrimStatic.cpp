// Prim算法优化（洛谷）
// 静态空间实现
// 时间复杂度O(n + m) + O((m+n) * log n)
// 测试链接 : https://www.luogu.com.cn/problem/P3366
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下所有代码，把主类名改成Main，可以直接通过

#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

struct Edge{int to, w;};

struct Cmp{
   bool operator()(const pair<int, int>& a,const pair<int, int>& b) const{
      //!  1 是权重，权重小的优先
      return a.second > b.second;
   }
};

int main(){
   int N,M;
   cin >> N >> M;
   vector<vector<Edge>> graph(N + 1);
   while(M--){
      //! 建图
      int from,to,weight;
      cin >> from >> to >> weight;
      graph[from].push_back({to,weight});
      graph[to].push_back({from,weight});
   }
   set<int> visited;
   priority_queue<pair<int, int>, vector<pair<int, int>>,Cmp> q;

   visited.insert(1);
   for(const auto& edge : graph[1]){
      q.push(make_pair(edge.to, edge.w));
   }
   int ans = 0;
   while(!q.empty()){
      pair<int, int>cur = q.top();
      q.pop();
      int cur_to = cur.first;
      int cur_w = cur.second;
      if(visited.count(cur_to)) continue;

      visited.insert(cur_to);
      ans += cur_w;
      if(visited.size() == N) break;
      for(const auto& edge : graph[cur_to]){
         if(!visited.count(edge.to)){                   //! 注意这里要查询是否存在
            q.push(make_pair(edge.to, edge.w));
         }
      }
   }

   if(visited.size() == N){
      cout << ans << endl;
   }
   else{
      cout << "orz";
   }
   return 0;
}