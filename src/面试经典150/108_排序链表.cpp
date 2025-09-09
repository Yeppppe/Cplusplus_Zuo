// https://leetcode.cn/problems/sort-list/description/?envType=study-plan-v2&envId=top-interview-150
#include <vector>
using namespace std;
#include <algorithm>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//! 取巧的方法
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> nums;
        ListNode* node = head;
        while(node != nullptr){
            nums.push_back(node -> val);
            node = node -> next;
        }
        sort(nums.begin(), nums.end());
        ListNode* dummynode = new ListNode(0);
        ListNode* pre = dummynode;
        for(auto num : nums){
            ListNode* nodenew = new ListNode(num);
            pre -> next = nodenew;
            pre = nodenew;
        }
        return dummynode -> next;
    }
};


//! 归并分治的做法

class Solution {
private:
    ListNode* start;
    ListNode* end;
public:
    ListNode* findEnd(ListNode* root, int k){
        ListNode* node = root;
        while(node -> next != nullptr && --k > 0){
            node = node -> next;
        }
        return node;
    }

    void merge(ListNode* l1, ListNode* r1, ListNode* l2, ListNode* r2){
        if(l1 == nullptr || l2 == nullptr) return;
        ListNode* pre;
        if(l1 -> val < l2 -> val){
            start = l1;
            pre = l1;
            l1 = l1 -> next;
        }
        else{
            start = l2;
            pre = l2;
            l2 = l2 -> next;
        }
        while(l1 != nullptr && l2 != nullptr){
            if(l1 -> val < l2 -> val){
                pre -> next = l1;
                pre = l1;
                l1 = l1 -> next;
            }
            else{
                pre -> next = l2;
                pre = l2;
                l2 = l2 -> next;
            }
        }

        if(l1 != nullptr){
            pre -> next = l1;
            end = r1;
        }
        if(l2 != nullptr){
            pre -> next = l2;
            end = r2;
        }
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == nullptr) return head;
        int n = 0;
        ListNode* node = head;
        while(node != nullptr){
            node = node -> next;
            n++;
        }

        ListNode* l1;
        ListNode* r1;
        ListNode* l2;
        ListNode* r2;
        ListNode* next = nullptr;
        ListNode* lastend = nullptr;
        for(int step = 1; step < n; step = step<< 1){
            l1 = head;
            r1 = findEnd(head, step);
            l2 = r1 -> next;
            r2 = findEnd(l2, step);
            next = r2 -> next;
            r1 -> next = nullptr;
            r2 -> next = nullptr;
            merge(l1, r1, l2, r2);
            head = start;
            lastend = end;
            while(next != nullptr){
                l1 = next;
                r1 = findEnd(l1, step);
                l2 = r1 -> next;
                if(l2 == nullptr){
                    lastend -> next = l1;
                    break;
                }
                r2 = findEnd(l2, step);
                next = r2 -> next;
                r1 -> next = nullptr;
                r2 -> next = nullptr;
                merge(l1,r1,l2,r2);
                lastend -> next = start;
                lastend = end;
            }

        }
        return head;
    }
}; 