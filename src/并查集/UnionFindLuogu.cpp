// 并查集模版(洛谷)
// 本实现用递归函数实现路径压缩，而且省掉了小挂大的优化，一般情况下可以省略
// 测试链接 : https://www.luogu.com.cn/problem/P3367
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过


#include <iostream>
#include <vector>

using namespace std;

vector<int> father(200001);

void build(int n){
   for(int i = 1; i <= n; i++){
      father[i] = i;
   }
}
int find(int a){
   if(a != father[a]){
      father[a] = find(father[a]);
   }
   return father[a];                   //! 并不是说
}

bool is_sameunion(int a,int b){
   return find(a) == find(b);
}

void merge(int a, int b){       
   father[find(a)] = find(b);     //! 注意这个merge 是找代表之间的father关系！
}

int main(){
   int n, m;
   cin >> n >> m;
   build(n);
   int a,b,opt;
   while(m--){
      cin >> opt >> a >> b;
      if(opt == 1){
         merge(a,b);
      }
      else{
         char s = is_sameunion(a,b) ? 'Y' : 'N';
         cout << s << endl;
      }
   }
   return 0;
}