/*
100个人 每个人都有100元
每一轮：
每个人拿出一块钱给其他人，给谁完全随机
如果某个人剩下0元，那么它可以不给，但是可以接收
发生很多轮后，100人的财富是均匀的吗

差值绝对值总和  =   每个人与其他人差值的绝对值的总和 即如果有五个人，那包括对自己的差值0 一共应该有25个数字
财富总和  =  所有人财富的总和

基尼系数 = 差值绝对值总和/（2*人口数的平方*平均财富）  ==   差值绝对值总和/（2*人口数*社会总财富）
 */ 

//! 如何使用随机数
//! 容器算法 sort

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
using namespace std;
double calGini(vector<int>& wealth){
    double sumOfDiff = 0;
    double sumOfAll = 0;
    for(auto one:wealth){
        sumOfAll += one;
        for(auto other:wealth){
            sumOfDiff += abs(one-other);
        }
    }
    int wealth_count = wealth.size();
    double Gini = sumOfDiff/(2*wealth_count*sumOfAll);
    return Gini;
}

void experiment(int person,int count){
    vector<int> wealth(person,100);
    vector<bool> hasMoney(person,true);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 99);  // [0, 99] 范围的随机数
    for(int i =0;i<count;i++){
        for(int j=0;j<person;j++){
            if(wealth.at(j)==0)
                hasMoney[j]=false;
        }
        for(int k=0;k<person;k++){
            if(!hasMoney[k])
                continue;
            int other = dis(gen);
            while(other == k){
                other = dis(gen);
            }
            wealth[k]--;
            wealth[other]++;
        }
    }
    sort(wealth.begin(),wealth.end());
    cout<<"列出每个人的财富，从贫穷到富有"<<endl;
    for(int i=0;i<person;i++){
        cout<<wealth[i]<<" ";
        if(i%10 == 9){
            cout<<endl;
        }
    }
    cout<<endl;
    double Gini=calGini(wealth);
    cout<<"这个社会的基尼系数为："<< Gini << endl;
    cout<< Gini << endl;
}

int main(void){
    cout<<"一个社会的基尼系数是一个在0~1之间的小数"<<endl;
    cout<<"基尼系数为0代表所有人的财富完全一样"<<endl;
    cout<<"基尼系数为1代表有1个人掌握了全社会的财富"<<endl;
    cout<<"基尼系数越小，代表社会财富分布越均衡；越大则代表财富分布越不均衡"<<endl;
    cout<<"在2022年,世界各国的平均基尼系数为0.44"<<endl;
    cout<<"目前普遍认为，当基尼系数到达 0.5 时"<<endl;
    cout<<"就意味着社会贫富差距非常大，分布非常不均匀"<<endl;
    cout<<"社会可能会因此陷入危机，比如大量的犯罪或者经历社会动荡"<<endl;
    cout<<"测试开始"<<endl; 
    experiment(100,10000);
    return 0;
}