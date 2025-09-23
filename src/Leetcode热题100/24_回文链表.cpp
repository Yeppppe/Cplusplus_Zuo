// https://leetcode.cn/problems/palindrome-linked-list/description/?envType=study-plan-v2&envId=top-100-liked
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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        //偶数
        if(fast != nullptr){
            slow = slow -> next;
        }

        ListNode* pre = nullptr;
        while(slow){
            ListNode* cur = slow -> next;
            slow -> next = pre;
            pre = slow;
            slow = cur;
        }

        while(pre){
            if(pre -> val != head -> val){
                return false;
            }
            pre = pre -> next;
            head = head -> next;
        }
        return true;
    }
};