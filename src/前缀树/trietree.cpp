// 用固定数组实现前缀树，空间使用是静态的。推荐！
// 测试链接 : https://www.nowcoder.com/practice/7f8a8553ddbf4eaab749ec988726702b

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

namespace trie {
    const int MAXN = 150001;
    int trie[MAXN][26];
    int end[MAXN];
    int pass[MAXN];
    int nodecount;

    void build() {
        nodecount = 1;
    }

    void insert(const string& word) {
        int cur = 1;
        pass[cur]++;
        for(auto s:word){
            int path = s - 'a';
            if(trie[cur][path] == 0){
                trie[cur][path] = ++nodecount;
            }
            cur = trie[cur][path];
            pass[cur]++;
        }
        end[cur]++;
    }

    int search(const string& word){
        int cur = 1;
        int path;
        for(auto a: word){
            path = a - 'a';
            if(trie[cur][path] == 0){
                return 0; 
            }
            cur = trie[cur][path];
        }
        return end[cur];
    }

    void delete_word(const string& word){
        if (search(word) > 0) {
            int cur = 1;
            int path;
            for(auto s:word){
                path = s - 'a';
                pass[cur]--;
                if (pass[trie[cur][path]] == 0) {
                    trie[cur][path] = 0;
                    return;
                }
                cur = trie[cur][path];
            }
            pass[cur]--;
            end[cur]--;
        }
    }

    int count_prefix(const string& word){
        int cur = 1;
        int path;
        for(auto s : word){
            path = s - 'a';
            if(trie[cur][path] == 0){
                return 0;
            }
            cur = trie[cur][path];
        }
        return pass[cur];
    }

    void clear() {
        for (int i = 1; i <= nodecount; i++) {
            memset(trie[i], 0, sizeof(trie[i]));
            end[i] = 0;
            pass[i] = 0;
        }
        nodecount = 1;
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    
    int m;
    while(cin >> m) {
        trie::build();
        while(m--){
            int op;
            string word;
            cin >> op >> word;

            switch(op){
                case 1:
                    trie::insert(word);
                    break;
                case 2:
                    trie::delete_word(word);
                    break;
                case 3:
                    cout << (trie::search(word) > 0 ? "YES" : "NO") << endl;
                    break;
                case 4:
                    cout << trie::count_prefix(word) << endl;
                    break;
                default: break;
            }
        }
        // trie::clear();
    }
    return 0;
}



// 64 位输出请用 printf("%lld")