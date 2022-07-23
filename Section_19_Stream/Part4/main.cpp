#include <iomanip>
#include <sstream>
#include <string>
#include <limits>
#include <iostream>
int main(){
    int num{};
    double total{};
    std::string name {};

    std::string info{"Moe 1000 1234.5"};
    std::istringstream iss {info};

    iss >> name >> num >> total;

    std::cout << std::setw(10) << std::left << name
        << std::setw(5) << num
        << std::setw(10) << total << std::endl;

    int value{};
    std::string entry{};
    bool done = false;

    do{
        std::cout << "Enter an integer: ";
        std::cin >> entry;
        std::istringstream ss {entry};

        if(ss >> value)
            done = true;

        else
            std::cout << "Sorry das ist nicht eine integer"<< std::endl;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (!done);

    std::cout << "You entered the integer: " << value << std::endl;

    return 0;
}