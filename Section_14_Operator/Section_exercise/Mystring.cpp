#include "Mystring.h"

//no args constr
Mystring::Mystring()
    :str{nullptr}
{
    str = new char[1];
    *str = '\0';

}

//args constr
Mystring::Mystring(const char *s)
    :str{nullptr}
{
    if(s==nullptr){
        str = new char[1];
        *str = '\0';

    } else {
        str = new char[std::strlen(s)+1];
        std::strcpy(str, s);
    }
}

//copy constr
Mystring::Mystring(const Mystring &source){
    str = new char[std::strlen(source.str)+1];
    std::strcpy(str, source.str);
}

//move constr
Mystring::Mystring(Mystring &&source)
    :str{source.str}
{
    source.str = nullptr;
}

//destr
Mystring::~Mystring()
{
    delete [] str;
}

//copy assignemnt
Mystring &Mystring::operator=(const Mystring &source){
    if(this == &source){
        return *this;
    }
    else{
        delete this->str;
        str = new char[std::strlen(source.str)+1];
        std::strcpy(str, source.str);
        return *this;
    }
}

//move assignment
Mystring &Mystring::operator=(Mystring &&source){
    if(this == &source){
        return *this;
    }
    else{
        delete this->str;
        str = source.str;
        source.str = nullptr;
        return *this;
    }
}

Mystring Mystring::operator-()const{
    char *buff = new char[std::strlen(str)+1];
    std::strcpy(buff, str);
    for(size_t i=0; i<std::strlen(buff); i++){
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp{buff};
    delete [] buff;

    return temp;
}

bool Mystring::operator==(const Mystring &rhs) const{
    return (std::strcmp(str, rhs.str)==0);
}
bool Mystring::operator!=(const Mystring &rhs) const{
    return !(str == rhs.str);
}

bool Mystring::operator>(const Mystring &rhs) const{
    return (str > rhs.str);
}
bool Mystring::operator<(const Mystring &rhs) const{
    return (str < rhs.str);
}
Mystring Mystring::operator+(const Mystring &rhs) const{
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) +1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);

    Mystring temp{buff};
    delete [] buff;
    return temp;
}

Mystring &Mystring::operator+=(const Mystring &rhs){
    *this = *this + rhs;
    return *this;
}
Mystring Mystring::operator*(int num) const{
    Mystring temp;
    for(size_t i=0; i<num; i++){
        temp = temp + *this;
    }

    return temp;
}
Mystring &Mystring::operator*=(int num){
    *this = *this * num;
    return *this;
}
Mystring &Mystring::operator++(){
    for(size_t i=0; i<std::strlen(str); i++){
        str[i] = std::toupper(str[i]);
    }
    return *this;
}                           
Mystring Mystring::operator++(int){
    Mystring temp (*this);
    operator++();
    return temp;
}