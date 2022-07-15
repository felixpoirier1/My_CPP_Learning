#include "Mystring.h"

//global function overloading
Mystring operator+(const Mystring &rhs){
    char *buff = new char[std::strlen(rhs.str)+1];
    std::strcpy(buff, rhs.str);
    for(size_t i=0; i<std::strlen(buff); i++){
        buff[i] = std::toupper(buff[i]);
    }

    Mystring temp{buff};
    delete [] buff;
    return temp;
}

bool operator<(const Mystring &lhs, const Mystring &rhs){
    bool is_smaller;
    is_smaller = std::strlen(lhs.str) < std::strlen(rhs.str);

    return is_smaller;
}

bool operator>(const Mystring &lhs, const Mystring &rhs){
    return !(lhs < rhs);
}

int main(){
    Mystring empty;
    Mystring larry{"Larry"};
    Mystring stooge{larry};

    empty = larry;

    Mystring josh{"Josh"};

    josh = Mystring{"Joshua"};

    empty.display();
    larry.display();
    stooge.display();
    josh.display();

    Mystring larry_l{-larry};
    Mystring larryjosh{larry+" "+josh};

    std::cout << std::boolalpha;

    std::cout << (larry == stooge) << std::endl;
    std::cout << larry_l.get_str() << std::endl;
    std::cout << larryjosh.get_str() << std::endl;
    
    std::cout << (+larryjosh).get_str() << std::endl;

    std::cout << (larry < josh) << std::endl;
    std::cout << (larry > josh) << std::endl;


    return 0;
}