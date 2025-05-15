// 用递归函数逆序栈

//栈的用法
#include <stack>
stack<int> stack;


//函数一：栈底元素移除掉，上面元素改下来，返回移除掉的栈低元素
int bottomOut(stack<int>& stack){
    int ans = stack.pop()
    if(stack.empty()){
        return ans;
    }
    else{
        last = bottomOut(stack);
        stack.push(ans);
        return last;
    }
}


//函数二：
void reverse(stack<int> stack){
    if(stack.empty()){
        return;
    }

    int num = bottomOut(stack);
    reverse(stack);
    stack.push(num);
}



