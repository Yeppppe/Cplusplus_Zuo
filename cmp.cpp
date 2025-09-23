#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string rankStr;
vector<string> strs;

// 自定义比较函数
bool compare(const string& a, const string& b) {
    int minLen = min(a.size(), b.size());
    int i = 0;
    while (i < minLen && a[i] == b[i]) {
        i++;
    }
    if (i == minLen) {
        return a.size() < b.size();
    } else {
        // 找到字符在rankStr中的位置，位置小的排名高
        int rankA = rankStr.find(a[i]);
        int rankB = rankStr.find(b[i]);
        return rankA < rankB;
    }
}

int main() {
    cin >> rankStr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        strs.push_back(s);
    }
    sort(strs.begin(), strs.end(), compare);
    for (const string& s : strs) {
        cout << s << endl;
    }
    return 0;
}