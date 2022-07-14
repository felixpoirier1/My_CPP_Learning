#ifndef _MOVIES_H_
#define _MOVIES_H_
#include "Movie.h"
#include <iostream>
#include <vector>
#include <string>

class Movies
{
private:
    std::vector<Movie> *movies;
public:
    Movies();                           //Constructor
    Movies(const Movies &source);       //Copy constructor
    Movies(Movies &&source) noexcept;   //Move constructor
    ~Movies();                          //Deconstructor

    bool add_movie(std::string name, std::string rating, int watched);
    bool increment_watched(std::string name);
    void display();
};




#endif