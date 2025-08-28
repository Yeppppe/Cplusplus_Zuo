#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
   srand(time(0));
   int index = rand()%100;  //! 生成0 - 99之间的数字
   return 0;
}