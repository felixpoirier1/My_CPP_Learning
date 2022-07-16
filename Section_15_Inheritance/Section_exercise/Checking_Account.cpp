#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    :Account{name, balance}
{
}

Checking_Account::Checking_Account(const Checking_Account &copy)
    :Account{copy.name, copy.balance}
{
}

bool Checking_Account::withdraw(double amount){
    amount += per_check_fee;
    return Account::withdraw(amount);
}

Checking_Account::~Checking_Account()
{
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account){
    os << "[Checking Account: " << account.name << ": " << account.balance << "]";
    return os;
}