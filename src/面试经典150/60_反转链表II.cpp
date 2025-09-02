// https://leetcode.cn/problems/reverse-linked-list-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
struct ListNode{
   int val;
   ListNode *next;
   ListNode():val(0), next(nullptr){}
   ListNode(int x): val(x), next(nullptr){}
   ListNode(int x, ListNode* next): val(x),next(next){}
};

class Solution {
private:
   void reserveLinkedList(ListNode* head){
      ListNode* pre = nullptr;
      ListNode* cur = head;
      while(cur != nullptr){
         ListNode *next = cur -> next;
         cur -> next = pre;
         pre = cur;
         cur = next;
      }
   }
public:
   ListNode* reverseBetween(ListNode* head, int left, int right) {
      ListNode* dummyNode = new ListNode(-1);
      dummyNode -> next = head;

      ListNode* pre = dummyNode;
      for(int i = 0; i < left - 1; i++){
         pre = pre -> next;
      }

      ListNode* rightNode = pre;
      for(int i = left -1; i < right; i++){
         rightNode = rightNode -> next;
      }

      ListNode* leftNode = pre -> next;
      ListNode* curr = rightNode -> next;

      pre -> next = nullptr;
      rightNode -> next = nullptr;

      reserveLinkedList(leftNode);
      pre -> next = rightNode;
      leftNode -> next = curr;
      return dummyNode->next;
   }
};