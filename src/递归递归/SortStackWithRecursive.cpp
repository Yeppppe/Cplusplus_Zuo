// 用递归函数排序栈
// 栈只提供push、pop、isEmpty三个方法
// 请完成无序栈的排序，要求排完序之后，从栈顶到栈底从小到大
// 只能使用栈提供的push、pop、isEmpty三个方法、以及递归函数
// 除此之外不能使用任何的容器，数组也不行
// 就是排序过程中只能用：
// 1) 栈提供的push、pop、isEmpty三个方法
// 2) 递归函数，并且返回值最多为单个整数


#include <stack>

// 返回栈的深度
// 不改变栈的数据状况
int deep(stack<int>& stack){
    if(stack.empty()){
        return 0;
    }
    int num = stack.top();     // C++中stack.pop不返回值
    stack.pop();
    int deep = 1+deep(stack);
    stack.push(num)
    return deep;
}


// 从栈当前的顶部开始，往下数deep层
// 返回这deep层里的最大值
int stack_max(stack<int>& stack,int deep){
    if(deep == 0){
        return INT_MIN;
    }

    int num = stack.top();
    stack.pop();
    int res_max = stack_max(stack,deep-1);
    int max = max(num,res_max);
    stack.push(num);

    return max;
}



// 从栈当前的顶部开始，往下数deep层，已知最大值是max了
// 返回，max出现了几次，不改变栈的数据状况
int max_time(stack<int>& stack,int deep,int max_num){
    if(deep == 0){
        return 0;
    }

    int num = stack.top();
    stack.pop();
    int ans = max_time(stack,deep-1,max_num)+(num == max_num?1:0)
    stack.push(num);

    return ans;
}


// 从栈当前的顶部开始，往下数deep层，已知最大值是max，出现了k次
// 请把这k个最大值沉底，剩下的数据状况不变
void down(stack<int>& stack,int deep,int max_num,int k){
    if(deep == 0){
        for(int i=0;i<k;i++){
            stack.push(max_num);
        }
        return;
    }

    int num = stack.top();
    stack.pop();
    down(stack,deep-1,max_num,k);
    if(num != max_num){
        stack.push(num);
    }
    return;
}


void sort(stack<int>& stack){
    int deep = deep(stack);
    while(deep>0){
        int max_num = stack_max(stack);
        int k = max_time(stack,max_num);
        down(stack,deep,max_num,k);
        deep -= k;
    }
}
