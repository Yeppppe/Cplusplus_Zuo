//* shared_future 专门用于多个线程共享的future
#include <iostream>
#include <future>
#include <mutex>
#include <vector>
std::mutex coutMutex;

void teach(std::promise<void> &&prom){
   std::cout << "上课" << std::endl;
   std::this_thread::sleep_for(std::chrono::seconds(10));
   prom.set_value();      //! 不传递任何值，进传递信号，让其变为就绪状态
   std::cout << "下课\n";
}




void learn(std::shared_future<void> &&sf){
   sf.wait();
   std::lock_guard<std::mutex> guard(coutMutex);
   std::cout << "再见(" << std::this_thread::get_id() << ")" << std::endl;
}


int main(){
   std::promise<void> promise;
   std::shared_future<void> sfuture = promise.get_future();

   std::thread teacher = std::thread(teach, std::move(promise));
   std::vector<std::thread> students;



   for(int i = 0; i < 40; i++){
      students.push_back(std::thread(learn, sfuture));
   }

   teacher.join();
   for(auto& s : students){
      s.join();
   }

   return 0;
}