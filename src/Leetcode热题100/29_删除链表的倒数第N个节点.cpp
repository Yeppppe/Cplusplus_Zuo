// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/?envType=study-plan-v2&envId=top-100-liked


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode -> next = head;
        ListNode* fast = dummyNode;
        ListNode* slow = dummyNode;
        while(n--){
            fast = fast -> next;
        }
        while(fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next;
        }

        slow -> next = slow -> next -> next;
        return dummyNode -> next;
    }
};