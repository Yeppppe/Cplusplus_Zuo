// https://leetcode.cn/problems/linked-list-cycle-ii/?envType=study-plan-v2&envId=top-100-liked

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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(true){
            if(fast -> next == nullptr || fast -> next -> next == nullptr) return nullptr;
            fast = fast -> next -> next;
            slow = slow -> next;
            if(slow == fast) break;
        }

        fast = head;
        while(fast != slow){
            fast = fast -> next;
            slow = slow -> next;
        }
        return fast;
    }
};