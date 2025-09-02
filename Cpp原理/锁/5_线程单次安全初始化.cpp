// call_once

#include <mutex>

std::once_flag flag;

void init_heavy();

void use(){
   std::call_once(flag, init_heavy);   //多线程下仅执行一次
}