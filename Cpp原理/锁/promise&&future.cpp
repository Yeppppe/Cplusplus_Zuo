#include <future>
#include <iostream>

void compute_pi(const long num_steps, std::promise<double>& promise){
   double step = 1.0 / num_steps;
   double sum = 0.0;
   for(long i = 0; i < num_steps; i++){
      double x = (i + 0.5)*step;
      sum += 4.0 / (1.0 + x*x);
   }
   promise.set_value(sum * step);
}


void display(std::future<double>& receiver){
   double pi = receiver.get();
   std::cout << "返回值 = " << pi << std::endl;
}



int main(){
   const int N_STEPS = 100000000;
   std::promise<double> promise;
   auto receiver = promise.get_future();
   std::thread th1(compute_pi,N_STEPS,std::ref(promise));
   std::thread th2(display,std::ref(receiver));
   th1.join();
   th2.join();
   return 0;
}



//! 防止promise 和 receiver被提前销毁导致引用未定义的行为，建议使用移动语义, compute_pi以及display需要改成右值引用
void compute_pi2(const long num_steps, std::promise<double>&& promise){}

void display2(std::future<double>&& receiver){}
int main(void){
   const int N_STEPS = 10000000;
   std::thread th1;
   std::thread th2;
   {
      std::promise<double> promise;
      auto receiver = promise.get_future();
      th1 = std::thread(compute_pi2, N_STEPS, std::move(promise));    //! 原有对象被销毁也不影响当前的值
      th2 = std::thread(display2, std::move(receiver));
   }

   th1.join();
   th2.join();
}



