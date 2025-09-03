// https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <queue>
using namespace std;
class Node {
public:
   int val;
   Node* left;
   Node* right;
   Node* next;

   Node() : val(0), left(NULL), right(NULL), next(NULL) {}

   Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

   Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
   Node* connect(Node* root) {
      if(root == nullptr) return root;
      queue<Node*> q;
      q.push(root);
      while(!q.empty()){
         int sz = q.size();
         while(sz--){
               Node* cur = q.front();
               q.pop();
               if(sz == 0){                  //! while是先判断条件，进入循环 再将条件--
                  cur -> next = nullptr;
               }
               else{
                  cur -> next = q.front();
               }
               if(cur -> left != nullptr) q.push(cur -> left);
               if(cur -> right != nullptr) q.push(cur -> right);
         }
      }
      return root;
   }
};