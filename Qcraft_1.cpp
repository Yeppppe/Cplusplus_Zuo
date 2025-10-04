#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>
#include <vector>
using namespace std;
queue<int> tast_queue;
mutex mtx;
condition_variable cond;

void prodecer(int x){
    for(int i = 0; i < 3; i++)
    {
        unique_lock<mutex> mtx;
        tast_queue.push(x);
        cond.notify_one();
    }
}

int consumer(){
    while(true){
        {
            unique_lock<mutex> mtx;
            cond.wait(mtx , !tast_queue.empty());
            if(!tast_queue.empty()){
                int tar = tast_queue.front();
                tast_queue.pop();
            }
        }
    }
}


int main(){

    thread t1(prodecer, 7);
    thread c1(consumer);

    t1.join();
    c1.join();
}