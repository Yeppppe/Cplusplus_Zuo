// https://leetcode.cn/problems/copy-list-with-random-pointer/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <unordered_map>
using namespace std;
// 1. 递归解法
class Node {
public:
   int val;
   Node* next;
   Node* random;
   
   Node(int _val) {
      val = _val;
      next = nullptr;
      random = nullptr;
   }
};

class Solution {
private:
   unordered_map<Node*, Node*> map;
public:
   Node* copyRandomList(Node* head) {
      if(head == nullptr){
         return nullptr;
      }    

      while(!map.count(head)){
         Node* newnode = new Node(head -> val);
         map[head] = newnode;
         newnode -> next = copyRandomList(head -> next);
         newnode -> random = copyRandomList(head -> random);
      }
      return map[head];
   }
};


// 2. 正常迭代 + 节点拆分的写法
class Solution {
public:
   Node* copyRandomList(Node* head) {
      if(head == nullptr){
         return nullptr;
      }

      for(Node* node = head; node != nullptr; node = node -> next -> next){
         Node* nodenew = new Node(node -> val);
         nodenew -> next = node -> next;
         node -> next = nodenew;
      }

      for(Node* node = head; node != nullptr; node = node -> next -> next){
         Node* nodenew = node -> next;
         nodenew -> random = (node -> random == nullptr) ? nullptr : node -> random -> next;
      }

      Node* head_cur = head -> next;
      for(Node* node = head; node != nullptr; node = node -> next){
         Node* nodenew = node -> next;
         node -> next = node -> next -> next;
         nodenew -> next = (nodenew -> next != nullptr) ? nodenew -> next -> next: nullptr;
      }
      return head_cur;
   }
};
