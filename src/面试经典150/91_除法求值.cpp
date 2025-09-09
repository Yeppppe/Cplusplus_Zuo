// https://leetcode.cn/problems/evaluate-division/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
private:
    vector<int> father;
    vector<double> weight;
public:
    void build(int n){
        father.resize(n);
        weight.resize(n);
        for(int i = 0; i < n; i++){
            father[i] = i;
            weight[i] = 1.0;
        }
    }


    int find_F(int x){
        if(father[x] != x){
            int cur = father[x];
            father[x] = find_F(father[x]);
            weight[x] *= weight[cur];
        }
        return father[x];
    }

    void Union(int x, int y, double val){
        int fx = find_F(x);
        int fy = find_F(y);
        if(fx != fy){
            father[fx] = fy;
            weight[fx] = weight[y] / weight[x] * val;
        }
    }

    double isconnect(int x, int y){
        int fx = find_F(x);
        int fy = find_F(y);

        if(fx != fy) return -1;
        return weight[x] / weight[y];
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> map;
        int n = equations.size();
        build(2*n);
        int id = 0;
        for(int i = 0; i < n; i++){
            string first = equations[i][0];
            string second = equations[i][1];
            if(!map.count(first)){
                map[first] = id++;
            }
            if(!map.count(second)){
                map[second] = id++;
            }
        }

        for(int i = 0; i < n; i++){
            int x = map[equations[i][0]];
            int y = map[equations[i][1]];
            Union(x, y ,values[i]);
        }

        vector<double> ans;
        int m = queries.size();
        for(int i = 0; i < m; i++){
            if(map.count(queries[i][0]) && map.count(queries[i][1])){
                ans.push_back(isconnect(map[queries[i][0]] ,map[queries[i][1]]));
            }
            else{
                ans.push_back(-1.0);
            }
        }
        return ans;
    }
};

