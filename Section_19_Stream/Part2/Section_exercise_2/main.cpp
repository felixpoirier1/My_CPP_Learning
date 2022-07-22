#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

int main(){

    std::ifstream in_file;
    std::string word {};
    int count {0};
    int found {0};
    std::string search {};

    in_file.open("romeoandjuliet");

    if(!in_file){
        std::cerr << "Can't open file" << std::endl;
        return 1;
    }
    std::cout << "What word do you want to search ? ";

    std::cin >> search;
    //std::transform(search.begin(), search.end(), search.begin(), ::tolower);

    while(!in_file.eof()){
        in_file >> word;
        //std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        if(word.find(search) != std::string::npos){
            ++found;
        }
        ++count;

    }
    in_file.close();

    std::cout << count << " words where searched..." << std::endl;
    std::cout << "The substring " << search << " was found " << found << " times" << std::endl;
    return 0;
}