#include <fstream>
#include <iostream>
int main(){

    std::ifstream in_file {"input.txt"};
    std::ofstream out_file {"output.txt", std::ios::app};

    if(!in_file){
        std::cerr << "Error finding file" << std::endl;
        return 1;
    }
    if(!out_file){
        std::cerr << "Error creating file" << std::endl;
        return 1;
    }

    std::string line;
    while(std::getline(in_file, line))
        out_file << line << std::endl;

    out_file.close();
    in_file.close();

    return 0;
}