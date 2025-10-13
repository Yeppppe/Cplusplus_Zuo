#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

// 定义指针状态
enum PtrState { UNINIT, NULLPTR, ALLOCATED, FREED };

void staticAnalyze(const string& code) {
    unordered_map<string, PtrState> ptrTable;
    istringstream iss(code);
    string word;

    while (iss >> word) {
        // 检测指针声明
        if (word == "int*") {
            string var;
            iss >> var;

            // 去掉分号
            if (var.back() == ';') var.pop_back();

            // 默认未初始化
            ptrTable[var] = UNINIT;

            // 检查是否有初始化
            if (iss.peek() == ' ') iss >> ws;
            char next = iss.peek();
            if (next == '=') {
                string eq, rhs;
                iss >> eq >> rhs;

                if (rhs.find("nullptr") != string::npos)
                    ptrTable[var] = NULLPTR;
                else if (rhs.find("new") != string::npos)
                    ptrTable[var] = ALLOCATED;
            }
        }

        // 检测解引用 (*ptr)
        if (word.size() > 1 && word[0] == '*') {
            string var = word.substr(1);
            if (ptrTable[var] == NULLPTR)
                cout << "[错误] 空指针解引用: " << var << endl;
            else if (ptrTable[var] == UNINIT)
                cout << "[警告] 未初始化指针使用: " << var << endl;
        }

        // 检测 delete
        if (word == "delete") {
            string var;
            iss >> var;
            if (ptrTable[var] == ALLOCATED) {
                ptrTable[var] = FREED;
            } else if (ptrTable[var] == NULLPTR) {
                cout << "[警告] delete 空指针: " << var << endl;
            } else {
                cout << "[错误] 无效 delete: " << var << endl;
            }
        }
    }

    // 检查未释放的内存
    for (auto& [var, state] : ptrTable) {
        if (state == ALLOCATED)
            cout << "[内存泄漏] 指针 '" << var << "' 分配后未释放。" << endl;
    }
}

int main() {
    string code = R"(
        int* p = new int;
        int* q = nullptr;
        *q = 10;     // 空指针访问
        int* r;
        *r = 5;      // 未初始化访问
        delete q;    // delete 空指针
        return 0;
    )";

    staticAnalyze(code);
    return 0;
}
