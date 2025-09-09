// https://leetcode.cn/problems/design-add-and-search-words-data-structure/?envType=study-plan-v2&envId=top-interview-150

#include <string>
using namespace std;

//! 搜索的时候使用了一个动态规划 递归搜索前缀树，真的绝了

class WordDictionary {
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
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        node -> pass++;
        for(auto c : word){
            if(node -> next[c - 'a'] == nullptr){
                node -> next[c - 'a'] = new TrieNode();
            }
            node = node -> next[c - 'a'];
            node -> pass++;
        }
        node -> end++;
    }

    
    bool search(string word) {
        TrieNode* node = root;
        return dfs(word, 0, root);
    }

    bool dfs(string word, int index,TrieNode* node){
        if(index == word.size()){
            return node -> end > 0;
        }
        char c = word[index];
        if('a' <= c && c <= 'z'){
            if(node -> next[c - 'a'] == nullptr){
                return false;
            }
            else{
                node = node -> next[c - 'a'];
                return dfs(word, index + 1, node);
            }
        }
        else{
            for(int i = 0; i < 26; i++){
                if(node -> next[i] != nullptr && dfs(word, index + 1, node -> next[i])){
                    return true;
                }
            }
        }
        return false;
    }
};
