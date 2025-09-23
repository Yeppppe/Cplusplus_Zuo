// https://leetcode.cn/problems/minimum-window-substring/description/?envType=study-plan-v2&envId=top-100-liked
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tmap;
        unordered_map<char, int> smap;
        for(auto c : t){
            tmap[c]++;
        }

        int n = s.size();
        int ans = INT_MAX;
        bool flag = true;
        int start = 0;
        for(int l = 0, r = 0; r < n; r++){
            smap[s[r]]++;
            flag = true;
            for(auto p : tmap){
                if(!smap.count(p.first) || smap[p.first] < p.second){
                    flag = false;
                }
            }
            while(flag && l <= r){
                if(ans > r - l + 1){
                    ans = r - l + 1;
                    start = l;
                }
                smap[s[l]]--;
                l++;
                for(auto p : tmap){
                if(!smap.count(p.first) || smap[p.first] < p.second){
                    flag = false;
                }
            }
            }
        }
        ans = ans == INT_MAX ? 0 : ans;
        return s.substr(start,ans);

    }
};