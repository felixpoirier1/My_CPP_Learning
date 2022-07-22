#include <fstream>
#include <iostream>
#include <iomanip>

int return_score(std::string ans, std::string res){
    int score {};
    for (size_t i = 0 ; i<res.length(); i++){
        if (ans[i] == res[i]){
            score ++;
        }
    }
    return score;
}

int main(){

    std::ifstream in_file;
    std::string correct_answers {};
    std::string response {};
    std::string name {};

    in_file.open("responses.txt");

    if(!in_file){
        std::cerr << "Sorry can't read the file" << std::endl;
        return 1;
    }

    in_file >> correct_answers;
    
    std::cout << std::setw(10) << std::left << "Student"
        << std::setw(10) << std::right << "Score" << std::endl;
    
    std::cout << std::setfill('-') << std::setw(20) << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << "";

    while(in_file >> name >> response){
        std::cout << std::setw(10) << std::left << name;
        std::cout << std::setw(10) << std::right <<  return_score(correct_answers, response) << std::endl;

    }

    std::cout << std::setfill('-') << std::setw(20) << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << "";

    in_file.close();

    return 0;
}