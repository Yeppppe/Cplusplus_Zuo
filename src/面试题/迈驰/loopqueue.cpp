#include <cstdint>

template <std::size_t S>
class CircularBuffer {
private:
    int data[S];
    std::size_t head = 0;  // 队列头部索引
    std::size_t tail = 0;  // 队列尾部索引
    bool is_full = false;  // 标记队列是否已满
 
public:
    // 当前缓冲区中的数据长度
    std::size_t length() {
        if (is_full) return S;
        if (head <= tail) return tail - head;
        return S - head + tail;
    }
  
    // 尝试入队一个元素。如果缓冲区满返回 false
    bool try_push(int val) {
        if (is_full) return false;
        
        data[tail] = val;
        tail = (tail + 1) % S;
        
        // 如果 tail 追上 head，说明队列已满
        if (tail == head) is_full = true;
        
        return true;
    }
  
    // 强制入队一个元素。如果缓冲区满则抛弃最旧的数据
    void force_push(int val) {
        if (is_full) {
            // 如果已满，移动 head 指针，抛弃最旧的数据
            head = (head + 1) % S;
        }
        
        data[tail] = val;
        tail = (tail + 1) % S;
        
        // 检查是否已满
        if (tail == head) is_full = true;
    }
  
    // 尝试弹出一个元素并写入 val。如果缓冲区空则返回 false
    bool try_pop(int& val) {
        // 如果 head 等于 tail 且队列不满，说明队列为空
        if (head == tail && !is_full) return false;
        
        val = data[head];
        head = (head + 1) % S;
        is_full = false;  // 弹出后队列一定不满
        
        return true;
    }
};
