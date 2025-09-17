#include "SimpleThreadPool.h"



int main(){
    SimpleThreadPool pool(4);   //! 创建4个线程

    for(int i = 0; i < 8; i++){
        pool.enqueue([i]{
            std::cout << "任务" << i << "开始\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));   //! 这种挂起不会占用CPU，但仍然持有锁
            std::cout << "任务" << i << "结束\n";
        });
    }

    return 0;
}