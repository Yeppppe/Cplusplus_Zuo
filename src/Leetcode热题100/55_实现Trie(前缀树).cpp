// https://leetcode.cn/problems/implement-trie-prefix-tree/description/?envType=study-plan-v2&envId=top-100-liked

#include <string>
using namespace std;


class Trie {
private:
    struct TrieNode{
        int pass;
        int end;
        TrieNode* next[26];
        TrieNode():pass(0),end(0){
            for(int i = 0; i < 26; i++){
                next[i] = nullptr;
            }
        }
    };
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        root -> pass++;
        for(auto c : word){
            int path = c - 'a';
            if(node -> next[path] == nullptr){
                node -> next[path] = new TrieNode();
            }
            node = node -> next[path];
            node -> pass++;
        }
        node -> end++;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(auto c : word){
            int path = c - 'a';
            if(node -> next[path] == nullptr) return false;
            node = node -> next[path];
        }
        return node -> end > 0;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(auto c : prefix){
            int path = c - 'a';
            if(node -> next[path] == nullptr) return false;
            node = node -> next[path];
        }
        return true;
    }
};
