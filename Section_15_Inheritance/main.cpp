// Section 15
// Deriving our First Class

#include <iostream>
#include "Account.h"
#include "Savings_Account.h"

using namespace std;

int main() { 
    
    // Use the Account class
    cout << "\n=== Account ==================================" << endl;
    Account acc {};
    acc.deposit(2000.0);               
    acc.withdraw(500.0);
    
    cout << endl;
    
    Account *p_acc {nullptr};
    p_acc = new Account();
    p_acc->deposit(1000.0);
    p_acc->withdraw(500.0);
    delete p_acc;

// Use the Savings Account class
    
    cout << "\n=== Savings Account ==========================" << endl;
    Savings_Account sav_acc {500, "Denny account", 0.03};
    sav_acc.deposit(2000.0);               
    sav_acc.withdraw(500.0);
    std::cout << sav_acc.balance <<std::endl;
    cout << endl;
    
    Savings_Account *p_sav_acc {nullptr};
    p_sav_acc = new Savings_Account();
    p_sav_acc->deposit(1000.0);
    p_sav_acc->withdraw(500.0);
    delete p_sav_acc;

    cout << "\n==============================================" << endl;
    return 0;
}

