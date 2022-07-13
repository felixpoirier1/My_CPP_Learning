#include "Movie.h"
#include "Movies.h"
#include <iostream>

int main(){

    Movie cinderella {"Cinderella", "PG", 0};
    
    Movies my_movies;

    Movie fight_club {"Fight Club", "PG-13", 5};
    
    my_movies.add_movie(cinderella);
    my_movies.add_movie(fight_club);

    increment_watched(cinderella);

    std::cout <<"Cinderella"<< cinderella.get_watched();

    my_movies.display();

    return 0;
}