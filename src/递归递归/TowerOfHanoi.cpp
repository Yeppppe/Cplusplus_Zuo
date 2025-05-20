// 打印n层汉诺塔问题的最优移动轨迹



void f(int i,string from,string to,string other){
    if(i == 1){
        std::cout<<"移动圆盘1" <<"从" <<from <<"到"<<to;
        return;
    }
    f(i-1,from,other,to);
    std::cout<<"移动圆盘"<< i <<"从" <<from <<"到"<<to;
    f(i-1,other,to,from);
}


void hanoi(int n){
    if(n>0){
        f(n,"左","中","右");
    }
}