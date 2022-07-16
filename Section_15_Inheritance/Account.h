#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>

class Account
{
public:
    double balance{};
    std::string name;

    Account();
    Account(double balance_val, std::string name_val);
    Account(const Account &other) 
        :balance{other.balance}, name{other.name}{
            std::cout << "Account copy constructor was called" <<std::endl;
        }
    ~Account();

    Account &operator=(const Account &rhs){
        if(this == &rhs){
            return *this;
        } else {
            balance = rhs.balance;
            name = rhs.name;
            return *this;
        }
    }

    void deposit(double amount);
    void withdraw(double amount);
};

#endif // _ACCOUNT_H_
