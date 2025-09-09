// https://leetcode.cn/problems/find-median-from-data-stream/?envType=study-plan-v2&envId=top-interview-150

#include <queue>
using namespace std;
class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minheap.empty() || num >= minheap.top()){
            minheap.push(num);
        }
        else{
            maxheap.push(num);
        }
        balance();
    }
    
    double findMedian() {
        if(minheap.size() == maxheap.size()){
            return (minheap.top() + maxheap.top())/2.0;
        }
        return minheap.size() > maxheap.size() ? minheap.top() : maxheap.top();
    }

    void balance(){
        while(minheap.size() > maxheap.size() + 1){
            maxheap.push(minheap.top());
            minheap.pop();
        }
        while(maxheap.size() > minheap.size() + 1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }
};