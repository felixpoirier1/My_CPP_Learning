#include <iostream>
#include <string>
#include <vector>

 class Player{
    //ATTRIBUTES
    public:
        std::string name {};
        int health {};
        int xp;

    public:

        Player(std::string name_val="None", int health_val=0, int xp_val=0);



        //METHODS
        void talk(std::string words){
            std::cout << name << " says : " << words << std::endl;
        }
        //prototype of copy constructor
        Player(const Player &source);

        //destructor
        ~Player(){
            std::cout << "Destructor called for: "<< name << std::endl; 
            }


        std::string get_name() const {return name; }
        int get_health() const {return health; }
        int get_xp() const {return xp; }


            //inside of main.cpp
        bool is_dead();

};

//shit class for pointer attributes
class ShallowDeep {
    private:
    int *data;

    public:
    void set_data_value(int d){ *data = d; }
    int get_data_value() const { return *data; }

    ShallowDeep(int d);

    ShallowDeep(const ShallowDeep &source);

    ~ShallowDeep();

};




Player::Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val}{
        std::cout << "Three args constructor" << std::endl;

}

//copy constructor
Player::Player(const Player &source)
    :name(source.name), health(source.health), xp(source.xp){
        std::cout << "Copy constructor made a copy of " << source.name << std::endl;
    }

//declaring method outside the scope of Player
bool Player::is_dead(){
        if (health <= 0 || xp <= 0)
            return 1;

        else return 0;
    };

void display_player(Player p){
    std::cout << "Name: " << p.get_name() << std::endl;
    std::cout << "Health: " << p.get_health() << std::endl;
    std::cout << "Xp: " << p.get_xp() << std::endl;
}



//Default constructor
ShallowDeep::ShallowDeep(int d){
    data = new int;
    *data = d;
}

// THIS IS GARBAGE COPY, Shallow uses pointers
// therefore this copy essentially gives different pointers
// that all point to the same thing
/* ShallowDeep::ShallowDeep(const ShallowDeep &source)
    : data(source.data){
        std::cout <<"Copy constructor - shallow copy" << std::endl;
} */

//THIS IS GOOD COPY, Deep copy
ShallowDeep::ShallowDeep(const ShallowDeep &source)
    : ShallowDeep(*source.data){
    std::cout <<"Copy constructor - deep copy" << std::endl;
} 

ShallowDeep::~ShallowDeep(){
    delete data;
    std::cout << "Destructor freeing data" << std::endl;
}

void display_shallow(ShallowDeep s){
    std::cout << s.get_data_value() << std::endl;
}


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

    display_player(josh);

    Player allen_copy{allen};

    ShallowDeep obj1 {100};
    display_shallow(obj1);

    ShallowDeep obj2 {obj1};
    obj2.set_data_value(1000);




    return 0;
}