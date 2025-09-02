// https://leetcode.cn/problems/partition-list/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
   ListNode* partition(ListNode* head, int x) {
      if(head == nullptr || head -> next == nullptr) return head;
      ListNode* head1 = nullptr;
      ListNode* end1 = nullptr;
      ListNode* head2 = nullptr;
      ListNode* end2 = nullptr;
      
      ListNode* node = head;
      while(node != nullptr){
         if(node -> val < x){
               if(head1 == nullptr){
                  end1 = new ListNode(node -> val);
                  head1 = end1;
               }
               else{
                  end1 -> next = new ListNode(node -> val);
                  end1 = end1 -> next;
               }
         }
         else{
               if(head2 == nullptr){
                  end2 = new ListNode(node -> val);
                  head2 = end2;
               }
               else{
                  end2 -> next = new ListNode(node -> val);
                  end2 = end2 -> next;
               }
         }
         node = node -> next;
      }
      if(head1 == nullptr) return head2;
      if(head2 == nullptr) return head1;
      end1 -> next = head2;
      return head1;
   }
};