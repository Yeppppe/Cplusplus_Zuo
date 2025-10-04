// https://leetcode.cn/problems/merge-two-sorted-lists/description/?envType=study-plan-v2&envId=top-100-liked

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(0);
        ListNode* head = dummyNode;
        while(list1 != nullptr && list2 != nullptr){
            if(list1 -> val < list2 -> val){
                head -> next = new ListNode(list1 -> val);
                head = head -> next;
                list1 = list1 -> next;
            }
            else{
                head -> next = new ListNode(list2 -> val);
                head = head -> next;
                list2 = list2 -> next;
            }
        }

        if(list1){
            head -> next = list1;
        }
        else{
            head -> next = list2;
        }
        return dummyNode -> next;
    }
};