// https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;
struct ListNode{
   int val;
   ListNode* next;
   ListNode(int x) : val(x),next(nullptr){}
};
class Solution {
public:
   ListNode* deleteDuplicates(ListNode* head) {
      unordered_map<int,int> map;
      set<int> set;
      while(head != nullptr){
         int val = head -> val;
         if(map.count(val)){
               map[val]++;
         }
         else{
               map[val] = 1;
         }
         set.insert(val);
         head = head -> next;
      }
      vector<int> que;
      ListNode* dummynode = new ListNode(-1);
      ListNode* prenode = dummynode;
      for(auto n : set){
         if(map[n] == 1){
               ListNode* node = new ListNode(n);
               prenode -> next = node;
               prenode = node;
         }
      }
      return dummynode -> next;
   }
};



class Solution {
public:
   ListNode* deleteDuplicates(ListNode* head) {
      if(head == nullptr) return nullptr;
      ListNode* dummyNode = new ListNode(-1);
      dummyNode -> next = head;
      ListNode* node  = dummyNode;
      while(node -> next != nullptr && node -> next -> next !=nullptr){
         if(node -> next -> val == node -> next -> next -> val){
               int x = node -> next -> val;
               while(node -> next && node -> next -> val == x){
                  node -> next = node -> next -> next;
               }
         }
         else{
               node = node -> next;
         }
      }
      return dummyNode -> next;
   }
};
   