#include "Movies.h"
#include <iostream>

Movies::Movies(/* args */)
{
}

Movies::~Movies()
{
}

void Movies::add_movie(Movie movie){
    library.push_back(movie);
}

void Movies::display(){
    for(Movie movie: library){
        std::cout << movie.get_name() << "\t" 
        << movie.get_rating() << "\t" 
        << movie.get_watched()<<std::endl;
    }
}