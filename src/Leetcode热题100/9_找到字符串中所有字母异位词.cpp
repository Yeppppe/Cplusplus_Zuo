// https://leetcode.cn/problems/find-all-anagrams-in-a-string/?envType=study-plan-v2&envId=top-100-liked

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size();
        int n = p.size();
        if(m < n) return vector<int> {};
        vector<int> scount(26, 0);
        vector<int> pcount(26, 0);

        for(int i = 0 ; i < n; i++){
            scount[s[i] - 'a']++;
            pcount[p[i] - 'a']++;
        }
        scount[s[n - 1] - 'a']--;
        vector<int> ans;
        for(int i = 0; i <= m - n; i++){
            scount[s[i + n - 1] - 'a']++;
            if(scount == pcount){
                ans.push_back(i);
            }
            scount[s[i] - 'a']--;
        }
        return ans;
    }
};