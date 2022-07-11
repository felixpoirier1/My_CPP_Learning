#include "Bank.h"

 class Player{
    //ATTRIBUTES
    public:
        std::string name {};
        int health {};
    private:
        int xp;

    public:

        //CONSTRUCTORS
        //SEE BELOW FOR BETTER FORM OF INITIALIZATION
        //if there are other constructors the default constructor won't work unless specified like so:

/*         Player (){
            std::cout << "No args constructor called" << std::endl;
        }
        Player (std::string name_val, int health_val, int xp_val){
            name = name_val;
            health = health_val;
            xp = xp_val;

            std::cout << "Three args constructor called" << std::endl;
        };
        Player (int xp_val){
            xp = xp_val;

            std::cout << "XP constructor called"<<std::endl;
        };

        ~Player (){
            std::cout << "Destructor called for " << name << std::endl;
        }; */

        //BETTER CONSTRUCTORS USING INITIALIZATION
        Player()
        // this will use the initializer with 3 params and use it to init an empty player
            : Player("None", 0, 0){

        };
        //declared outside of the scope of the class (see below)
        Player(int xp_val);

        Player(std::string name_val, int health_val, int xp_val)    
            : name{name_val}, health{health_val}, xp{xp_val}{

        }



        //METHODS
        void talk(std::string words){
            std::cout << name << " says : " << words << std::endl;
        }

        int get_xp(){
            return xp;
        }

            //inside of main.cpp
        bool is_dead();

};


Player::Player(int xp_val) 
    : name{}, health{0}, xp{xp_val}{

}





//declaring method outside the scope of Player
bool Player::is_dead(){
        if (health <= 0 || xp <= 0)
            return 1;

        else return 0;
    };

//declare method outside of the scope of Bank (declared in Bank.h)
bool Bank::deposit(double amount){
    balance += amount;
    return true;
}


int main(){
    //simple definitions
    Player frank;
    Player hero;

    //assessing the attributes of frank (object of type Player)
    frank.name = "Frank";
    frank.health = 100;

    //will trigger compiler error, XP is private
    // frank.xp = 12;

    hero.name = "SpoilderMan";

    //pointer-style definitions
    Player *enemy {nullptr};
    enemy = new Player {};

    //assessing using two different pointing methods
    (*enemy).name = "Ludwig";
    enemy->name = "Ludwig";

    delete enemy;

    //array-style definitions
    Player players[] {frank, hero};

    //vector-style definitions
    std::vector<Player> player_vec {frank};
    player_vec.push_back(hero);

    frank.talk("Oh! It's SpoilderMan!");

    hero.talk("Shush, I don't like to hear my name.");

    Bank account_frank;
    account_frank.account_name = "Frank's account";
    account_frank.balance = 40'000.00;

    std::cout << "\n" << account_frank.account_name << " balance is $" << account_frank.balance << std::endl;
    //function declared in Account.cpp
    account_frank.withdrawal(10'000.0);
    std::cout << "\n$10 000 where withdrew in " << account_frank.account_name << std::endl;
    std::cout << "\n" << account_frank.account_name << " balance is $" << account_frank.balance << std::endl;
    account_frank.deposit(20'000.0);
    std::cout << "$20 000 where deposited in " << account_frank.account_name << std::endl;
    std::cout << "\n" << account_frank.account_name << " balance is $" << account_frank.balance << std::endl;

    if (account_frank.withdrawal(70'000.0)){
        std::cout << "$\n70 000 where withdrawn from " <<  account_frank.account_name << std::endl;
    }
    else {
        std::cout << "\n$70 000 couldn't be withdrawn from " <<  account_frank.account_name << std::endl;
    }

    //using the xp constructor
    Player josh {5};

    std::cout << "\nJosh's XP is : " << josh.get_xp() << std::endl;

    //using the "all attributes" constructor
    Player allen{"Allen", 100, 10};

    //using initialized constructors
    Bank empty;
    Bank fill {"A bank account", 6,};


    return 0;
}