#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <cstring>
#include <iostream>

class Mystring
{
private:
    char *str;
public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    Mystring(Mystring &&source);
    ~Mystring();

    friend Mystring operator+(const Mystring &obj);
    friend bool operator<(const Mystring &lhs, const Mystring &rhs);
    friend bool operator>(const Mystring &lhs, const Mystring &rhs);

    //stream operators
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

    //overload
    Mystring &operator=(const Mystring &rhs);       //copy assignment
    Mystring &operator=(Mystring &&rhs);            //move assignment
    Mystring operator-() const;                     //make lowercase
    Mystring operator+(const Mystring &rhs) const;  //concat
    bool operator==(const Mystring &rhs) const;     //compare



    void display() const;
    int get_length() const;
    const char *get_str() const;
};


#endif