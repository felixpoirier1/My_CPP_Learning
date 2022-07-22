#include <fstream>
#include <iostream>
#include <iomanip>

int main(){
    std::ifstream in_file;
    std::string line;
    int num{};
    double total{};

    in_file.open("test.txt");
    if(!in_file){
        std::cerr << "Cannot open file" << std::endl;
        return 1;
    }
    while (in_file >> line >> num >> total){
        std::cout << std::setw(10) << std::left << line
            << std::setw(10) << num
            << std::setw(10) << total
            <<std::endl;  
    }
    in_file.close();

    //POEM
    std::cout << std::endl;

    std::ifstream in_poem;

    in_poem.open("poem.txt");

    if(!in_poem){
        std::cerr << "Cannot open file" << std::endl;
        return 1;
    }
    std::string line_poem;

    while(std::getline(in_poem, line_poem))
        std::cout << line_poem << std::endl;

    in_poem.close();
    return 0;

}