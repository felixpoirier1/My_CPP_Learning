#include <iostream>
#include <string>

double calculate_mpg(int miles, int gallons){
    if (gallons==0)
        throw 0;
    if (gallons < 0 || miles <0)
        throw std::string {"Sorry miles or gallons cannot be smaller than 0"};
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
    } catch (int &ex) {
        std::cerr << "Sorry function can't divide by zero" << std::endl;
    } catch (std::string &ex){
        std::cerr << ex << std::endl;
    }
    std::cout << "bye" << std::endl;

    return 0;
}