#ifndef _MOVIES_H_
#define _MOVIES_H_
#include "Movie.h"

class Movies
{
private:
    std::vector<Movie> *movies;
public:
    Movies();                       //Constructor
    Movies(const Movies &source);   //Copy constructor
    Movies(Movies &&m);    //Move constructor
    ~Movies();                      //Destructor

    bool increment_watched(std::string name);
    bool add_movie(std::string name, std::string rating, int watched);
    void display();
};







#endif