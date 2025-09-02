// https://leetcode.cn/problems/lru-cache/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <unordered_map>
using namespace std;
struct DLinkNode{
   int key;
   int value;
   DLinkNode* pre;
   DLinkNode* next;
   DLinkNode():key(0),value(0),pre(nullptr),next(nullptr){}
   DLinkNode(int k, int v):key(k),value(v),pre(nullptr),next(nullptr){}
};

class LRUCache {
private:
   unordered_map<int, DLinkNode*> cache;
   DLinkNode* head;
   DLinkNode* tail;
   int size;
   int capacity;
public:
   LRUCache(int capacity) {
       head = new DLinkNode();
       tail = new DLinkNode();
       this -> capacity = capacity;
       head -> next = tail;
       tail -> pre = head;
       size = 0;
   }
   
   int get(int key) {
       if(!cache.count(key)){
           return -1;
       }
       else{
           DLinkNode* cur = cache[key];
           moveToHead(cur);
           return cur-> value;
       }
   }
   
   void put(int key, int value) {
       if(cache.count(key)){
           DLinkNode* cur = cache[key];
           cur -> value = value;
           moveToHead(cur);
       }
       else{
           cache[key] =new DLinkNode(key,value);
           addToHead(cache[key]);
           size++;
           if(size > capacity){
               DLinkNode* last = removeTail();
               cache.erase(last -> key);
               size--;
               delete last;
           }
       }
   }

   void removeNode(DLinkNode* node){
       node -> pre -> next = node -> next;
       node -> next -> pre = node -> pre;
   }
   void moveToHead(DLinkNode* node){
       removeNode(node);
       addToHead(node);
   }

   void addToHead(DLinkNode* node){
       node -> pre = head;
       node -> next = head -> next;
       head -> next -> pre = node;
       head -> next = node;
   }

   DLinkNode* removeTail(){
       DLinkNode *last = tail -> pre;
       removeNode(last);
       return last;
   }
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/

