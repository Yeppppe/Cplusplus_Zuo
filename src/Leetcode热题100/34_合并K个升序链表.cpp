// https://leetcode.cn/problems/merge-k-sorted-lists/solutions/219756/he-bing-kge-pai-xu-lian-biao-by-leetcode-solutio-2/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return nullptr;
        if(n == 1) return lists[0];
        ListNode* listn = merge2(lists[0], nullptr);
        for(int i = 1; i < n; i++){
            listn = merge2(listn, lists[i]);
        }
        return listn;
    }
    ListNode* merge2(ListNode* list1, ListNode* list2){
        ListNode* dummynode = new ListNode(0);
        ListNode* node = dummynode;
        while(list1 && list2){
            int a = list1 -> val;
            int b = list2 -> val;
            if(a < b){
                node -> next = list1;
                list1 = list1 -> next;
            }
            else{
                node -> next = list2;
                list2 = list2 -> next;
            }
            node = node -> next;
        }
        if(list1){
            node -> next = list1;
        }
        if(list2){
            node -> next = list2;
        }
        return dummynode -> next;
    }
};