// https://leetcode.cn/problems/reverse-nodes-in-k-group/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>

struct ListNode{
   int val;
   ListNode* next;
   ListNode(int x) : val(x), next(nullptr){}
   ListNode(int x, ListNode* next) : val(x), next(next){}
};
class Solution {
public:
   ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode* dummyNode = new ListNode(-1);
      dummyNode -> next = head;
      ListNode* pre = dummyNode;
      ListNode* start = nullptr;
      ListNode* end = nullptr;
      ListNode* next = nullptr;
      while(true){
         start = pre -> next;
         end = teamEnd(start , k);
         if(end == nullptr) return dummyNode -> next;
         next = end -> next;
         reverseK(start,end);

         pre -> next = end;
         start -> next = next;
         pre = start;
      }
      return dummyNode -> next;
   }

   void reverseK(ListNode* start, ListNode* end){
      ListNode* pre = nullptr;
      ListNode* cur = start;
      ListNode* next = nullptr;
      while(cur != end){
         next = cur -> next;
         cur -> next = pre;
         pre = cur;
         cur = next;
      }
      cur -> next = pre;
   }

   //! 要么返回一个node 指向的下一个值，要么没那么多返回值直接返回nullptr
   ListNode* teamEnd(ListNode* start, int k){
      ListNode* node = start;
      while(node != nullptr && --k){
         node = node -> next;
      }
      return node;
   }
};