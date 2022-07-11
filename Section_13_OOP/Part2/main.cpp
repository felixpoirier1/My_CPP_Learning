#include <iostream>
#include <string>
#include <vector>

 class Player{
    //ATTRIBUTES
    public:
        std::string name {};
        int health {};
    private:
        int xp;

    public:

        Player(std::string name_val="None", int health_val=0, int xp_val=0);



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


Player::Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val}{
        std::cout << "Three args constructor" << std::endl;

}





//declaring method outside the scope of Player
bool Player::is_dead(){
        if (health <= 0 || xp <= 0)
            return 1;

        else return 0;
    };



int main(){
    //simple definitions
    Player frank;
    Player hero;

    //assessing the attributes of frank (object of type Player)
    frank.name = "Frank";
    frank.health = 100;

    Player josh {"Josh", 100};

    std::cout << "\nJosh's XP is : " << josh.get_xp() << std::endl;

    //using the "all attributes" constructor
    Player allen{"Allen", 100, 10};



    return 0;
}