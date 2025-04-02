1. 随机数字
#include <random>
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(0, 99);  // [0, 99] 范围的随机数
int other = dis(gen)

2. 容器算法排序
#include <algorithm>
sort(wealth.begin(),wealth.end());

3. vector resize与reserve的区别
.resize(size_num,0) : resize 无论当下vector有多少元素，都会重新设置未size_num个，0为未没有初值的附初值，对于已有的元素，值不会改变
.reserve(reserve_num) : 相当于一种提前留好位置


4. sscanf : 从一个字符串中读取格式化输入（但必须是c风格字符串，如果是string需要使用.c_str()进行转换）
  .substr(start,end-start): 是string类的一个成员函数，用来提取string的字串，字串索引[start,end) 
  sscanf(num_string.substr(start,end-start).c_str(),"%d",&bit);  将num_string 提取从start开始提取长度未end-start的字串，以10进制存入bit中

5. sprintf(char* buffer , const char* format, ...)  将...以format(需要是c字符串)转换到buffer中