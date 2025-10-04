// https://leetcode.cn/problems/copy-list-with-random-pointer/?envType=study-plan-v2&envId=top-100-liked

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        for(Node* node = head; node != nullptr; node = node -> next -> next){
            Node* newnode = new Node(node -> val);
            Node* next = node -> next;
            node -> next = newnode;
            newnode -> next = next;
        }

        for(Node* node = head; node != nullptr; node = node -> next -> next){
            Node* copynode = node -> next;
            copynode -> random = node -> random != nullptr ? node -> random -> next : nullptr;
        }
        Node* newhead = head -> next;
        for(Node* node = head; node != nullptr; node = node -> next){
            Node* copynode = node -> next;
            Node* next = copynode -> next;
            node -> next = next;
            copynode -> next = next != nullptr ? next -> next : nullptr;
        }

        return newhead;
    }
};
