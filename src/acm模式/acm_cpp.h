//* 来自牛客
#include <iostream>
//1. 读入单个数据
int num;
cin >> num;
cout << num << endl;


//* cin
#include <vector>
//2. 批量读入多个数据
vector<int> nums(5);
for (int i =0; i< nums.size(); i++){
    cin >> nums[i];
}
//* 输出读入的数组
for (int i=0; i< nums.size(); i++){
    cout << nums[i] << " ";
}


//* getline()
//* 从cin的注意中，也可以看出，当我们要求读取的字符串中间存在空格的时候，cin会读取不全整个字符串，这个时候，可以采用getline()函数来解决。
