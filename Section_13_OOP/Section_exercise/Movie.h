#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <string>
#include <iostream>

class Movie{
    //attributes
    std::string name {};
    std::string rating {};
    int watched {};

    friend void increment_watched(Movie &movie);
    public:
    //constructors
    Movie(std::string name, std::string rating, int watched);
    Movie(const Movie &source);

    std::string get_name(){return name; }
    std::string get_rating(){return rating; }
    int get_watched(){return watched; }

};


#endif