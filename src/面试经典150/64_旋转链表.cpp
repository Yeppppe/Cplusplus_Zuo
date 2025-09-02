// https://leetcode.cn/problems/rotate-list/description/?envType=study-plan-v2&envId=top-interview-150
#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
   int val;
   ListNode* next;
   ListNode(): val(0),next(nullptr){}
   ListNode(int x): val(x), next(nullptr){}
};

class Solution {
public:
   ListNode* rotateRight(ListNode* head, int k) {
      vector<int> nums;
      ListNode* node = head;
      while(node != nullptr){
         nums.push_back(node -> val);
         node = node -> next;
      }
      int n = nums.size();
      vector<int> copy(n);
      for(int i = 0; i < n; i++){
         copy[(i + k)%n] = nums[i];
      }
      ListNode* dummynode = new ListNode(-1);
      ListNode* pre = dummynode;
      for(int i = 0; i < n; i++){
         ListNode* node = new ListNode(copy[i]);
         pre -> next = node;
         pre = node;
      }
      return dummynode -> next;
   }
};