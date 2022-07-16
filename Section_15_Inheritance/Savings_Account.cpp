#include <iostream>
#include "Savings_Account.h"

Savings_Account::Savings_Account()
    :int_rate{0.05}{
    std::cout << "Savings account constructor was called" << std::endl;
}
Savings_Account::Savings_Account(double balance_val, std::string name_val, double int_rate)
    :Account{balance_val,name_val}, int_rate{int_rate}
{
    std::cout << "Savings account constructor was called" << std::endl;
}
Savings_Account::~Savings_Account(){
    std::cout << "Savings account destructor was called" << std::endl;
}
void Savings_Account::deposit(double amount){
    amount = amount*(1+int_rate);
    Account::deposit(amount);
    std::cout << "Savings Account deposit called with "<< amount << std::endl;
}