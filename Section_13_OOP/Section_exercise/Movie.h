#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <iostream>
#include <vector>
#include <string>

class Movie
{
private:
    std::string name {};
    std::string rating {};
    int watched {};
public:
    Movie(std::string name_val, std::string rating_val, int watched_val);
    ~Movie();

    std::string get_name() const {return name; }
    std::string get_rating() const {return rating; }
    int get_watched() const {return watched; } 

    void display() const;

};







#endif