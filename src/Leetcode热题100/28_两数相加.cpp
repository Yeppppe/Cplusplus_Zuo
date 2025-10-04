// https://leetcode.cn/problems/add-two-numbers/description/?envType=study-plan-v2&envId=top-100-liked

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummyNode = new ListNode(0);
        ListNode* node = dummyNode;
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int a = l1 != nullptr ? l1 -> val : 0;
            int b = l2 != nullptr ? l2 -> val : 0;
            node -> next = new ListNode((a + b + carry)%10);
            carry = (a + b + carry) / 10;
            l1 = l1 != nullptr ? l1 -> next : nullptr;
            l2 = l2 != nullptr ? l2 -> next : nullptr;
            node = node -> next;
        }
        return dummyNode -> next;
    }
};