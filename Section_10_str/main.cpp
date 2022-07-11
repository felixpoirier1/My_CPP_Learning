#include <iostream>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>



void foo(){
    
    std::string pyramid;
    std::cout <<"Enter your string : ";
    std::cin >>pyramid;
    
    std::string end_ = " ";
    
    for(int line{1}; line <= pyramid.length(); line++){
        
        if (line > 1){
            end_ = pyramid.substr(0, line - 1);
            reverse(end_.begin(), end_.end());
        }
        
        for(int space = pyramid.length(); space > line; space--)
            std::cout << " " ;
        
        std::cout<<pyramid.substr(0, line) + end_<<std::endl;
    }
}

int main()
{
    char first_name[20] {};
    char last_name[20] {};
    char full_name[50] {};
    char temp[50] {};
    
/*    std::cout << "Enter your first name : ";
    std::cin >> first_name;
    std::cout << "Enter your last name : ";
    std::cin >> last_name;
    
    std::cout << "------------------" << std::endl;
    
    std::cout << "Hi " << first_name << ", your first name contains " << strlen(first_name) << " letters." << std::endl;
    std::cout << "Hi " << last_name << ", your last name contains " << strlen(last_name) << " letters." << std::endl;
    
    strcpy(full_name, first_name);
    strcat(full_name, " ");
    strcat(full_name, last_name);*/
    
    std::cout << "What is your full name? : ";
    std::cin.getline(full_name, 50);
    
    std::cout << "Your full name is " << full_name << std::endl;
    
    //C++ strings never have garbage
    std::string name {"Félix"};
    
    //copies name from 0 to 3 steps ahead
    std::string name_half {name, 0, 3};
    
    
    //substr starts at 0 then prints 3 next chars
    std::cout << name.substr(0, 3) << std::endl;
    
    //find finds wherever specific string starts (and starts from 0) (if doesnt find returns string::npos)
    std::cout << name.find("ix", 2) << std::endl;
    
    // inserts at position 3 string " "
    std::cout << name.insert(3, " ") << std::endl;
    
    // erase at position 3 with 2 steps
    std::cout << name.erase(3, 2) << std::endl;
    // getline(cin, string); // makes sure we capture entire inputs that contain whitespace and stores it all in "string"
 
    foo();
    
    
    return 0;
}

