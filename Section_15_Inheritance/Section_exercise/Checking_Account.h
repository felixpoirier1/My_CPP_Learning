#ifndef _CECKINGACCOUNT_H_
#define _CECKINGACCOUNT_H_
#include "Account.h"

class Checking_Account : public Account
{
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double per_check_fee = 1.5;
public:
    Checking_Account(std::string name = def_name, double balance = def_balance);
    Checking_Account(const Checking_Account &copy);
    ~Checking_Account();

    bool withdraw(double amount);
};


#endif