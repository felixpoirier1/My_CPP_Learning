#ifndef _MOVIES_H_
#define _MOVIES_H_
#include <vector>
#include "Movie.h"
class Movies
{
private:
    std::vector<Movie> library;

public:
    Movies();
    ~Movies();

    void add_movie(Movie movie);

    void display();


};



#endif