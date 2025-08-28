// https://leetcode.cn/problems/add-two-numbers/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
using namespace std;
struct ListNode{
   int val;
   ListNode* next;
   ListNode(int x):val(x),next(nullptr){}
   ListNode(int x, ListNode* next):val(x),next(next){};
};


class Solution {
public:
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int carry = 0;
      ListNode* head = new ListNode(0);
      int sum = 0;
      ListNode* res = head;
      while(l1 != nullptr || l2 != nullptr || carry != 0){
         int n1 = l1 == nullptr ? 0 : l1 -> val;
         int n2 = l2 == nullptr ? 0 : l2 -> val;
         sum = n1 + n2 + carry;
         int val = sum%10;
         carry = sum/10;

         res -> next = new ListNode(val);
         res = res -> next;
         l1 = l1 == nullptr ? l1 : l1 -> next;
         l2 = l2 == nullptr ? l2 : l2 -> next;
      }
      return head -> next;
   }
};