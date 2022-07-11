#include <iostream>
#include <string>
#include <vector>
#include "Bank.h"

bool Bank::withdrawal(double amount){
    if (balance >= amount){
        balance -= amount;
        return true;
        }

    else return false;

}