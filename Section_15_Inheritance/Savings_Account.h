#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include "Account.h"

class Savings_Account : public Account
{
public:
    double int_rate{};
    Savings_Account();
    Savings_Account(double balance_val, std::string name_val, double int_rate);
    Savings_Account(const Savings_Account &other)
        :Account{other}, int_rate{other.int_rate}{
            std::cout << "Savings account copy constructor was called" << std::endl;
        }
    Savings_Account &operator=(const Savings_Account &rhs){
        if(this == &rhs){
            return *this;
        } else {
            Account::operator=(rhs);
            int_rate = rhs.int_rate;
            return *this;
        }
    }
    ~Savings_Account();
    void deposit(double amount);
    void withdraw(double amount);

};

#endif // _SAVINGS_ACCOUNT_H_
