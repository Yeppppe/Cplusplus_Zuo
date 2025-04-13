// 头文件包含
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 自定义类 Set，用于实现带有 setAll 功能的键值存储
class Set {
public:
    // 构造函数，初始化成员变量
    Set() : setAllValue(0), setAllTime(0), count(0) {}

    // 插入键值对
    void put(int key, int val) {
        vector<int> tmp;
        tmp.push_back(val); // 存储值
        tmp.push_back(++count); // 存储插入时间
        set[key] = tmp; // 更新键值对
    }

    // 获取键对应的值
    int get(int key) {
        if (set.find(key) == set.end()) // 如果键不存在，返回 -1
            return -1;
        auto& tmp = set[key];
        // 如果键的插入时间早于 setAll 操作时间，则返回 setAll 的值
        tmp[0] = tmp[1] < setAllTime ? setAllValue : tmp[0];
        return tmp[0];
    }

    // 设置所有键的值
    void setAll(int val) {
        setAllValue = val; // 更新全局值
        setAllTime = ++count; // 更新全局时间
    }

private:
    unordered_map<int, vector<int>> set; // 存储键值对及其插入时间
    int setAllValue; // 全局设置的值
    int setAllTime; // 全局设置的时间
    int count; // 操作计数器，用于记录时间
};

int main() {
    int n;
    cin >> n; // 读取操作次数
    Set s; // 创建 Set 对象
    while (n--) {
        int mode;
        cin >> mode; // 读取操作模式
        if (mode == 1) { // 插入操作
            int a, b;
            cin >> a >> b;
            s.put(a, b);
        } else if (mode == 2) { // 查询操作
            int a;
            cin >> a;
            int output = s.get(a);
            cout << output << endl;
        } else if (mode == 3) { // 全局设置操作
            int a;
            cin >> a;
            s.setAll(a);
        }
    }
}
// 64 位输出请用 printf("%lld")