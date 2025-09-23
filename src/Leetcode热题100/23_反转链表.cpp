// https://leetcode.cn/problems/reverse-linked-list/submissions/665320446/?envType=study-plan-v2&envId=top-100-liked
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
    ListNode* reverseList(ListNode* head) {
        ListNode* node = head;
        ListNode* pre = nullptr;
        while(node != nullptr){
            ListNode* next = node -> next;
            node -> next = pre;
            pre = node;
            node = next;
        }
        return pre;
    }
};
