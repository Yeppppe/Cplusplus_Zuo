// https://leetcode.cn/problems/word-ladder/submissions/659752316/?envType=study-plan-v2&envId=top-interview-150


//! 单词接龙
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

//! 最暴力的bfs，遍历是否有相邻单词，使用了暴力遍历的方法，实际上构建邻接表会快很多
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool> visit(wordList.size(), false);
        queue<string> q;
        q.push(beginWord);
        int step = 1;
        while(!q.empty()){
            int sz = q.size();
            step++;
            while(sz--){
                string cur = q.front();
                q.pop();
                for(int i = 0; i < wordList.size(); i++){
                    int count = 0;
                    for(int j = 0; j < cur.size(); j++){
                        if(cur[j] != wordList[i][j]){
                            count++;
                        }
                    }

                    if(count == 1 && !visit[i]){
                        visit[i] = true;
                        if(wordList[i] == endWord){
                            return step;
                        }
                        q.push(wordList[i]);
                    }
                }
            }
        }
        return 0;
    }
};


//! 把每两个相邻单词之间构造一条无相边，将整个连接起来，寻找无向图的最短路径问题，利用通配符建立无向图
class Solution {
public:
    unordered_map<string, int> wordid;
    int nodenum;
    vector<vector<int>> edges;

    void addWord(string& word){
        if(!wordid.count(word)){
            wordid[word] = nodenum++;
            edges.emplace_back();  //因为边最开始并没有初始化数量，因此每添加一个节点，就创建一个边的空集合
        }
    }

    void addEdge(string& word){
        addWord(word);
        int id1 = wordid[word];
        for(auto& c : word){
            char tmp = c;
            c = '*';
            addWord(word);
            int id2 = wordid[word];
            edges[id1].push_back(id2);
            edges[id2].push_back(id1);
            c = tmp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        addEdge(beginWord);
        for(auto word : wordList){
            addEdge(word);
        }
        if(!wordid.count(endWord)) return 0;
        queue<int> q;
        q.push(wordid[beginWord]);
        vector<int> dis(nodenum, INT_MAX);
        dis[wordid[beginWord]] = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(cur == wordid[endWord]) 
                return dis[wordid[endWord]]/2 + 1;
            for(auto e : edges[cur]){
                if(dis[e] == INT_MAX){
                    dis[e] = dis[cur] + 1;
                    q.push(e);
                }
            }
        }
        return 0;
    }
};