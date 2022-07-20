// Section 16 
// Challenge 
#include <iostream>
#include <vector>
#include <memory>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

class Test{
private:
    int data;
public:
    Test(): data{0}{std::cout << "Test constructor (" << data << ")" << std::endl;}
    Test(int data) : data{data} {std::cout << "Test constructor (" << data << ")" << std::endl;}
    int get_data() const {return data;}
    ~Test(){std::cout << "Test destructor (" << data << ")" << std::endl;}
};


using namespace std;

int main() {
    //raw pointer
    std::cout << "Raw pointer" << std::endl;
    Test *t1 = new Test{100};
    std::cout << "data = " << t1->get_data() << std::endl;
    delete t1;
    //unique pointer
    std::cout << "\nUnique pointer" << std::endl;
    std::unique_ptr<Test> t2 {new Test{100}};
    std::cout << "data = " << t2->get_data() << std::endl;
    std::cout << "\nUnique pointer using make unique" << std::endl;
    std::unique_ptr<Test> t3 = std::make_unique<Test>(200);
    std::cout << "data = " << t3->get_data() << std::endl;

    //moving a unique pointer
    t3 = std::move(t2);

    std::unique_ptr<Account> a1 = std::make_unique<Checking_Account>("Moe", 5000);
    std::cout << *a1 << std::endl;
    a1->deposit(500);
    std::cout << *a1 << std::endl;

    std::vector<std::unique_ptr<Account>> accounts;
    accounts.push_back(make_unique<Checking_Account>("James", 1000));
    accounts.push_back(make_unique<Savings_Account>("Billy", 5000, 3));
    accounts.push_back(make_unique<Trust_Account>("Bobby", 4000, 4));
    
    for(const auto &acc: accounts)
        std::cout << *acc << std::endl;

    //shared pointer
    std::cout << "\nShared pointer" << std::endl;
    std::shared_ptr<int> p1 {new int {100}};

    std::cout << "Use count: " << p1.use_count() << std::endl;

    std::shared_ptr<int> p2 = std::make_shared<int>(50);

    p2 = p1;

    std::cout << "Use count: " << p1.use_count() << std::endl;

    p1.reset();

    std::cout << "Use count: " << p1.use_count() << std::endl;

    //weak pointer
    

    return 0;
}

