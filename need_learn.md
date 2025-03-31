1.随机数字
#include <random>
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(0, 99);  // [0, 99] 范围的随机数
int other = dis(gen)

2.容器算法排序
#include <algorithm>
sort(wealth.begin(),wealth.end());

