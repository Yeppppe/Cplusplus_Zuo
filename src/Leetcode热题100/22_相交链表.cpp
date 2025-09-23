// https://leetcode.cn/problems/intersection-of-two-linked-lists/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;
        int countA = 0;
        int countB = 0;
        ListNode* nodea = headA;
        ListNode* nodeb = headB;
        while(nodea){
            countA++;
            nodea = nodea -> next;
        }
        while(nodeb){
            countB++;
            nodeb = nodeb -> next;
        }
     
        if(countA > countB){
            nodea = headA;
            nodeb = headB;
        }
        else{
            nodea = headB;
            nodeb = headA;
        }
        int diff = abs(countA - countB);
        while(diff--){
            nodea = nodea -> next;
        }
        while(nodea!=nullptr && nodeb != nullptr){
            if(nodea == nodeb) return nodea;
            else{
                nodea = nodea -> next;
                nodeb = nodeb -> next;
            }
        }
        return nullptr;
    }
};