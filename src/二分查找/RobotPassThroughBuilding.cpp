// 机器人跳跃问题
// 机器人正在玩一个古老的基于DOS的游戏
// 游戏中有N+1座建筑，从0到N编号，从左到右排列
// 编号为0的建筑高度为0个单位，编号为i的建筑的高度为H(i)个单位
// 起初机器人在编号为0的建筑处
// 每一步，它跳到下一个（右边）建筑。假设机器人在第k个建筑，且它现在的能量值是E
// 下一步它将跳到第个k+1建筑
// 它将会得到或者失去正比于与H(k+1)与E之差的能量
// 如果 H(k+1) > E 那么机器人就失去H(k+1)-E的能量值，否则它将得到E-H(k+1)的能量值
// 游戏目标是到达第个N建筑，在这个过程中，能量值不能为负数个单位
// 现在的问题是机器人以多少能量值开始游戏，才可以保证成功完成游戏
// 测试链接 : https://www.nowcoder.com/practice/7037a3d57bbd4336856b8e16a9cafd71
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过

#include <iostream>
#include <vector>
using namespace std;

bool isOk(vector<long>& energy, long long start, long emax) {
   for (auto e : energy) {
      start += (start - e);
      if (start >= emax) return true;
      if (start < 0) return false;
   }
   return true;
}

int main() {
   long n;
   cin >> n;
   vector<long> energy(n, 0);
   long tmp;
   for (int i = 0; i < n; i++) {
      cin >> energy[i];
   }
   long emax = 0;
   for (auto e : energy) {
      emax = max(emax, e);
   }
   long l = 0;
   long r = emax;
   long ans = 0;
   while (l <= r) {
      long long m = l + (r - l) / 2;
      if (isOk(energy, m, emax)) {
         ans = m;
         r = m - 1;
      } else {
         l = m + 1;
      }
   }
   cout << ans;
   return 0;
}
// 64 位输出请用 printf("%lld")

