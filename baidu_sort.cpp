#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct student{
   string name;
   int chengji;
};

int main(){
   vector<student> students;
   for(int i = 0; i < 5; i++){
      student s;
      cin >> s.name >> s.chengji;
      students.push_back(s);
   }
   sort(students.begin(),students.end() , [](const student& a, const student& b){
      return a.chengji > b.chengji;
   });

   cout << students[1].name << students[1].chengji << endl;
   cout << students[1].name << students[1].chengji << endl;
   return 0;
}