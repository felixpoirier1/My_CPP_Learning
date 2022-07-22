#include <ios>
#include <iostream>
#include <iomanip>
#include <vector>

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
    std::cout << std::endl;

    //FLOATING POINT NUMBER
    double num1 {123456789.987654321};
    double num2 {1234.5678};
    double num3 {1234.0};

    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    
    //will display 8 numbers if possible
    std::cout << std::setprecision(8);
    //will ensure that there are 8 numbers (will add zero if len < precision)
    std::cout << std::fixed;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    std::cout << std::endl;

    std::cout.setf(std::ios::scientific);
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    std::cout <<  std::resetiosflags(std::ios::scientific);

    std::vector<std::vector<int>> matrix {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::cout << std::setw(8)<< "" << std::setw(7)<< std::left << "NOKIA" << std::endl;
    std::cout << std::setfill('-');
    std::cout << std::setw(20) << " "<< std::endl;
    std::cout << std::setfill(' ');
    for (size_t i = 0 ; i<5; i++){
        std::cout << "|" << std::setw(20) << std::right << "|" << std::endl;
    }
    std::cout << " ";
    std::cout << std::setfill('-');
    std::cout << std::setw(20) << " " << std::endl;
    std::cout << std::setfill(' ') <<;
    for (auto vec: matrix){
        for (auto val: vec){
            std::cout << std::setw(10) << std::left << val;
        }
        std::cout << std::endl;
    }

    return 0;
}