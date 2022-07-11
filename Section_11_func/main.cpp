#include <iostream>
#include <string>
#include <vector>
//math library https://en.cppreference.com/w/cpp/header/cmath
#include <cmath>
//C standard library (used to output random numbers) https://en.cppreference.com/w/cpp/header/cstdlib
#include <cstdlib>
//time library https://en.cppreference.com/w/cpp/header/ctime
#include <ctime>

//forward declaration FUNCTION PROTOTYPES (function at end of document)
void print(std::string argument);
//you can use the same name for two different functions
// they will need different types as arguments, the compiler will understand

// the "&" symbol tells the compiler to treat num as the actual parameter within memory
// essentially when we change num we change the actual parameter
void swap(int &a, int &b);

// this function will save space because "&" but won't compromise 
// its contents because of "const"
void print_vector(const std::vector<int> &vec);

// this is a global variable
std::string glob_var {"Global variable"};

// factorial numbers may output large numbers (RECURSION)
unsigned long long factorial(unsigned long long n);
int main(){
    //cmath library
    double num {};

    std::cout <<"Enter a double : " ;
    std::cin >> num;

    std::cout << "The sqrt of " << num << " is " <<sqrt(num) <<std::endl;

    std::cout <<num << " to the power of 4 is " <<pow(num, 4) <<std::endl;

    std::cout <<"The sin of "<<num <<" is "<<sin(num)<<std::endl;

    //cstdlib library
    int random_number{};
    size_t count {10};
    int min{1};
    int max{6};

    //the rand function returns a number between 0 and RAND_MAX
    std::cout <<"RAND_MAX on my system is: "<< RAND_MAX <<std::endl;
    //this seeds the random number generator (makes sure we dont have the same random numbers every run)
    srand(time(nullptr));
    
    for(size_t i{1}; i<=count; ++i){
        random_number = rand()%max + min; //this will return a random number between the bounds min to max inclusive
        std::cout << random_number << std::endl;
    }

    //usage of my personal function through forward declaration
    print("Hello world");

    swap(min, max); //(max = 1 ; min = 6)

    swap(min, max); //(max = 6 ; min = 1)

    std::vector<int> value {3, 5, 6, 7, 5, 6};
    print_vector(value);

    //variables declared within blocks "{}" die at the end of block
    int value_block{6};
    {
        //notice value_block was also declared previously
        int value_block{7};
        std::cout << "Within block : " << value_block << std::endl; //will output 7
    
    }

    std::cout << "Outside block : " << value_block<< std::endl; //will output 6

    //global variable initialized before main()
    std::cout << glob_var << std::endl;
    
    std::cout << factorial(16) << std::endl;

    return 0;
}

///////////////////

void print(std::string argument){
    std::cout <<argument<<std::endl;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void print_vector(const std::vector<int> &vec){
    for(auto num: vec){
        std::cout << num << std::endl;
    }


}

unsigned long long factorial(unsigned long long n){
    if (n==0)
        return 1;
    
    return n*factorial(n-1);
}
