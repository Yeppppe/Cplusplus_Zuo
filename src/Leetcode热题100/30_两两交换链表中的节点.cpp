// https://leetcode.cn/problems/swap-nodes-in-pairs/description/?envType=study-plan-v2&envId=top-100-liked

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode -> next = head;
        ListNode* pre = dummyNode;
        while(pre -> next != nullptr && pre -> next -> next != nullptr){
            ListNode* cur = pre -> next;
            ListNode* next = pre -> next -> next;

            cur -> next = next -> next;
            next -> next = cur;
            pre -> next = next;

            pre = cur;
        }
        return dummyNode -> next;
    }
};