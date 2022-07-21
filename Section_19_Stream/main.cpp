#include <ios>
#include <iostream>
#include <iomanip>

int main(){
    //BOOLEAN TYPES
    std::cout << "No Boolalpha: " << (10==10) <<std::endl;
    //returns true or false instead of 1 or 0
    std::cout << std::boolalpha;

    std::cout << "Boolalpha: " << (10==10) <<std::endl;

    //returns 1 or 0 instead of true or false
    std::cout << std::noboolalpha;

    std::cout << "No Boolalpha: " << (10==10) <<std::endl;

    //flag
    std::cout.setf(std::ios::boolalpha);
    std::cout << "Boolalpha: " << (10==10) <<std::endl;

    //reset flag (iomanip)
    std::cout << std::resetiosflags(std::ios::boolalpha);
    std::cout << "Boolalpha: " << (10==10) <<std::endl;
    std::cout << std::endl;

    //INTEGER TYPES
    int num {255};
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;
    std::cout << std::endl;

    std::cout << std::showbase;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;
    std::cout << std::endl;

    std::cout << std::showpos;
    std::cout << std::dec << num << std::endl;

    //flags
    std::cout.setf(std::ios::showbase);
    std::cout.setf(std::ios::uppercase);
    std::cout.setf(std::ios::showpos);

    //resetting to default
    std::cout << std::resetiosflags(std::ios::basefield);
    std::cout << std::resetiosflags(std::ios::showbase);
    std::cout << std::resetiosflags(std::ios::uppercase);
    std::cout << std::resetiosflags(std::ios::showpos);

    //FLOATING POINT NUMBER
    
    

    return 0;
}