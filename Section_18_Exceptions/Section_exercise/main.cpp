#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    double balance {};
    double withdrawal {};
    try {
        std::cout << "What's the balance : " ;
        std::cin >> balance;
        std::unique_ptr<Account> moes_account = std::make_unique<Checking_Account>("Moe", balance);
        std::cout << "How much do you want to withdraw : ";
        std::cin >> withdrawal;
        moes_account->withdraw(withdrawal);
        std::cout << *moes_account << std::endl;
    }
    catch (const IllegalBalanceException &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    catch (const InsufficientFundsException &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    return 0;
}

