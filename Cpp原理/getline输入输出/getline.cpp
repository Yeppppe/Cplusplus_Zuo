#include <bits/stdc++.h>

using namespace std;


int main(){
    string line;
    vector<int> nums;

    while(getline(cin , line)){
        for(char c : line){
            if(isdigit(c)){
                nums.push_back(c - '0');
            }
        }
    }
}



int main2(){
    string line;
    vector<vector<int>> all;

    while(getline(cin, line)){
        vector<int> digits;
        for(char c : line){
            if(isdigit(c)) 
                digits.push_back('c' - '0');
        }
        if(!digits.empty()){
            all.push_back(digits);
        }
    }
}



//! getline用于切分
void parseMac(const string& mac){
    string token;
    stringstream ss(mac);
    vector<string> parts;
    while(getline(ss, token, '-')){             //! 会一直分割，直到当前行结束，分割符为'-'
        parts.push_back(token);
    }
}



//! 华为笔试
// 把 "xx-xx-xx-xx-xx-xx" 解析为 48 位整数（高位在左）
static uint64_t parseMac48(const string& mac) {
    uint64_t val = 0;
    string token;
    stringstream ss(mac);
    for (int i = 0; i < 6; ++i) {
        if (!getline(ss, token, '-')) throw runtime_error("bad mac");
        unsigned int byteVal = 0;
        // stoi/stoul 都可以，16 进制自动支持大小写
        byteVal = stoul(token, nullptr, 16);              //* std::stoul(const std::string& str, std::size_t* pos = 0, int base = 10)  把字符串str按照给定进制base转换成unsigned long，转换从开头第一个非空白字符开始，读到第一个不合法字符
        val = (val << 8) | (byteVal & 0xFFu);        
    }
    return val; // 低 48 位有效
}



// 生成前缀掩码：高位 M 个 1，其余为 0（只在低 48 位范围内）
static inline uint64_t prefixMask(int M) {
    if (M == 0) return 0ull;
    return (( (1ULL << M) - 1ULL) << (48 - M));
}

int main5() {
    int n;
    if (!(cin >> n)) return 0;
    string line; getline(cin, line); // 吃掉行尾
    // 按 M 分组，存储已掩码化的前缀值
    unordered_map<int, unordered_set<uint64_t>> bucket;
    bucket.reserve(64);
    // 预先把出现过的 M 的掩码也存起来，便于查询时遍历
    vector<int> Ms;
    vector<bool> seenM(49, false);
    for (int i = 0; i < n; ++i) {
        string rule; getline(cin, rule);
        // 拆分 "mac/M"
        auto pos = rule.find('/');
        string macStr = rule.substr(0, pos);
        int M = stoi(rule.substr(pos + 1));
        uint64_t addr = parseMac48(macStr);
        uint64_t msk = prefixMask(M);
        uint64_t key = addr & msk;
        auto &S = bucket[M];
        if (S.empty() && !seenM[M]) {
            Ms.push_back(M);
            seenM[M] = true;
        }
        S.insert(key);
    }
    int m;
    cin >> m;
    getline(cin, line); // 吃掉行尾
    // 预计算所有可能 M 的掩码，避免重复位运算
    uint64_t masks[49];
    for (int M = 0; M <= 48; ++M) masks[M] = prefixMask(M);

    for (int i = 0; i < m; ++i) {
        string mac; getline(cin, mac);
        uint64_t x = parseMac48(mac);

        bool ok = false;
        // 只遍历输入中出现过的 M
        for (int M : Ms) {
            uint64_t masked = x & masks[M];
            auto it = bucket.find(M);
            if (it != bucket.end()) {
                if (it->second.find(masked) != it->second.end()) {
                    ok = true; break;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}

