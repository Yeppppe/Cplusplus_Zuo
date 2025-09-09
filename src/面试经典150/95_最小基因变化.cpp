// https://leetcode.cn/problems/minimum-genetic-mutation/submissions/659745405/?envType=study-plan-v2&envId=top-interview-150

#include <string>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int bank_size = bank.size();
        vector<bool> vis(bank.size(), false);
        queue<string> q;
        q.push(startGene);
        int step = 0;
        while(!q.empty()){
            int sz = q.size();
            step++;
            while(sz--){
                string cur = q.front();
                q.pop();
                int count = 0;
                for(int i = 0; i < bank.size(); i++){
                    int count = 0;
                    for(int j = 0; j < 8; j++){
                        if(cur[j] != bank[i][j]){
                            count++;
                        }
                    }
                    if(count == 1 && !vis[i]){
                        vis[i] =true;
                        if(bank[i] == endGene)
                            return step;
                        
                        q.push(bank[i]);
                    }
                }
            }
        }
        return -1;
    }
};
