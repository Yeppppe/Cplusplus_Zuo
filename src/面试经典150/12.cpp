// https://leetcode.cn/problems/insert-delete-getrandom-o1/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <unordered_map>
using namespace std;


class RandomizedSet {
   vector<int> arr;
   unordered_map<int,int> map;
public:
   RandomizedSet() {
      srand((unsigned)time(NULL));
   }
   
   bool insert(int val) {
      if(map.find(val) != map.end()){
         return false;
      }
      arr.push_back(val);
      map[val] = arr.size()-1;
      return true;
   }
   
   bool remove(int val) {
      if(map.find(val) != map.end()){
         int cur_index = map[val];
         arr[cur_index] = arr.back();
         map[arr.back()] = cur_index;
         map.erase(val);
         arr.pop_back();
         return true;
      }
      else{
         return false;
      }
   }
   
   int getRandom() {
      return arr[rand()%arr.size()];    //! rand会随机生成一个大整数（范围再 0 ~ RAND_MAX之间）
   }
};



// C++ 随机数
#include <random>

int getRandomBetter(int min, int max) {
    random_device rd;
    mt19937 gen(rd()); // 高质量随机数引擎
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}
