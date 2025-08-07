// 合并K个有序链表
// 测试链接：https://www.nowcoder.com/practice/65cfde9e5b9b4cf2b6bafa5f3ef33fa6


/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode{
   int val;
   ListNode* next;
   ListNode(int x): val(x),next(nullptr){}
};


class Solution {
public:
   struct Compare{
      bool operator()(ListNode* a, ListNode* b){
         return a->val > b->val;
      }
   };
   ListNode* mergeKLists(vector<ListNode*>& lists) {
      // write code here
      priority_queue<ListNode*,vector<ListNode*>,Compare> heap;
      for(auto node : lists){
         if(node != nullptr)
            heap.push(node);
      }
      if(heap.empty()) return nullptr;

      ListNode* head = heap.top();
      heap.pop();
      if(head->next != nullptr) heap.push(head->next);
      ListNode* cur = head;
      while(!heap.empty()){
         ListNode* next = heap.top();
         heap.pop();
         if(next->next != nullptr){
            heap.push(next->next);
         }
         cur->next = next;
         cur = next;
      }

      return head;
   }
};