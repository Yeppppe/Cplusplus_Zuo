#include <iostream>
#include <string>
#include <vector>
#include <sstream>
// 二叉树先序序列化和反序列化
// 测试链接 : https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/

// 二叉树节点结构体
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Codec {
private:
    static int count;
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string builder;
        f(root,builder);
        return builder;
    }
    void f(TreeNode* root, std::string& builder){
        if(root == nullptr){
            builder += "#,";
            return;
        }
        builder += (std::to_string(root->val)+",");
        f(root->left,builder);
        f(root->right,builder);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::vector<std::string> results = split(data,',');
        count = 0;
        return g(results);
    }
    TreeNode* g(const vector<string>& vals){
        std::string cur = vals[count++];
        if (cur == "#"){
            return nullptr;
        }
        else{
            //* stoi来自string头文件 int stoi(const std::string& str, std::size_t* pos = 0, int base = 10);
            //* 将string类型的str转换成 int ，默认是十进制 ，可选参数pos返回第一个未被转换字符的位置。
            TreeNode* head = new TreeNode(std::stoi(cur));
            head->left = g(vals);
            head->right = g(vals);
            return head;
        }
    }

    std::vector<string> split(const std::string& s,char delim){
        std::vector<std::string> results;
        //* stringstream是一个字符串流累心，可以像流一样操作
        std::stringstream ss(s);
        string item;
        //* 这个getline是来自sstream中， std::getline(std::stringstream&, std::string&, char)
        //* 用char作为分隔符，分割stringstream，每个分隔符前面的内容存入string中
        while(getline(ss,item,delim)){
            results.push_back(item);
        }
        return results;
    }
};

//* 注意类的静态成员变量要在类外进行初始化！
int Codec::count = 0;