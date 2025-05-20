// 含有嵌套的分子式求原子数量
// 测试链接 : https://leetcode.cn/problems/number-of-atoms/

// 无敌了
class Solution {

private:
    int where;
public:
    string countOfAtoms(string formula) {
        map<string,int> ans;
        ans = f(formula,0);
        string result;
        for(auto pair:ans){
            result+=pair.first;
            if(pair.second!=1)
                result+=to_string(pair.second);
        }
        return result;
    }

    map<string,int> f(string formula,int i){
        map<string,int> ans;
        map<string,int> pre;
        string name;
        int cnt = 0;
        while(i<formula.size()&&formula[i]!=')'){
            if((formula[i]>='A'&&formula[i]<='Z')||formula[i] == '('){
                fill(name,pre,cnt,ans);
                name = "";
                cnt = 0;
                pre = {};
                if(formula[i]>='A'&&formula[i]<='Z'){
                    name+=formula[i++];
                }
                else{
                    pre = f(formula,i+1);
                    i = where + 1;
                }
            }
            else if(formula[i]>='a'&&formula[i]<='z'){
                name+=formula[i++];
            }
            else{
                cnt = cnt*10 + formula[i++]-'0';
            }
        }
        fill(name,pre,cnt,ans);
        where = i;
        return ans;
    }

    void fill(string name,map<string,int> pre,int cnt,map<string,int>& ans){
        cnt = cnt==0? 1:cnt;
        if(name.size()>0||pre.size()>0){
            if(name.size()>0){
                auto it = ans.find(name);
                if(it!=ans.end()){
                    ans[name]+=cnt;
                }
                else{
                    ans.insert({name,cnt});
                }
            }
            else{
                for(auto& pair:pre){
                    auto it= ans.find(pair.first);
                    if(it!=ans.end()){
                        ans[pair.first]+=cnt*(pair.second);
                    }
                    else{
                        ans.insert({pair.first,pair.second*cnt});
                    }
                }
            }
        }
    }


};