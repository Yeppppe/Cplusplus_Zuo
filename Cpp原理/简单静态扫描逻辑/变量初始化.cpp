#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <regex>
using namespace std;

// 简单的状态机：记录变量是否初始化
enum VarState { UNINITIALIZED, INITIALIZED };

// 去掉 token 末尾的一些标点（如 ; , ) ]
static inline string strip_tail(string s) {
    while (!s.empty()) {
        char c = s.back();
        if (c == ';' || c == ',' || c == ')' || c == ']' ) s.pop_back();
        else break;
    }
    return s;
}

// 从一个片段中提取所有“标识符”（形如 [A-Za-z_][A-Za-z0-9_]*）
// 这样 "a+b;"、"foo(bar)"、"x[3]" 都能拆出 a / foo / x
static vector<string> extract_identifiers(const string& fragment) {
    static const regex id_re(R"([A-Za-z_][A-Za-z0-9_]*)");
    vector<string> ids;
    for (sregex_iterator it(fragment.begin(), fragment.end(), id_re), end; it != end; ++it) {
        ids.push_back(it->str());
    }
    return ids;
}

// 模拟静态分析器
void staticAnalyze(const string& code) {
    unordered_map<string, VarState> symbolTable;
    istringstream iss(code);
    string token;

    while (iss >> token) {
        if (token == "int") {
            // 读取变量名（可能是 "a;" 或 "a,"）
            string var;
            if (!(iss >> var)) break;
            var = strip_tail(var);

            // 跳过等号前的空白
            iss >> ws;

            // 窥视下一个字符是否为 '='
            int ch = iss.peek();
            if (ch != char_traits<char>::eof() && static_cast<char>(ch) == '=') {
                // 读掉 '='
                string eq;
                iss >> eq;

                // 把 RHS 直到 ';' 的所有片段读出来
                vector<string> rhs_tokens;
                string t;
                bool seen_semicolon = false;
                do {
                    if (!(iss >> t)) break;
                    rhs_tokens.push_back(t);
                    if (t.find(';') != string::npos) {
                        seen_semicolon = true;
                        break;
                    }
                } while (true);

                // 在 RHS 中找出所有标识符，并检查是否未初始化使用
                for (const auto& raw : rhs_tokens) {
                    // 可能是 a+b; 这种没有空格的写法，用正则拆标识符
                    auto ids = extract_identifiers(raw);
                    for (auto id : ids) {
                        if (symbolTable.count(id) && symbolTable[id] == UNINITIALIZED) {
                            cout << "[警告] 变量 '" << id
                                 << "' 在使用前未初始化！" << endl;
                        }
                    }
                }

                // RHS 处理完，c 才算初始化
                symbolTable[var] = INITIALIZED;

                // 如果 RHS 没读到分号，后续主循环还会继续读；这里不强制恢复
                (void)seen_semicolon;
            } else {
                // 没有初始化（没有 '='）
                symbolTable[var] = UNINITIALIZED;
            }
        }
        else {
            // 非声明分支：若 token 看起来像标识符且在符号表里，则可检查一次
            // （为了健壮，先去掉尾随标点）
            string id = strip_tail(token);
            if (symbolTable.count(id) && symbolTable[id] == UNINITIALIZED) {
                cout << "[警告] 变量 '" << id
                     << "' 在使用前未初始化！" << endl;
            }
        }
    }
}

int main() {
    string code = R"(
        int a;
        int b = 5;
        int c = a + b;
        // 一些变体，验证无空格/有调用/有下标也可识别出标识符
        int d =a+b;
        int e = func(a, b);
        int f = arr[a];
    )";

    staticAnalyze(code);
    return 0;
}
