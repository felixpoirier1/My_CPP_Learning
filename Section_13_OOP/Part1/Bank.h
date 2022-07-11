//we can also use "#pragma once "
#ifndef _BANK_H_
#define _BANK_H_
#include <iostream>
#include <string>
#include <vector>

class Bank{
    public:
        std::string account_name {};
        double balance {};
        std::vector<std::string> purchases {};

        //in Bank.cpp

        bool deposit(double amount);

        bool withdrawal(double amount);

};


#endif