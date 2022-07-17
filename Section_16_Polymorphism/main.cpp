#include <iostream>

// This class uses dynamic polymorphism for the withdraw method
class Account {
public:
    virtual void withdraw(double amount) = 0;
    virtual ~Account() { std::cout << "Destructor called for : Account" << std::endl; }
};

class Checking: public Account  {
public:
    //don't need to repeat virtual but best practice
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual ~Checking() { std::cout << "Destructor called for : Checking" << std::endl; }
};

class Savings: public Account  {
public:
    //override keyword insures that the method from base class
    //is truly replaced 
    virtual void withdraw(double amount) override {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() { std::cout << "Destructor called for : Savings" << std::endl; }
};

//final specifier makes sure this class can't be derived
class Trust final: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust() { std::cout << "Destructor called for : Trust" << std::endl; }
};

void do_withdraw(Account &account, double amount){
    //virtual methods will trigger
    account.withdraw(amount);
}

int main() {
    std::cout << "\n === Pointers ==== " << std::endl;
    Account *p2 = new Savings();
    Account *p3 = new Checking();
    Account *p4 = new Trust();

    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);

    std::cout << "\n === References ==== " << std::endl;
    Checking a;
    Account &ref = a;
    ref.withdraw(1000);

    Trust t;
    Account &ref1 = t;
    ref1.withdraw(1000);

    Savings a1;

    do_withdraw(a1, 1000);

    std::cout << "\n === Clean up ==== " << std::endl;
    delete p2;
    delete p3;
    delete p4;
        
    return 0;
}
