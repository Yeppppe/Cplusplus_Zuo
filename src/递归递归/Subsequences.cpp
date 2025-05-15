// 字符串的全部子序列
// 子序列本身是可以有重复的，只是这个题目要求去重
// 测试链接 : https://www.nowcoder.com/practice/92e6247998294f2c933906fdedbc6e6a



class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串vector
     */
    vector<string> generatePermutation(string s) {
        // write code here
        unordered_set<string> set;
        string path;
        vector<string> ans;
        f(s,0,path,set);
        for(auto ss : set){
            ans.push_back(ss);
        }
        return ans;
    }

    void f(string s,int i,string& path,unordered_set<string>& set){
        if(i == s.size()){
            set.insert(path);           // 哈希set 添加元素insert  删除元素.erase()  清除所有.clear()
        }
        else{
            path += s[i];               // string 添加一个字符
            f(s,i+1,path,set);
            path.pop_back();            // string 的删除最后一个字符
            f(s,i+1,path,set);
        }
    }
};