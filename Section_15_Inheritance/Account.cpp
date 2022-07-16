#include <iostream>
#include "Account.h"


Account::Account()
    :balance{0.0}, name{"An account"}{
    std::cout << "Account constructor was called"<<std::endl;
}

Account::Account(double balance_val, std::string name_val)
    :balance{balance_val}, name{name_val}{
    std::cout << "Account constructor was called"<<std::endl;
}


Account::~Account(){
    std::cout << "Account destructor was called" << std::endl;
}

void Account::deposit(double amount){
    balance += amount;
    std::cout << "Account deposit called with "<< amount <<std::endl;
}

void Account::withdraw(double amount){
    balance -= amount;
    std::cout << "Account withdraw called with "<< amount <<std::endl;
}