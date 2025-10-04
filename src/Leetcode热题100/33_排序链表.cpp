// https://leetcode.cn/problems/sort-list/?envType=study-plan-v2&envId=top-100-liked
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
    ListNode* sortList(ListNode* head) {
        vector<int> nums;
        while(head != nullptr){
            nums.push_back(head -> val);
            head = head -> next;
        }
        sort(nums.begin(),nums.end());
        ListNode* dummynode = new ListNode(0);
        ListNode* pre = dummynode;
        for(auto n : nums){
            ListNode* node = new ListNode(n);
            pre -> next = node;
            pre = node;
        }
        return dummynode -> next;
    }
};