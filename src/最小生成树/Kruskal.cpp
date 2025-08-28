// Kruskal算法模版（洛谷）
// 静态空间实现
// 测试链接 : https://www.luogu.com.cn/problem/P3366
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下所有代码，把主类名改成Main，可以直接通过

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int MAXN = 5001;
vector<int> father(MAXN);

void build(int n){
   for(int i = 1; i <= n; i++){
      father[i] = i;
   }
}
int findf(int i){
   if(i != father[i]){
      father[i] = findf(father[i]);
   }
   return father[i];
}

bool Union(int x, int y){
   int fx = findf(x);
   int fy = findf(y);
   if(fx != fy){
      father[fx] = fy;                       //! 这里要更新整条分支，因此是fx
      return true;
   }
   else{
      return false;
   }
}


int main(){
   int N,M;
   cin >> N >> M;
   vector<vector<int>> graph(M,vector<int>(3));
   for(int i = 0; i < M; i++){
      cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
   }
   sort(graph.begin(),graph.end(),[](const vector<int>& a, const vector<int>& b){
      return a[2] < b[2];
   });


   //build
   build(N);
   int ans = 0;
   int count = 0;
   for(int i = 0; i < M; i++){
      if(Union(graph[i][0],graph[i][1])){
         ans += graph[i][2];
         count++;
      }
   }
   if(count == N - 1){
      cout << ans;
   }
   else{
      cout << "orz";
   }
   return 0;
}

