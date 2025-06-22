#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
private:
    static const int MAXN = 100001;
    char trie[MAXN][12];
    int pass[MAXN];
    int count;

    void build(){
        count = 1;
    }

    int path(char c){
        if(c == '#'){
            return 10;
        }
        else if(c == '-'){
            return 11;
        }
        else{
            return c - '0';
        }
    }

    void insert(const string& stri){
        int cur = 1;
        pass[cur]++;
        for(auto s : stri){
            if(trie[cur][path(s)] == 0){
                trie[cur][path(s)] = ++count;
            }
            pass[trie[cur][path(s)]]++;
            cur = trie[cur][path(s)];
        }
    }

    int search(const string& stri){
        int cur = 1;
        for(auto s : stri){
            if(trie[cur][path(s)] == 0) return 0;
            cur = trie[cur][path(s)];
        }
        return pass[cur];
    }
    
    void clear() {
        for (int i = 1; i <= count; i++) {
            memset(trie[i], 0, sizeof(trie[i]));
            pass[i] = 0;
        }
        count = 1;
    }
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param b int整型vector<vector<>> 
     * @param a int整型vector<vector<>> 
     * @return int整型vector
     */
    vector<int> countConsistentKeys(vector<vector<int> >& b, vector<vector<int> >& a) {
        // write code here
        vector<int> ans;
        build();
        for (auto aa : a){
            int size = aa.size();
            int last = aa[0];
            string astring;
            int tmp;
            for(int i = 1;i<size ; i++){
                tmp = aa[i] - last;
                astring+=to_string(tmp);     //* int转换成string 要使用to_string函数
                astring.push_back('#');
                last = aa[i];
            }
            insert(astring);
        }


        for(auto bb : b){
            int size = bb.size();
            int last = bb[0];
            string bstring;
            int tmp;
            for(int i = 1;i<size ; i++){
                tmp = bb[i] - last;
                bstring+=to_string(tmp);
                bstring.push_back('#');
                last = bb[i];
            }
            ans.push_back(search(bstring));
        }
        
        // clear();
        return ans;
    }
};