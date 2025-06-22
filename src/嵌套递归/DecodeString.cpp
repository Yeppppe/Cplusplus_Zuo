// 含有嵌套的字符串解码
// 测试链接 : https://leetcode.cn/problems/decode-string/

class Solution {
private:
    int where;
public:
    string decodeString(string s) {
        where = 0;
        return f(s,0);
    }

    string f(string s,int i){
        string path;
        int cnt = 0;
        while(i<s.size()&&s[i]!=']'){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
                path += s[i++];
            }
            else if(s[i]>='0'&&s[i]<='9'){
                cnt = cnt*10 + (s[i++]-'0');
            }
            else{  //遇到 '['
                string path0 = f(s,i+1);
                path = path + get(cnt,path0);
                i = where+1;
                cnt = 0;
            }
        }
        where = i;
        return path;
    }

    string get(int cnt,string& s){
        string path;
        for(int i=0;i<cnt;i++){
            path+=s;
        }
        return path;
    }
};