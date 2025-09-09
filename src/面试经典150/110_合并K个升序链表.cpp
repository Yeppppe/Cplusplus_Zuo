// https://leetcode.cn/problems/merge-k-sorted-lists/?envType=study-plan-v2&envId=top-interview-150


#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(l1 == nullptr || l2 == nullptr) return l1 == nullptr ? l2 : l1;
        ListNode* head = l1 -> val < l2 -> val ? l1 : l2;
        head == l1 ? (l1 = l1 -> next) : (l2 = l2 -> next);
        ListNode* pre = head;
        while(l1 != nullptr && l2 != nullptr){
            if(l1 -> val < l2 -> val){
                pre -> next = l1;
                pre = l1;
                l1 = l1 -> next;
            }
            else{
                pre -> next = l2;
                pre = l2;
                l2 = l2 -> next;
            }
        }
        if(l1 != nullptr) pre -> next = l1;
        if(l2 != nullptr) pre -> next = l2;
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return nullptr;
        ListNode* head = lists[0];
        if(n == 1) return head;
        for(int i = 1; i < n; i++){
            head = merge(head, lists[i]);
        }
        return head;
    }
};