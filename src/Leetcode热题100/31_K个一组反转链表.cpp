// https://leetcode.cn/problems/reverse-nodes-in-k-group/?envType=study-plan-v2&envId=top-100-liked

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode -> next = head;
        ListNode* pre = dummyNode;
        while(true){
            ListNode* start = pre -> next;
            ListNode* end = pre;
            for(int i = 0; i < k && end; i++){
                end = end -> next;
            }

            if(end == nullptr) break;

            ListNode* next = end -> next;

            reverseK(start, end);

            pre -> next = end;
            start -> next = next;

            pre = start;
        }
        return dummyNode -> next;
    }

    void reverseK(ListNode* start, ListNode* end){
        ListNode* cur = start;
        ListNode* pre = end -> next;
        ListNode* stop = pre;
        while(cur != stop){
            ListNode* next = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = next;
        }
    }
};
