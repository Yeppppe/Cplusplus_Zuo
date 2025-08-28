// https://leetcode.cn/problems/merge-two-sorted-lists/?envType=study-plan-v2&envId=top-interview-150

#include <climits>
struct ListNode{
   int val;
   ListNode* next;
   ListNode(int val):val(val),next(nullptr){}
   ListNode(int val, ListNode* next): val(val),next(next){}
};

class Solution {
public:
   ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode* head = new ListNode(0);
      ListNode* res = head;
      while(list1 != nullptr || list2 != nullptr){
         int n1 = list1 != nullptr ? list1 -> val : INT_MAX;
         int n2 = list2 != nullptr ? list2 -> val : INT_MAX;

         if(n1 <= n2){
               res -> next = new ListNode(n1);
               res = res -> next;
               list1 = list1->next;
         }
         else{
               res -> next = new ListNode(n2);
               res = res -> next;
               list2 = list2->next;
         }
      }
      return head -> next;
   }
};