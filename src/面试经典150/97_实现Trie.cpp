// https://leetcode.cn/problems/implement-trie-prefix-tree/description/?envType=study-plan-v2&envId=top-interview-150

#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
//! 固定数组形式的前缀树 但是14/16不知道为啥
class Trie {
private:
    static const int MAXN = 100000;
    int trie[MAXN][26];
    int pass[MAXN];
    int end[MAXN];
    int nodecount;
public:
    Trie() {
        nodecount = 1;
        memset(trie, 0, sizeof(trie));
        memset(pass, 0, sizeof(pass));
        memset(end, 0, sizeof(end));
    }
    
    void insert(string word) {
        if(word.empty()) return;
        int cur = 1;
        pass[cur]++;
        for(auto c : word){
            int path = c - 'a';
            if(trie[cur][path] == 0){
                trie[cur][path] = nodecount++;
            }
            cur = trie[cur][path];
            pass[cur]++;
        }
        end[cur]++;
    }
    
    bool search(string word) {
        if(word.empty()) return false;
        int cur = 1;
        int path;
        for(auto c : word){
            path = c - 'a';
            cur = trie[cur][path];
            if(cur == 0)
                return false;
        }
        return end[cur] > 0;
    }
    
    bool startsWith(string prefix) {
        if(prefix.empty()) return false;
        int cur = 1;
        int path;
        for(auto c : prefix){
            path = c - 'a';
            if(trie[cur][path] == 0) return false;
            cur = trie[cur][path];
        }
        return true;
    }
};




//! 类的形式  可以完全通过
class Trie2 {
private:
    struct TireNode{
        int pass;
        int end;
        TireNode* next[26];
        TireNode():pass(0),end(0){
            for(int i = 0; i < 26; i++){
                next[i] = nullptr;
            }
        }
    };
    TireNode* root;
public:
    Trie2() {
        root = new TireNode();
    }
    
    void insert(string word) {
        TireNode* node = root;
        root -> pass++;
        for(auto c : word){
            int path = c - 'a';
            if(node->next[path] == nullptr){
                node->next[path] = new TireNode();
            }
            node = node->next[path];
            node -> pass++;
        }
        node -> end++;
    }
    
    bool search(string word) {
        TireNode* node = root;
        for(auto c : word){
            int path = c - 'a';
            if(node ->next[path] == nullptr){
                return false;
            }
            node = node->next[path];
        }
        return node -> end > 0;
    }
    
    bool startsWith(string prefix) {
        TireNode* node = root;
        for(auto c : prefix){
            int path = c - 'a';
            if(node ->next[path] == nullptr){
                return false;
            }
            node = node->next[path];
        }
        return true;
    }
};



