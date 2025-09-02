#include <mutex>

struct Account{
   std::mutex m;
   int balance = 0;
};

void transfer(Account& a, Account& b, int amt){
   std::scoped_lock lk(a.m, b.m);
   a.balance -= amt;
   b.balance += amt;
}