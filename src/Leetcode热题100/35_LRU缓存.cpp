// https://leetcode.cn/problems/lru-cache/description/?envType=study-plan-v2&envId=top-100-liked

#include <unordered_map>
using namespace std;
struct DoubleListNode{
    DoubleListNode* pre;
    DoubleListNode* next;
    int key;
    int val;
    DoubleListNode():key(0),val(0),pre(nullptr),next(nullptr){}
    DoubleListNode(int k, int v):key(k),val(v),pre(nullptr),next(nullptr){};
};

class LRUCache {
private:
    int capacity;
    DoubleListNode* head;
    DoubleListNode* tail;
    unordered_map<int, DoubleListNode*> map;
    int size;
public:
    LRUCache(int capacity) {
        head = new DoubleListNode();
        tail = new DoubleListNode();
        this->capacity = capacity;
        size = 0;
        head -> next = tail;
        tail -> pre = head;
    }
    
    int get(int key) {
        if(map.count(key)){
            movetohead(map[key]);
            return map[key] -> val;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(map.count(key)){
            map[key] -> val = value;
            movetohead(map[key]);
        }
        else{
            DoubleListNode* node = new DoubleListNode(key, value);
            map[key] = node;
            if(size == capacity){
                removetail();
            }
            addTohead(node);
            size++;
        }
    }

    void addTohead(DoubleListNode* node){
        DoubleListNode* cur_head = head -> next;
        head -> next = node;
        cur_head -> pre = node;
        node -> pre = head;
        node -> next = cur_head;
    }

    void movetohead(DoubleListNode* node){
        node -> pre -> next = node -> next;
        node -> next -> pre = node -> pre;
        DoubleListNode* first = head -> next;
        head -> next = node;
        first -> pre = node;
        node -> next = first;
        node -> pre = head;
    }

    void removetail(){
        DoubleListNode* lastnode = tail -> pre;
        lastnode -> pre -> next = tail;
        tail -> pre = lastnode -> pre;
        map.erase(lastnode -> key);
        size--;
        delete lastnode;
    }
};
