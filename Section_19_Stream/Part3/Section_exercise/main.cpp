#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
int main(){

    std::ifstream in_file {"romeoandjuliet.txt"};
    std::ofstream out_file {"romeoandjuliet_out.txt", std::ios::trunc};

    if(!in_file){
        std::cout << "File could not be opened" << std::endl;
        return 1;
    }
    if(!in_file){
        std::cout << "File could not be created" << std::endl;
        return 1;
    }

    std::string line;
    int count {1};

    while(std::getline(in_file,line)){
        if(line == "" || line == "\r"){
            out_file << std::endl;
            
        } else {
            out_file << std::setw(10) << std::left << count << line << std::endl;
            count++;
        }

    }

    in_file.close();
    out_file.close();




    return 0;
}