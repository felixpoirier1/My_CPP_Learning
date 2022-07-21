#include <iostream>
#include <string>

class DivisionByZeroException{
public:
    std::string desc {"Cannot divide by zero"};
};

class NegativeValueException{
public:
    std::string desc {"Cannot have negative values"};
};

double calculate_mpg(int miles, int gallons){
    if (gallons==0)
        throw DivisionByZeroException();
    if (gallons < 0 || miles <0)
        throw NegativeValueException();
    return static_cast<double>(miles)/gallons;
}

int main(){

    int miles {};
    int gallons {};
    double miles_per_gallon {};

    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >>gallons;

    try{
        if (gallons == 0){
            throw 0;
        }
        miles_per_gallon = static_cast<double>(miles)/gallons;
        std::cout << "Result: " << miles_per_gallon << std::endl;
    } catch (int &ex) {
        std::cerr << "Sorry, can't divide by zero" << std::endl;
    }
    try {
        std::cout<< "Result using function: " << calculate_mpg(miles, gallons) << std::endl;
    } catch (const DivisionByZeroException &ex) {
        std::cerr << ex.desc << std::endl;
    } catch (const NegativeValueException &ex){
        std::cerr << ex.desc << std::endl;
    }
    std::cout << "bye" << std::endl;

    return 0;
}