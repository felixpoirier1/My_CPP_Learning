#include "Movie.h"
#ifndef _MOVIES_H_
#define _MOVIES_H_

class Movies
{
private:
    std::vector<Movie> movies;
public:
    Movies();
    ~Movies();

    bool increment_watched(std::string name);
    bool add_movie(std::string name, std::string rating, int watched);
    void display();
};







#endif