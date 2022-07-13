#include "Movie.h"

Movie::Movie(std::string name_val, std::string rating_val, int watched_val)
    : name{name_val}, rating{rating_val}, watched{watched_val}  {
        std::cout<<"The movie "<<name<<" was successfully created"<< std::endl;
}


void increment_watched(Movie &movie){
    ++movie.watched;
}