// https://leetcode.cn/problems/add-binary/?envType=study-plan-v2&envId=top-interview-150

#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size() - 1;
        int n = b.size() - 1;
        int carry = 0;
        string ans;
        while(m >= 0 || n >= 0 || carry){
            int sum = carry;
            if(m >= 0){
                sum += a[m--] - '0';
            }

            if(n >= 0){
                sum += b[n--] - '0';
            }

            carry = sum >= 2 ? 1 : 0;
            ans.push_back(sum%2 + '0');
        }   
        reverse(ans.begin(), ans.end());
        return ans;
    }
};