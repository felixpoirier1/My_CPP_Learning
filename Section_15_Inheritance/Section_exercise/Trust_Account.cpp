#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    :Savings_Account{name, balance, int_rate}
{
}

Trust_Account::Trust_Account(const Trust_Account &copy)
    :Trust_Account{copy.name, copy.balance, copy.int_rate}
{
}


Trust_Account::~Trust_Account()
{
}

bool Trust_Account::deposit(double amount){
    if(amount >= 5000){
        amount += 50.0;
        return Savings_Account::deposit(amount);
    } else {
        return Savings_Account::deposit(amount);
    }
}

bool Trust_Account::withdraw(double amount){
    if((withdrawals == 3) || (amount/balance > 0.2)){
        return false;
    } else {
        ++withdrawals;
        return Account::deposit(amount);
    }
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account){
    os << "[Trust Account " << account.name << ": " << account.balance << ", " << account.int_rate << "%, withdrawals: " << account.withdrawals << "]";
    return os;
}
