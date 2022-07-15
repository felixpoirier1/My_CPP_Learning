#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <cstring>
#include <iostream>

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);
private:
    char *str;
public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    Mystring(Mystring &&source);
    ~Mystring();

    Mystring &operator=(const Mystring &source);
    Mystring &operator=(Mystring &&source);
    Mystring operator-()const;
    bool operator==(const Mystring &rhs) const;
    bool operator!=(const Mystring &rhs) const;
    bool operator>(const Mystring &rhs) const;
    bool operator<(const Mystring &rhs) const;
    Mystring operator+(const Mystring &rhs) const;
    Mystring &operator+=(const Mystring &rhs);
    Mystring operator*(int num) const;
    Mystring &operator*=(int num);
    Mystring &operator++();                                     
    Mystring operator++(int); 

};





#endif 