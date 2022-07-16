#ifndef _TRUSTACCOUNT_H_
#define _TRUSTACCOUNT_H_
#include "Savings_Account.h"

class Trust_Account: public Savings_Account
{
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr const double def_balance = 0.0;
    static constexpr const double def_int_rate = 0.0;
    int withdrawals = 0;
protected:

public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    Trust_Account(const Trust_Account &copy);
    ~Trust_Account();

    bool deposit(double amount);
    bool withdraw(double amount);    
};


#endif