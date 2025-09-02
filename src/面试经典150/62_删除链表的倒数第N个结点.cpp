// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/?envType=study-plan-v2&envId=top-interview-150

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
   ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* dummyNode = new ListNode(-1);
      dummyNode -> next = head;
      ListNode* node = head;
      int count = 0;
      while(node != nullptr){
         node = node -> next;
         count++;
      }

      int target = count - n + 1;
      ListNode* tarnode = dummyNode;
      ListNode* pre = nullptr;
      ListNode* next = nullptr;
      // for(int i = 0; i < count; i++){
      //     if(i == target - 1){
      //         pre = tarnode;
      //     }
      //     if(i == target +1){
      //         next = tarnode;
      //     }
      //     tarnode = tarnode -> next;
      // }
      for(int i = 0; i < target - 1; i++){
         tarnode = tarnode -> next;
      }
      tarnode -> next = tarnode -> next -> next;
      return dummyNode -> next;
   }
};