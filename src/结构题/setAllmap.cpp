// https://www.nowcoder.com/practice/7c4559f138e74ceb9ba57d76fd169967
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Set{
public:
    Set():setAllValue(0),setAllTime(0),count(0){}
    void put(int key,int val){
        vector<int> tmp;
        tmp.push_back(val);
        tmp.push_back(++count);
        set[key] = tmp;
    }

    int get(int key){
        if(set.find(key) == set.end())
            return -1;
        auto& tmp = set[key];
        tmp[0] = tmp[1]<setAllTime ? setAllValue:tmp[0];
        return tmp[0];
    }

    void setAll(int val){
        setAllValue = val;
        setAllTime = ++count;
    }


private:
    unordered_map<int, vector<int>> set;
    int setAllValue;
    int setAllTime;
    int count;
};
int main() {
    int n;
    cin>>n;
    Set s;
    while(n--){
        int mode;
        cin >> mode;
        if(mode == 1){
            int a,b;
            cin >> a >> b;
            s.put(a,b);
        }
        else if(mode == 2){
            int a;
            cin >> a;
            int output = s.get(a);
            cout << output <<endl;
        }
        else if(mode ==3){
            int a;
            cin >> a;
            s.setAll(a);
        }

    }
}
// 64 位输出请用 printf("%lld")