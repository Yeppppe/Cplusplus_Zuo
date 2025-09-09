// https://leetcode.cn/problems/clone-graph/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


//! 广度优先搜索的方法
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        unordered_map<Node*, Node*> map;
        Node* head = new Node(node -> val);
        map[node] = head;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            for(auto n : cur -> neighbors){
                if(!map.count(n)){
                    Node* node_new = new Node(n -> val);
                    map[n] = node_new;
                    map[cur] -> neighbors.push_back(node_new);
                    q.push(n);
                }
                else{
                    map[cur] -> neighbors.push_back(map[n]);
                }
            }
        }
        return head;
    }
};



//! 深度优先搜索（递归版本）
class Solution2 {
public:
    unordered_map<Node*, Node*> map;
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        if(map.count(node)) return map[node];
        map[node] = new Node(node -> val);
        for(auto neighbor : node -> neighbors){
            map[node] -> neighbors.push_back(cloneGraph(neighbor));
        }

        return map[node];
    }
};