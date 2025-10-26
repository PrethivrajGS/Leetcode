#include <bits/stdc++.h>
using namespace std;

class Bank {
private:
    vector<long long> balance; 

    
    bool validAccount(int account) {
        return account >= 1 && account <= (int)balance.size();
    }

public:
   
    Bank(vector<long long>& balance) {
        this->balance = balance;
    }


    bool withdraw(int account, long long money) {
        if (!validAccount(account)) return false;         
        if (balance[account - 1] < money) return false;   
        balance[account - 1] -= money;                   
        return true;
    }

    // Deposit money into given account
    bool deposit(int account, long long money) {
        if (!validAccount(account)) return false;         // invalid account
        balance[account - 1] += money;                    // perform deposit
        return true;
    }

    // Transfer money between accounts
    bool transfer(int account1, int account2, long long money) {
        if (!validAccount(account1) || !validAccount(account2)) return false;
        if (balance[account1 - 1] < money) return false;  // insufficient funds
        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }
};
